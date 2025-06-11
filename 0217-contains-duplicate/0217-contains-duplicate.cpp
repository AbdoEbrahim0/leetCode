class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //bool ans = false;
        unordered_map<int, int>ump(nums.size());

        for (int i = 0; i < nums.size(); i++)
        {
            ump[nums[i]] = ump[nums[i]] + 1;
            if (ump[nums[i]] == 2)
                return 1;
        }
        return 0;
    }
};