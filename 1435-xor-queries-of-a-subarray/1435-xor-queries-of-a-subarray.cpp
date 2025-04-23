//next sol. give me Time Limit Exceed
// 
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefixXor(n + 1, 0); // prefixXor[0] = 0

        // Build prefix XOR
        for (int i = 0; i < n; i++) {
            prefixXor[i + 1] = prefixXor[i] ^ arr[i];
        }

        vector<int> result;
        for (auto& q : queries) {
            int L = q[0], R = q[1];
            result.push_back(prefixXor[R + 1] ^ prefixXor[L]);
        }

        return result;
    }
};