//doenst know maximum number of postive and negative
//O(n)
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         //{ 4, 1, 2, 1, 2 };
//         int n = nums.size();
//         vector<int> negative ;
//         //fill(negative.begin(), negative.end(), false);
//         int maxE = *max_element(nums.begin(), nums.end());
//         vector< int >arr (maxE + 1);
//         //fill(negative.begin(), negative.end(), false);
//         for (int i=0;i<nums.size();i++)
//         {
//             if (nums[i] < 0)
//                 negative.emplace_back(nums[i]*-1);
//             else
//                 arr[nums[i]]++;
//         }
//         for (int i = 0; i < arr.size(); i++)
//         {
//             if (arr[i] == 1)
//                 return i;
//         }
//         //ceck negative vals
//         maxE = *max_element(negative.begin(), negative.end());
//         vector< int >arr2(maxE + 1);
//         for (int i = 0; i < negative.size(); i++)
//         {
//                 arr2[negative[i]]++;
//         }
//         for (int i = 0; i < arr2.size(); i++)
//         {
//             if (arr2[i] == 1)
//                 return i*-1;
//         }
        
//         return 0;
//     }
// };

// still O(n) but [optimized]
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         //{ 4, 1, 2, 1, 2 };
//         int n = nums.size();
//         vector<int> negative ;
//         int arr[3 * 10000] = {};
//         for (int i=0;i< n;i++)
//         {
//             if (nums[i] < 0)
//                 negative.emplace_back(nums[i]*-1);
//             else
//                 arr[nums[i]]++;
//         }
//         for (int i = 0; i < 3 * 10000; i++)
//         {
//             if (arr[i] == 1)
//                 return i;
//         }
//         //ceck negative vals
//         int arr2[3 * 10000] = {};
//         for (int i = 0; i < negative.size(); i++)
//         {
//                 arr2[negative[i]]++;
//         }
//         for (int i = 0; i < 3 * 10000; i++)
//         {
//             if (arr2[i] == 1)
//                 return i*-1;
//         }        
//         return 0;
//     }
// };

// still O(n) but [optimized ^2]
//  know maximum number of postive and negative in array from constarins
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         short n = nums.size();
//         short PostiveOccuranences[3 * 10000] = {};
//         short negativeOccurnences[3 * 10000] = {};
//         for (int i = 0; i < n; i++)
//         {
//             if (nums[i] < 0)
//             negativeOccurnences[nums[i] * -1]++;
//             else
//                 PostiveOccuranences[nums[i]]++;
//         }
//         for (int i = 0; i < 3 * 10000; i++)
//         {
//             if (PostiveOccuranences[i] == 1)
//                 return i;
//             if (negativeOccurnences[i] == 1)
//                 return i * -1;
//         }
//         return 0;
//     }
// };
// [optimized ^3] this approach can only work in case of duplicated apperance  " every element appears twice"
/*
| A | B | A ^ B |
| - | - | ----- |
| 0 | 0 | 0     |
| 0 | 1 | 1     |
| 1 | 0 | 1     |
| 1 | 1 | 0     |
a ^ a = 0 (any number XOR itself = 0)

a ^ 0 = a (any number XOR 0 = itself)

XOR is commutative and associative:
→ a ^ b ^ a = b (order doesnt matter)
res = 0
res ^= 2 → res = 2
res ^= 2 → res = 0    // 2 ^ 2 = 0
res ^= 3 → res = 3    // 0 ^ 3 = 3

*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int num : nums)
            res ^= num;  // XOR cancels duplicates
        return res;
    }
};

