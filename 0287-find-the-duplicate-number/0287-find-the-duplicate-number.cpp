// // class Solution {
// // public:
// //     int findDuplicate(vector<int>& nums) {
// //         int n = nums.size()-1;
// //         int expectedSum = n * (n + 1) / 2;
// //         int actualSum = accumulate(nums.begin(), nums.end(), 0);
// //         return actualSum - expectedSum ;
// //     }
// // };

// // class Solution {
// // public:
// //     int findDuplicate(vector<int>& nums) {
// //         int n = nums.size()-1;
// //         int xorAll = 0;
// //         for (int i = 0; i <= n; ++i) {
// //             xorAll ^= i;
// //         }
// //         for (int num : nums) {
// //             xorAll ^= num;
// //         }
// //         return xorAll;
// //     }
// // };

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         int n = nums.size() ;
//         int arr[100001] = {};
//         int i;
//         for (i = 0; i < n; i++)
//         {
//             //arr[nums[i]] = arr[nums[i]]++; // wrong  implement      
//             arr[nums[i]]++; //correct
//             if (arr[nums[i]] >= 2)
//                 break;
//         }
//         return nums[i];
//     }
// };

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //3,1,3,4,2
        int n = nums.size() ;
        vector<int>copy(nums.begin(), nums.end());
        //1 2 3 3 4
        sort(copy.begin(), copy.end());
        int  i;
        for ( i = 1; i < n; i++)
        {
            if (copy[i] == copy[i - 1])
            {
             break;   
            }
        }
return copy[i-1];
    }
};