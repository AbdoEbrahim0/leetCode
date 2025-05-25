class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        unordered_map <int, int>mp;
        for (int& val : nums)
        {
            int x = val;
            int ct = 0;
            while (x != 0)
            {
                if (x & 1) ct++;
                x = x >> 1; //shift right
            }
            mp[val] = ct;
        }
        //bubble sort
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (nums[j] > nums[j + 1])
                {
                    if (mp[nums[j]] == mp[nums[j+1]])
                        swap(nums[j], nums[j + 1]);
                    else
                        return false;
                }
            }
        }
        return true;
    }
};