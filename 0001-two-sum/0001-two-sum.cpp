
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {

//         unordered_map<int,int>mp;

//         for (int i = 0; i < nums.size(); i++)
//         {
//             mp[nums[i]]= i;
//         }
        
//         for (int i = 0; i < nums.size(); i++)
//         {
//             auto it = mp.find((target - nums[i]));
//             if (it != mp.end()  && i !=(mp[target - nums[i]]))
//             {
//                 return { i,mp[target - nums[i]] };
//             }
//         }
//         return {};
//     }
// };
//[optimized]
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen; // value -> index

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (seen.count(complement)) {
                return { i,seen[complement]};
            }
            seen[nums[i]] = i;
        }

        return {}; // Should never reach here if one solution is guaranteed
    }
};
