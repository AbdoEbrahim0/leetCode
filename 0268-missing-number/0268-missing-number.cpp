class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums[0] !=0) return 0;
        //0 1  3
        int i;
        int n= nums.size();
        for ( i = 1; i <n; i++)
        {
            if (nums[i] != nums[i - 1] + 1)
                return nums[i] - 1;
        }
        if(n==1)
        return abs(nums[i-1]-1);
        return nums[i - 1] +1;
    }
};