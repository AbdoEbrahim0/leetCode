// #include <unordered_map>
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int, int> seen; // value -> index

//         for (int i = 0; i < nums.size(); ++i) {
//             int complement = target - nums[i];
//             if (seen.count(complement)) {
//                 return {seen[complement], i};
//             }
//             seen[nums[i]] = i;
//         }

//         return {}; // Should never reach here if one solution is guaranteed
//     }
// };

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //unordered_set<int>st(nums.begin(), nums.end());
        unordered_map<int,int>mp;
        vector<int>res(2);
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]= i;
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            
            auto it = mp.find((target - nums[i]));
            if (it != mp.end()  && i !=(mp[target - nums[i]]))
            {
                res[0]=(i);
                res[1]=(mp[target - nums[i]]);
                break;
            }
        }
        return res;
    }
};
