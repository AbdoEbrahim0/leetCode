class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefix(n);
        vector<int> suffix(n);
        
        // Build prefix max
        prefix[0] = arr[0];
        for (int i = 1; i < n; ++i) {
            prefix[i] = max(prefix[i - 1], arr[i]);
        }

        // Build suffix min
        suffix[n - 1] = arr[n - 1];
        for (int j = n - 2; j >= 0; --j) {
            suffix[j] = min(suffix[j + 1], arr[j]);
        }

        // Count valid chunks
        int chunks = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (prefix[i] < suffix[i + 1]) {
                chunks++;
            }
        }

        // adds 1 tto chunks in 2 cases Always at least one chunk so
        //also  in case as last element in prefix  can't be compared to next element in suffx dut to reach size of suffex

        return chunks+1 ;     }
};
