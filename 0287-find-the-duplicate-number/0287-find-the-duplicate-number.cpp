// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         int n = nums.size()-1;
//         int expectedSum = n * (n + 1) / 2;
//         int actualSum = accumulate(nums.begin(), nums.end(), 0);
//         return actualSum - expectedSum ;
//     }
// };

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         int n = nums.size()-1;
//         int xorAll = 0;
//         for (int i = 0; i <= n; ++i) {
//             xorAll ^= i;
//         }
//         for (int num : nums) {
//             xorAll ^= num;
//         }
//         return xorAll;
//     }
// };

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size() ;
        int arr[100001] = {};
        int i;
        for (i = 0; i < n; i++)
        {
            //arr[nums[i]] = arr[nums[i]]++; // wrong  implement      
            //correct
            arr[nums[i]]++;

            if (arr[nums[i]] >= 2)
                break;
        }


        return nums[i];
    }
};