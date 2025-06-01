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

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int sizeNums = nums.size();
        int *indcies=new int[sizeNums];
        fill_n(indcies, sizeNums, -1);
        short start = 0;
        for (int i = sizeNums - 1; i > 0; i--)
        {
            if (nums[i] == nums[i - 1])
            {
                indcies[start++] = i;
            }

        }
        for (int z = 0; z <sizeNums ; z++)
        {
            if (indcies[z] >= 0)
                nums.erase(nums.begin() + indcies[z]);
        }
        return nums.size();
    }
};