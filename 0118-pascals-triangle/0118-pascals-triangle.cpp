
// //naive 2D Array time O(n^2) space  O(n^2)
// class Solution {
// public:
//     vector<vector<int>> generate(int numRows) {
//         vector<vector<int>> res;
//         vector<int> rowVToADD;
//         res.push_back({1});
//         for (int i = 1; i < numRows; i++)
//         {
//             rowVToADD.emplace_back(1);
//             for (int j = 0; j + 1 < i; j++)
//             {
//                 rowVToADD.emplace_back(res[i-1][j] + res[i-1][j + 1]);
//             }
//             rowVToADD.emplace_back(1);
//             res.emplace_back(rowVToADD);
//             rowVToADD.clear();
//         }
//         return res;
//     }
// };

// In-Place Row Construction [optimized] 1D array time O(n^2) space  O(n)
// class Solution {
// public:
//     vector<vector<int>> generate(int numRows) {
//         vector<vector<int>> res;
//         vector<int> row;
//         for (int i = 0; i < numRows; ++i) {
//             row.push_back(1); // always ends with 1
//             // update middle values from end to start
//             for (int j = i - 1; j > 0; --j) {
//                 row[j] = row[j] + row[j - 1];
//             }
//             res.push_back(row);
//         }
//         return res;
//     }
// };

//[delete clear fn]
//Time: O(n²), Space: O(n²)
// class Solution {
// public:
//     vector<vector<int>> generate(int numRows) {
//         vector<vector<int>> res;
        
//         res.push_back({1});
//         for (int i = 1; i < numRows; i++)
//         {
//             vector<int> rowVToADD;
//             rowVToADD.emplace_back(1);
//             for (int j = 0; j +1< i; j++)//as i push at index 0 {1} always
//             {
//                 rowVToADD.emplace_back(res[i-1][j] + res[i-1][j + 1]);
//             }
//             rowVToADD.emplace_back(1);
//             res.emplace_back(rowVToADD); 
//         }
//         return res;
//     }
// };

//Iterative DP (Classic, Row-by-Row
// class Solution {
// public:
//     vector<vector<int>> generate(int numRows) {
//         vector<vector<int>> res;
//         for (int i = 0; i < numRows; ++i) {
//             vector<int> row(i + 1, 1); // all elements = 1
//             for (int j = 1; j < i; ++j) {
//                 row[j] = res[i - 1][j - 1] + res[i - 1][j]; // sum from previous row
//             }
//             res.push_back(row);
//         }
//         return res;
//     }
// };

// Binomial Coefficient Formula (C(n, k))
//Use long long to avoid overflow in intermediate calculations (especially for large n).
// class Solution {
// public:
//     vector<vector<int>> generate(int numRows) {
//         vector<vector<int>> res;
//         for (int i = 0; i < numRows; ++i) {
//             vector<int> row;
//             long long val = 1;
//             for (int j = 0; j <= i; ++j) {
//                 row.push_back(val);
//                 //This allows building each row without using any of the previous rows
//                 val = val * (i - j) / (j + 1); // iterative form of C(i, j)
//             }
//             res.push_back(row);
//         }
//         return res;
//     }
// };
//
// recursion with no memoization O(N^2) give TLE
// class Solution {
// public:
//     int getValue(int row, int col) {
//         if (col == 0 || col == row) return 1;
//         return getValue(row - 1, col - 1) + getValue(row - 1, col);
//     }

//     vector<vector<int>> generate(int numRows) {
//         vector<vector<int>> res;

//         for (int i = 0; i < numRows; ++i) {
//             vector<int> row;
//             for (int j = 0; j <= i; ++j) {
//                 row.push_back(getValue(i, j));
//             }
//             res.push_back(row);
//         }

//         return res;
//     }
// };
// recursion with  memoization O(N^2) give TLE
class Solution {
public:
    int pascal(int row, int col, vector<vector<int>>& dp) {
        if (col == 0 || col == row) return 1;
        if (dp[row][col] != -1)
            return dp[row][col];

        return dp[row][col] = pascal(row - 1, col - 1, dp) + pascal(row - 1, col, dp);
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<vector<int>> dp(numRows, vector<int>(numRows, -1));  // memoization table

        for (int i = 0; i < numRows; ++i) {
            vector<int> row;
            for (int j = 0; j <= i; ++j) {
                row.push_back(pascal(i, j, dp));
            }
            res.push_back(row);
        }

        return res;
    }
};
