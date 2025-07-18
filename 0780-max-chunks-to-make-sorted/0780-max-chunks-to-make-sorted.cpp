// class Solution {
// public:
//     int maxChunksToSorted(vector<int>& arr) {
//         int n = arr.size();
//         vector<int> prefix(n);
//         vector<int> suffix(n);
        
//         // Build prefix max
//         prefix[0] = arr[0];
//         for (int i = 1; i < n; ++i) {
//             prefix[i] = max(prefix[i - 1], arr[i]);
//         }

//         // Build suffix min
//         suffix[n - 1] = arr[n - 1];
//         for (int j = n - 2; j >= 0; --j) {
//             suffix[j] = min(suffix[j + 1], arr[j]);
//         }

//         // Count valid chunks
//         int chunks = 0;
//         for (int i = 0; i < n - 1; ++i) {
//             if (prefix[i] < suffix[i + 1]) {
//                 chunks++;
//             }
//         }

//         // adds 1 tto chunks in 2 cases Always at least one chunk so
//         //also  in case as last element in prefix  can't be compared to next element in suffx dut to reach size of suffex

//         return chunks+1 ;     }
// };
//optimized^2 very smart sol
// class Solution {
// public:
//     int maxChunksToSorted(vector<int>& arr) {

//         int cntIndcies = 0;
//         int cntValues = 0;
//         int chunks=0;
//         for (int i = 0; i < arr.size(); i++)
//         {
//             cntIndcies += i;
//             cntValues += arr[i];
//             if (cntValues == cntIndcies)
//                 chunks++;
//         }
//         return chunks;
//     }
// };

//optimized^3 very smart sol
// class Solution {
// public:
//     int maxChunksToSorted(vector<int>& arr) {
//         int cntValues = 0;
//         int chunks=0;
//         for (int i = 0; i < arr.size(); i++)
//         {
//            if(i)
//             arr[i] += arr[i-1]; //repalcing last element with current and previous in array
//             if (( i*(i+1)/2 ) == arr[i]) //equasion of incremental series
//                 chunks++;
//         }
//         return chunks;
//     }
// };
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        //in :[4, 3, 2, 1, 0] out : 1
        //in :[1 ,0 ,2 ,3 ,4] out : 4
        //indices 0 1 2 3 4 
        //values  4 3 2 1 0
        //max     4 4 4 4 4
        //chunks  0 0 0 0 1

        int chunks=0,mx=0;
        for (int i = 0; i < arr.size(); i++)
        {
            mx = max(mx, arr[i]);  
            if (mx == i)        
                chunks++;
        }
        return chunks;
    }
};