// class Solution {
// public:
//     int largestCombination(vector<int>& candidates) {

//         int res = candidates[0];
//         vector<int> anding;
//         vector<bitset<32>> Bin;
//         for (int& val : candidates)
//         {
//             Bin.emplace_back(bitset<32>(val));
//         }

//         vector<int>ones(32);
//         int maxi = 0;
//             for (int i = 0; i < 32; i++)
//             {
//                 for (int x = 0; x < candidates.size(); x++)
//                 {

//                     if(Bin[x][i]==1)
//                     ones[i]++;
//                 }
//                 maxi = max(ones[i], maxi);
//             }
        
        
//         return maxi;
//     }
// };

//[optimized] //change number of bit from 32 to 24 as max number can be 10^7
// class Solution {
// public:
//     int largestCombination(vector<int>& candidates) {
//         vector<bitset<24>> Bin;
//         for (int& val : candidates)
//         {
//             Bin.emplace_back(bitset<24>(val));
//         }
//         vector<int>ones(24);
//         int maxi = 0;
//             for (int i = 0; i < 24; i++)
//             {
//                 for (bitset<24>& val : Bin)
//                 {
//                     if(val[i]&1)
//                     ones[i]++;
//                 }
//                 maxi = max(ones[i], maxi);
//             }
//         return maxi;
//     }
// };
// //
// class Solution {
// public:
//     int largestCombination(vector<int>& candidates) {
//         vector<int>ones(24);
//         int maxi = 0;
//         for (int& val : candidates)
//         {
//             bitset<24> bits (val);
//             for (short i = 0; i < 24; i++)
//             {
//                 if(bits[i])
//                 ones[i]++;
//                 //maxi = max(ones[i], maxi);
//             }
//         }
//         maxi = *max_element(ones.begin(), ones.end());
//         return maxi;
//     }
// };


class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int n = candidates.size();
        int max_n = 0, cnt = 0;
        for(int i = 0; i < 24; i++) {
            cnt = 0;
            for(int j = 0; j < n; j++) {
                cnt += ((candidates[j] & (1<<i)) != 0) ? 1 : 0;
            }
            max_n = max(max_n, cnt);
        }
        return max_n;
    }
};