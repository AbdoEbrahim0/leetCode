// class Solution {
// public:
//     int countGoodStrings(int low, int high, int zero, int one) {
        
//     }
// };

// class Solution {
// public:
//     int countGoodStrings(int low, int high, int zero, int one) {
//         const int MOD = 1e9 + 7;
//         vector<int> dp(high + 1, 0);
//         dp[0] = 1; // Base case: one way to make empty string
        
//         for (int i = 1; i <= high; ++i) {
//             if (i >= zero) {
//                 dp[i] = (dp[i] + dp[i - zero]) % MOD;
//             }
//             if (i >= one) {
//                 dp[i] = (dp[i] + dp[i - one]) % MOD;
//             }
//         }
        
//         int result = 0;
//         for (int i = low; i <= high; ++i) {
//             result = (result + dp[i]) % MOD;
//         }
        
//         return result;
//     }
// };


#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// class Solution {
// public:
//     int countGoodStrings(int low, int high, int zero, int one) {
//         const int MOD = 1e9 + 7;
//         unordered_map<int, int> memo;
        
//         function<int(int)> dp = [&](int len) {
//             if (len == 0) return 1;
//             if (len < 0) return 0;
//             if (memo.count(len)) return memo[len];
            
//             int res = (dp(len - zero) + dp(len - one)) % MOD;
//             memo[len] = res;
//             return res;
//         };
        
//         int result = 0;
//         for (int i = low; i <= high; ++i) {
//             result = (result + dp(i)) % MOD;
//         }
        
//         return result;
//     }
// };

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int MOD = 1e9 + 7;
        vector<int> dp(high + 1, 0);
        dp[0] = 1; // Base case: one way to form an empty string
        
        for (int i = 1; i <= high; ++i) {
            if (i >= zero) {
                dp[i] = (dp[i] + dp[i - zero]) % MOD;
            }
            if (i >= one) {
                dp[i] = (dp[i] + dp[i - one]) % MOD;
            }
        }
        
        int result = 0;
        for (int i = low; i <= high; ++i) {
            result = (result + dp[i]) % MOD;
        }
        
        return result;
    }
};
// class Solution {
// public:
//     int countGoodStrings(int low, int high, int zero, int one) {

//     }
//     };