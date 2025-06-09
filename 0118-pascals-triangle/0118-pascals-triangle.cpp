
// //naive
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
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;

        for (int i = 0; i < numRows; ++i) {
            vector<int> row(i + 1, 1); // all elements = 1

            for (int j = 1; j < i; ++j) {
                row[j] = res[i - 1][j - 1] + res[i - 1][j]; // sum from previous row
            }

            res.push_back(row);
        }

        return res;
    }
};
