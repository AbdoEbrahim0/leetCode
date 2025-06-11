class Solution {
public:
    vector<int> getRow(int rowIndex) {
                    vector<int> row;
            long long val = 1;
            for (int j = 0; j <= rowIndex; ++j) {
                row.push_back(val);
                //This allows building each row without using any of the previous rows
                val = val * (rowIndex - j) / (j + 1); // iterative form of C(i, j)
            }
            
            return row;
    }
};

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