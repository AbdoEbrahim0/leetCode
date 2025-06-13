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
//O(n)	O(1)

// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {   
//         short n = nums.size();
//         short lastIndx = 0;
//         short numOfZeros=0;
//         for (short j = 0; j < n && lastIndx<(n-numOfZeros) ; j++)
//         {
//             if (nums[j] != 0)
//                 swap(nums[lastIndx++], nums[j]);
//             else
//                 numOfZeros++;   
//         }
//         for (short j = lastIndx; j < n; j++)
//         {
//             nums[j] = 0;
//         }
//     }
// };

//2 pointers best for interview 
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        short n = nums.size();
        short lastNonZeroIndex = 0;
        for (short j = 0; j < n   ; j++)
        {
            if (nums[j] != 0)
            {
                nums[lastNonZeroIndex++] = nums[j];
                //  lastNonZeroIndex ++;
            }
        }
        for (; lastNonZeroIndex < n   ; )
        {
        nums[lastNonZeroIndex++] =0;
        }
    }
};