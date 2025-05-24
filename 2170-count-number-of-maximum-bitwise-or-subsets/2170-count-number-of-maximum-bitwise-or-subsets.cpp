class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {

        int maxOr = 0;
        for (int &val : nums)
        {
            maxOr |= val;
        }
        short n = nums.size();
        int counter = 0;
        for (int i = 0; i < (1 << n); i++)
        {
            int mask = i;
            int curOr = 0;
            for (int j = 0; j < n; j++)
            {
                if (mask & 1)
                {
                    curOr |= nums[j];
                }
                mask = mask >> 1; // mask= mask/2
            }
            
            counter += (curOr == maxOr);
        }
        return counter;
    }
};