class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //sort(nums.begin(), nums.end());
        auto toZeros =remove(nums.begin(), nums.end(), 0);
        for (int dx= toZeros - nums.begin();dx<nums.size(); dx++)
        {
            nums[dx]= 0;
        }
        //return nums;
    }
};