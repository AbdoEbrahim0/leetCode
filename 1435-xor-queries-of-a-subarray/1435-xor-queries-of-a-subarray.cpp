//next sol. give me Time Limit Exceed
// 
// class Solution {
// public:
//     vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
//         int n = arr.size();
//         vector<int> prefixXor(n + 1, 0); // prefixXor[0] = 0

//         // Build prefix XOR
//         for (int i = 0; i < n; i++) {
//             prefixXor[i + 1] = prefixXor[i] ^ arr[i];
//         }

//         vector<int> result;
//         for (auto& q : queries) {
//             int L = q[0], R = q[1];
//             result.push_back(prefixXor[R + 1] ^ prefixXor[L]);
//         }

//         return result;
//     }
// };

// class Solution {
// public:
//     vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
//         int n = arr.size();
//         vector<int> prefixXor(n + 1, 0); // prefixXor[0] = 0

//         // Build prefix XOR
//         for (int i = 0; i < n; i++) {
//             prefixXor[i + 1] = prefixXor[i] ^ arr[i];
//         }

//         vector<int> result;
//         for (auto& q : queries) {
//             int L = q[0], R = q[1];
//             result.push_back(prefixXor[R + 1] ^ prefixXor[L]);
//         }
// //1 001
// //6 100
// //out 101 ->7

// //0 000
// //14 1110
// //out 1110 ->14

// //6   110
// //14 1110 
// //out 1000 ->8
//         return result;
//     }
// };
// // 
// //1  0001
// //9  1001

// //1 001
// //3 011
// //out 010 ->2

// //2 010
// //4 100
// //out 110 ->6

// //6  110
// //8 1000
// //out 1110//8+4+2 ->14
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int>result;
        vector<int> prefixXor(n, arr[0]); // prefixXor[0] = 0

        // Build prefix Sum XOR
        for (short i = 1; i < n; i++) {
            prefixXor[i] = prefixXor[i - 1] ^ arr[i];
        }

        for (vector<int> val : queries)
        {
            short L = val[0], R = val[1];
            if ((L-1) < 0)
                result.emplace_back(prefixXor[R]);
            else
                result.emplace_back(prefixXor[R] ^ prefixXor[L - 1]);
        }
        return result;
    }
};
