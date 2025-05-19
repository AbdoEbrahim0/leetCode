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

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<bitset<24>> Bin;
        for (int& val : candidates)
        {
            Bin.emplace_back(bitset<24>(val));
        }

        vector<int>ones(24);
        int maxi = 0;
            for (int i = 0; i < 24; i++)
            {
                for (bitset<24>& val : Bin)
                {
                    if(val[i]&1)
                    ones[i]++;
                }
                maxi = max(ones[i], maxi);
            }
        return maxi;
    }
};