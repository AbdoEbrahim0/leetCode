// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         unordered_map<int, int>ump(nums.size());
//         for (int i = 0; i < nums.size(); i++)
//         {
//             ump[nums[i]] = ump[nums[i]] + 1;
//             if (ump[nums[i]] == 2)
//                 return 1;
//         }
//         return 0;
//     }
// };

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            if (seen.count(num)) return true;
            seen.insert(num);
        }
        return false;
    }
};
