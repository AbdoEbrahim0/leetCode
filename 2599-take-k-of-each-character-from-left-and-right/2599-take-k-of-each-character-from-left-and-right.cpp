// class Solution {
// public:
//     bool ok(int mid, string s, int k)
//     {
//         array <int, 3>arrR = { 0,0,0 };
//         vector<array<int, 3>>vR;

//         array <int, 3>arrL = { 0,0,0 };
//         vector<array<int, 3>>vL;

//         int sizeString = s.size();
//         vL.emplace_back(array<int, 3> {0, 0, 0}); //when no taking any substring 
//         for (int z = s.size() - 1; z >= sizeString - mid ; z--)
//         {
//             arrL[s[z] - 'a']++;
//             vL.emplace_back(arrL);
//         }
//         reverse(vL.begin(), vL.end());
        
//         vR.emplace_back(array<int, 3> {0, 0, 0});
//         for (int z = 0; z < mid; z++)
//         {
//             arrR[s[z] - 'a']++;
//             vR.emplace_back(arrR);
//         }
        
//         for (int i = 0; i < vL.size(); i++)
//         {
//             if (vR[i][0] + vL[i][0] >= k && vR[i][1] + vL[i][1] >= k && vR[i][2] + vL[i][2] >= k)
//                 return true;
//         }
//         return false;
//     }
//     int takeCharacters(string s, int k) {
//         int n = s.size();
//         int start = 0, end = n, cur = -1;
//         int mid = 3 * k;

//         while (start <= end)
//         {
//             mid = (start + end) >> 1; // divide on 2
//             //mid = 10;
//             if (ok(mid, s, k)) //try to minimize
//             {
//                 cur = mid;
//                 end= mid - 1;
//             }
//             else
//                 start = mid + 1;
//         }
//         return cur;
//     }
// };
// [optimized][improve DataSturcture] 
// class Solution {
// public:
//     bool ok(int mid, string &s, int k)
//     {
//         array <int, 3>arrR = { 0,0,0 };
//         for (int z = 0; z < mid; z++)
//             arrR[s[z] - 'a']++;

//         if (arrR[0] >= k && arrR[1] >= k && arrR[2] >= k)
//                 return true;
//         array <int, 3>arrL = { 0,0,0 };
//         int sizeString = s.size();
//         for (int z = s.size() - 1; z >= sizeString - mid; z--)
//             arrL[s[z] - 'a']++;

//         if (arrL[0] >= k && arrL[1] >= k && arrL[2] >= k)
//                 return true;
//         // Now, check combinations of left + right
//         // Sliding window: take `i` from left and `mid - i` from right
//         array<int, 3> total = arrR;  // Start with all left
//         for (int i = mid - 1; i >= 0; i--) {
//             // Remove s[i] from left, add s[n - (mid - i)] from right
//             total[s[i] - 'a']--;
//             total[s[s.size() - (mid - i)] - 'a']++;
//             if (total[0] >= k && total[1] >= k && total[2] >= k) {
//                 return true;
//             }
//         }
//         return false;
//     }

//     int takeCharacters(string &s, int k) {
//         int n = s.size();
//         int start = 0, end = n, cur = -1;
//         int mid ;
//         //pre check if string is valid reduce run time to 1/2
//         array<int, 3> total_counts = {0, 0, 0};
//         for (char c : s) {
//             total_counts[c - 'a']++;
//         }
//         if (total_counts[0] < k || total_counts[1] < k || total_counts[2] < k) {
//             return -1;
//         }
//         while (start <= end)
//         {
//             mid = (start + end) >> 1; // divide on 2
//             //mid = 10;
//             if (ok(mid, s, k)) //try to minimize
//             {
//                 cur = mid;
//                 end= mid - 1;
//             }
//             else
//                 start = mid + 1;
//         }
//         return cur;
//     }
// };
//forward stratgy 
// class Solution {
// public:
//     int vis[3][100005];// 3 as row=0 > a row=1 >  b row=2 >  c 

//     bool ok(int mid,  int k,int n)
//     {
//         for (int i = 0; i <= mid; i++)
//         {
//             //left a +right a >=K 
//             int a = vis[0][i] + (vis[0][n] - vis[0][n - mid + i]);
//             int b = vis[1][i] + (vis[1][n] - vis[1][n - mid + i]);
//             int c = vis[2][i] + (vis[2][n] - vis[2][n - mid + i]);

//             if (a >= k && b >= k && c >= k)
//                 return true;
//         }
        
//         return false;
//     }
//     int takeCharacters(string s, int k) {
//         if(k==0) //testCase s="cc" k=0 output =0
//         return 0;
//         for (int i = 0; i < s.size(); i++)
//         {
//             vis[s[i] - 'a'][i+1]++; //plussed 1 as i need 0 as i dont take from left at all
//         }
//         //apply concept prefix sum  
//         for (int i = 0; i < 3; i++)
//         {
//             //we start from j=1 as index cant be negative
//             for (int j = 1; j <= s.size(); j++)
//             {
//                 vis[i][j] +=   vis[i][j - 1] ;
//             }
//         }

