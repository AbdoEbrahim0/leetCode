// class Solution {
// public:
//     int longestSubarray(vector<int>& nums) {      
//         int counter = 1;
//         int resOfAnding = nums[0];
//         int maxi = 1;
//         int maxElement=*max_element(nums.begin(),nums.end());
//         for (int i = 1; i < nums.size(); i++)
//         {
//             if ( (resOfAnding & nums[i])>=maxElement)
//             {
//                 resOfAnding = resOfAnding & nums[i];
//                 counter++;
//                 maxi = max(maxi, counter);
//             }
//             else
//             {
//                 resOfAnding = nums[i];
//                 counter = 1;
//             }
//         }
//         return maxi ;
//     }
// };

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxElement = *max_element(nums.begin(), nums.end());
        int maxLength = 0, currentLength = 0;
        
        for (int &num : nums) {
            if (num == maxElement) {
                currentLength++;
                maxLength = max(maxLength, currentLength);
            } else {
                currentLength = 0;
            }
        }
        
        return maxLength;
    }
};
