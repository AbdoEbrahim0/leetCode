class Solution {
public:
    // [1,4,3,3,2]
    int longestMonotonicSubarray(vector<int>& nums) {
        int mx = 0;
        int cnt =1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
            {
                cnt++;
            }
            else
            {
                mx = max(mx, cnt);
                cnt = 1;
            }
        }
        mx = max(mx, cnt);
        cnt = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < nums[i - 1])
            {
                cnt++;
            }
            else
            {
                mx = max(mx, cnt);
                cnt = 1;
            }
        }
        return max(mx, cnt);
    }
};