// /*
// //aabaaaacaabc
// a:122345667888
// b:001111111122
// c:000000011112
// */

//         int n = s.size();
//         int start = 0, end = n, cur = -1;
//         int mid ;
//         //pre check if string is valid reduce run time to 1/2
//         array<int, 3> total_counts = { 0, 0, 0 };
//         for (char c : s) {
//             total_counts[c - 'a']++;
//         }
//         if (total_counts[0] < k || total_counts[1] < k || total_counts[2] < k) {
//             return -1;
//         }

//         while (start <= end)
//         {
//             mid = (start + end) /2; // >>1 divide on 2
//             //mid = 10;
//             if (ok(mid, k,n)) //try to minimize
//             {
//                 cur = mid;
//                 end = mid - 1;
//             }
//             else
//                 start = mid + 1;
//         }
//         return cur;
//     }
// };
//backward stratgy
class Solution {
    public:
        int takeCharacters(string s, int k) {
            vector<int> vis(3);
            for (char c : s)
                vis[c - 'a']++;
            //if num of a or b or c <k string is not valid ret -1
            if (*min_element(vis.begin(), vis.end()) <k)
                return -1;
            
            int l = 0, r = 0, ans=0;
            while (true)
            {
                vis[s[r] - 'a']--;
                // because string is valid from begingi as itt ddidnt return -1 at 1st
                //we will take char by char from right until string became not valid
                //then while will turn on and take char by char from left
                //to make string valid again
                while (*min_element(vis.begin(), vis.end()) < k)
                {
                vis[s[l] - 'a']++;
                l++;
                }
                ans = max(ans, r - l + 1);
                r++;
                if(r>=s.size()) break;
            }
            return s.size() - ans;
        }
    };
//[optimized gpt]
// class Solution {
// public:
//     bool ok(int mid, const string &s, int k) {
//         array<int, 3> left_counts = {0, 0, 0};
//         array<int, 3> right_counts = {0, 0, 0};
        
//         // Compute frequencies for the first `mid` chars (left window)
//         for (int i = 0; i < mid; i++) {
//             left_counts[s[i] - 'a']++;
//         }
        
//         // Check if taking all from left is enough
//         if (left_counts[0] >= k && left_counts[1] >= k && left_counts[2] >= k) {
//             return true;
//         }
        
//         // Compute frequencies for the last `mid` chars (right window)
//         for (int i = s.size() - 1; i >= (int)s.size() - mid; i--) {
//             right_counts[s[i] - 'a']++;
//         }
        
//         // Check if taking all from right is enough
//         if (right_counts[0] >= k && right_counts[1] >= k && right_counts[2] >= k) {
//             return true;
//         }
        
//         // Now, check combinations of left + right
//         // Sliding window: take `i` from left and `mid - i` from right
//         array<int, 3> total = left_counts;  // Start with all left
//         for (int i = mid - 1; i >= 0; i--) {
//             // Remove s[i] from left, add s[n - (mid - i)] from right
//             total[s[i] - 'a']--;
//             total[s[s.size() - (mid - i)] - 'a']++;
            
//             if (total[0] >= k && total[1] >= k && total[2] >= k) {
//                 return true;
//             }
//         }
        
//         return false;
//     }

//     int takeCharacters(string s, int k) {
//         if (k == 0) return 0;  // Edge case
        
//         int n = s.size();
//         int start = 0, end = n, result = -1;
        
//         // Pre-check if the entire string has enough 'a', 'b', 'c'
//         array<int, 3> total_counts = {0, 0, 0};
//         for (char c : s) {
//             total_counts[c - 'a']++;
//         }
//         if (total_counts[0] < k || total_counts[1] < k || total_counts[2] < k) {
//             return -1;
//         }
        
//         // Binary search the minimal `mid`
//         while (start <= end) {
//             int mid = (start + end) / 2;
//             if (ok(mid, s, k)) {
//                 result = mid;
//                 end = mid - 1;  // Try to minimize
//             } else {
//                 start = mid + 1;
//             }
//         }
//         return result;
//     }
// };
//[optimized deepseek]
// class Solution {
// public:
//     int takeCharacters(string s, int k) {
//         if (k == 0) return 0;
        
//         array<int, 3> total = {0, 0, 0};
//         for (char c : s) {
//             total[c - 'a']++;
//         }
        
//         if (total[0] < k || total[1] < k || total[2] < k) {
//             return -1;
//         }
        
//         int max_window = 0;
//         array<int, 3> window_counts = {0, 0, 0};
//         int left = 0;
        
//         for (int right = 0; right < s.size(); right++) {
//             char c = s[right];
//             window_counts[c - 'a']++;
            
//             while (window_counts[c - 'a'] > total[c - 'a'] - k) {
//                 window_counts[s[left] - 'a']--;
//                 left++;
//             }
            
//             max_window = max(max_window, right - left + 1);
//         }
        
//         return s.size() - max_window;
//     }
// };