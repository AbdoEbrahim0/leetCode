// n log n as remove sort implecitly 
// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
        
//         auto toZeros =remove(nums.begin(), nums.end(), 0);
//         for (int dx= toZeros - nums.begin();dx<nums.size(); dx++)
//         {
//             nums[dx]= 0;
//         }
//     }
// };
// if we dont care about sorting
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int n = nums.size();
        int lastIndx = 0;
        short numOfZeros=0;
        for (int j = 0; j < n && lastIndx<(n-numOfZeros) ; j++)
        {
            if (nums[j] != 0)
                swap(nums[lastIndx++], nums[j]);
            else
                numOfZeros++;   
        }
        
        for (int j = lastIndx; j < n; j++)
        {
            nums[j] = 0;
        }
    }
};