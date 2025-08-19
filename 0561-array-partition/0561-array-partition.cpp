
//gpt

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // Step 1: Sort the array
        int sum = 0;
        for (int i = 0; i < nums.size(); i += 2) {
            sum += nums[i];  // Step 2: Add every alternate element
        }
        return sum;
    }
};
