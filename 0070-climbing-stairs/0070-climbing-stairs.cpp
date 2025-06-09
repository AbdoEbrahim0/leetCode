
// class Solution {
// public:
//     int climbStairs(int n) {
//         vector<int> dp(n + 1, -1);
//         return climb(n, dp);
//     }

// private:
//     int climb(int n, vector<int>& dp) {
//         if (n == 1) return 1;
//         if (n == 2) return 2;
//         if (dp[n] != -1) return dp[n];
//         return dp[n] = climb(n - 1, dp) + climb(n - 2, dp);
//     }
// };

/*
n=4
2+2
1+1+1+1
2+1+1
1+1+2

*/
//puer recursion (brute force) as comp 2^n and give TLE when n>30  1,073,741,824
// class Solution {
// private :
// int x=0;
// public:
// int dp[45];
//     int climbStairs(int n) {
            
//             if (n<=2)
//             return n;
//             return climbStairs (n-1) + climbStairs(n-2);
//     }
// };
            // if(dp[n])
            // return dp[n];
            // if(dp[n])
            // return dp[n];
// comp: O(N). Recursion with Memoization (Top-Down DP) with care to & operator to avoid MLE
// class Solution {
// private :
// int myClimb(int n,vector<int> &dp)
// {
//     if (n<=2)   
//         return n;
//     if(dp[n]!=-1) 
//     return dp[n];
// return dp[n]=myClimb(n-1,dp) +myClimb(n-2,dp);
// }
// public:
// int climbStairs(int n)
//     {
//     vector<int>dp(n+1,-1);
//         return  myClimb(n,dp);
//     }
// };
// comp: O(N) Tabulation (Bottom-Up DP)
// class Solution {

// public:

// int climbStairs(int n) {

//     if (n <= 2) return n;
// vector<int> dp(n + 1);    
//     dp[1] = 1;
//     dp[2] = 2;
//     for (int i = 3; i <= n; ++i) {
//         dp[i] = dp[i - 1] + dp[i - 2];
//     }
//     return dp[n];
// }
// };
// Best performance as Comp : O(N) space : O(1)

class Solution {

public:
int climbStairs(int n) {
    if (n <= 2) return n;
    int a = 1, b = 2;
    for (int i = 3; i <= n; ++i) {
        int temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}
};

