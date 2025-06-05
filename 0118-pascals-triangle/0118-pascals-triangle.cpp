
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
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        
        res.push_back({1});
        for (int i = 1; i < numRows; i++)
        {
            vector<int> rowVToADD;
            rowVToADD.emplace_back(1);
            for (int j = 0; j + 1 < i; j++)
            {
                rowVToADD.emplace_back(res[i-1][j] + res[i-1][j + 1]);
            }
            rowVToADD.emplace_back(1);
            res.emplace_back(rowVToADD);
            
        }
        return res;
    }
};