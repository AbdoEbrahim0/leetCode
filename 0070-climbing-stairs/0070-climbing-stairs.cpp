
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
//. Recursion with Memoization (Top-Down DP)
class Solution {
private :
int myClimb(int n,vector<int> &dp)
{
    if (n<=2)   
        return n;
    if(dp[n]!=-1) 
    return dp[n];
return dp[n]=myClimb(n-1,dp) +myClimb(n-2,dp);
}
public:
int climbStairs(int n)
    {
    vector<int>dp(n+1,-1);
        return  myClimb(n,dp);
    }
};