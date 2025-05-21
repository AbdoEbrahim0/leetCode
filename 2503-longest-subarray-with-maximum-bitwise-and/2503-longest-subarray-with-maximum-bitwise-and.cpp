class Solution {
public:
    
    int longestSubarray(vector<int>& nums) {
        
        int counter = 1;
        int resOfAnding = nums[0];
        int maxi = 0;
        int maxElement=*max_element(nums.begin(),nums.end());
        for (int i = 1; i < nums.size(); i++)
        {
            if ((resOfAnding & nums[i]) >= resOfAnding && (resOfAnding & nums[i])>=maxElement)
            {
                resOfAnding = resOfAnding & nums[i];
                counter++;
                maxi = max(maxi, counter);
            }
            else
            {
               // maxElement = max(nums[i], maxElement);
                resOfAnding = nums[i];
                counter = 1;
            }
        }
        return maxi = max(maxi, counter);
    }
};