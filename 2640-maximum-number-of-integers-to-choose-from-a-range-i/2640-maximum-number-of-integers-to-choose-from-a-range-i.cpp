// class Solution {
// public:
//     int maxCount(vector<int>& banned, int n, int maxSum) {
//         int bannedSize = banned.size();
//         int counter = 0;
//         sort(banned.begin(), banned.end());
//         for (int j = 1; j < n; j++) //n
//         {
//                 int start = 0, end = bannedSize-1, mid, cur = -1; // 1 2 3 4 5 6 n
//                 while (start <= end) // log(baneedSize)
//                 {
//                     mid = (start + end) / 2;
//                     if (j == banned[mid])
//                     {
//                         cur = mid;
//                         break;
//                     }
//                     else if (  j >banned[ mid]) {
//                         start = mid + 1;
//                     }
//                     else 
//                         end = mid - 1;
//                 }
//                 if (cur == -1 && (maxSum - j) >= 0)
//                 {
//                     counter++;
//                     maxSum -= j; //maxSum -[2+3 
//                 }              
//         }
//         return counter;
//     }
// };

// total comp: O(m log m) + O(n log m) /and MEM comp for sorting : log m
// class Solution {
// public:
//     int maxCount(vector<int>& banned, int n, int maxSum) {
//         int bannedSize = banned.size();
//         int counter = 0;
//         sort(banned.begin(), banned.end()); //O(m log m)
//         for (int j = 1; j <= n; j++) //o(n)
//         {
//             if (!(binary_search(banned.begin(),banned.end() ,j))) //O (log m)
//             {
//                 if (maxSum - j >= 0)
//                 {
//                     counter++;
//                     maxSum -= j; //maxSum -[2+3 
//                 }
//             }
//         }
//         return counter;
//     }
// };

// total comp: O(m) + O(n) /and MEM comp for unordered_set : m
// class Solution {
// public:
//     int maxCount(vector<int>& banned, int n, int maxSum) {
//         int bannedSize = banned.size();
//         int counter = 0;
//         unordered_set<int> un_set(banned.begin(), banned.end());
//         for (int j = 1; j <= n; j++) //O(n)
//         {
//             if (! un_set.count(j))//O(1)
//             {
//                 if (maxSum - j >= 0)
//                 {
//                     counter++;
//                     maxSum -= j; //maxSum -[2+3 
//                 }
//             }
//         }
//         return counter;
//     }
// };
// total comp: O(m+n) and MEM comp for bitset : O(1)
// class Solution {
// public:
//     int maxCount(vector<int>& banned, int n, int maxSum) {
//         bitset<10001> vis;
//         int counter = 0;
//         for (auto it : banned)
//         {
//             vis[it] = 1;
//         }
//         for (int j = 1; j <= n; j++) //n
//         {
//             if (!vis [j])
//             {
//                 if (maxSum - j >= 0)
//                 {
//                     counter++;
//                     maxSum -= j; //maxSum -[2+3 
//                 }
//             }
//         }
//         return counter;
//     }
// };

//creack interview matb3a
class Solution {
 public:
     int maxCount(vector<int>& banned, int n, int maxSum) {
         //vector<bool>vis(10001); 
         bitset<10001>vis;
         for (int & val : banned)
         {
             vis[val] = 1;//to ignore
         }
         int sum = 0;
         short counter = 0;
         for (short i = 1; i <= n; i++)
         {
             if (vis[i] == 0)
             {
                 sum += i ;
                 if (sum > maxSum)// by logic all next is greater than currrent so if current plussed to sum and exceed MaxSum then all next values will not be taken also
                     break;
                 counter++;
             }
         }
         //if (sum > maxSum)
         //    return 0;
         return counter;
     }
    };
