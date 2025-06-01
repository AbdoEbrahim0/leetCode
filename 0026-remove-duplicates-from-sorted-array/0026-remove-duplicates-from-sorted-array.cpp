// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int sizeNums = nums.size();
//         int indcies[3 * 10000]  ;
//         fill_n(indcies, 30000, -1);
//         int start=0;
//         for (int i = sizeNums - 1; i >0; i--,start++)
//         {
//             if (nums[i] == nums[i - 1])
//             {
//                 indcies[start] = i;
//             }
            
//         }
//         for (int z = 0; z < sizeNums; z++)
//         {
//         if(indcies[z]>=0)
//             nums.erase(nums.begin() + indcies[z]);
//         }
//         return nums.size();
//     }
// };

// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         short sizeNums = nums.size();
//         int *indcies=new int[sizeNums];
//         fill_n(indcies, sizeNums, -1);
//         short start = 0;
//         for (short i = sizeNums - 1; i > 0; i--)
//         {
//             if (nums[i] == nums[i - 1])
//             {
//                 indcies[start++] = i;
//             }
//         }
//         for (short z = 0; z <sizeNums ; z++)
//         {
//             if (indcies[z] >= 0)
//                 nums.erase(nums.begin() + indcies[z]);
//         }
//         return nums.size();
//     }
// };
//less optimized
// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         vector<int>res;
//         set<int>nums2(nums.begin(), nums.end());
//         for (auto it = nums2.begin(); it != nums2.end(); it++)
//         {
//             res.emplace_back(*it);
//         }
//         nums = res;
//         res.clear();
        
//         return nums.size();
//     }
// };
//more optimized
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        set<int>nums2(nums.begin(), nums.end());
        int i = 0;
        for (int val : nums2) {
            nums[i++] = val;  // copy unique values back to nums
        }

        nums.erase(nums.begin() + i, nums.end());  // erase remaining duplicate tail

        return nums.size();
        
    }
};