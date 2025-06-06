// class Solution {
// public:
//     int climbStairs(int n) {
//         if (n == 1) return 1;
//         if (n == 2) return 2;
//         return climbStairs(n - 1) + climbStairs(n - 2);
//     }
// };
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return climb(n, dp);
    }

private:
    int climb(int n, vector<int>& dp) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (dp[n] != -1) return dp[n];
        return dp[n] = climb(n - 1, dp) + climb(n - 2, dp);
    }
};
