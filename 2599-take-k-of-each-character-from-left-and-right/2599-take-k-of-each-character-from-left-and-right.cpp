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

class Solution {
public:
    bool ok(int mid, string s, int k)
    {
        array <int, 3>arrR = { 0,0,0 };
        vector<array<int, 3>>vR;
        vR.emplace_back(array<int, 3> {0, 0, 0});
        for (int z = 0; z < mid; z++)
        {
            arrR[s[z] - 'a']++;
            vR.emplace_back(arrR);
        }
        if (vR[0][0] >= k && vR[0][1] >= k && vR[0][2] >= k)
                return true;

        array <int, 3>arrL = { 0,0,0 };
        vector<array<int, 3>>vL;
        int sizeString = s.size();
        vL.emplace_back(array<int, 3> {0, 0, 0}); //when no taking any substring 
        for (int z = s.size() - 1; z >= sizeString - mid ; z--)
        {
            arrL[s[z] - 'a']++;
            vL.emplace_back(arrL);
        }
        reverse(vL.begin(), vL.end());
        if (vL[0][0] >= k &&  vL[0][1] >= k && vL[0][2] >= k)
                return true;

        for (int i = 0; i < vL.size(); i++)
        {
            if (vR[i][0] + vL[i][0] >= k && vR[i][1] + vL[i][1] >= k && vR[i][2] + vL[i][2] >= k)
                return true;
        }
        return false;
    }
    int takeCharacters(string s, int k) {
        int n = s.size();
        int start = 0, end = n, cur = -1;
        int mid = 3 * k;
        //pre check if string is valid reduce run time to 1/2
        array<int, 3> total_counts = {0, 0, 0};
        for (char c : s) {
            total_counts[c - 'a']++;
        }
        if (total_counts[0] < k || total_counts[1] < k || total_counts[2] < k) {
            return -1;
        }
        while (start <= end)
        {
            mid = (start + end) >> 1; // divide on 2
            //mid = 10;
            if (ok(mid, s, k)) //try to minimize
            {
                cur = mid;
                end= mid - 1;
            }
            else
                start = mid + 1;
        }
        return cur;
    }
};


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