//time: O( n log n) Space Complexity: O(n) 
// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         if(nums[0] !=0) return 0;
//         //0 1  3
//         int i;
//         int n= nums.size();
//         for ( i = 1; i <n; i++)
//         {
//             if (nums[i] != nums[i - 1] + 1)
//                 return nums[i] - 1;
//         }
//         if(n==1)
//         return abs(nums[i-1]-1);
//         return nums[i - 1] +1;
//     }
// };
//time: O(  n) Space Complexity: O(n) 
// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         //wherre 1 <= n <= 1e4
//         //bool arr[10001] = {};
//         int n=nums.size();
//         vector<bool>arr(n);
//         //0 1  3
//         for ( int i = 0; i < n; i++)
//         {
//             arr[nums[i]]= 1;      
//         }
//         int j;
//         for (j = 0; j <= nums.size(); j++)
//         {
//             if(!arr[j])
//                 return j;
//         }
//         return 0;
//     }
// };
//MATH  time: O(n) Space Complexity: O(1) 

// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int n = nums.size();
//         int expectedSum = n * (n + 1) / 2;
//         int actualSum = accumulate(nums.begin(), nums.end(), 0);
//         return expectedSum - actualSum;
//     }
// };
//bit manipulation   time: O(n) Space Complexity: O(1) 
// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int n = nums.size();
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
//binary search  
//is sorted aleardy will be (log n)and  if not (n log n)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Ensure sorted for this method
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] > mid) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
