
// time : O(n log n) space :O(n)
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         //3,1,3,4,2
//         int n = nums.size() ;
//         vector<int>copy(nums.begin(), nums.end()); //O(n)
//         //1 2 3 3 4
//         sort(copy.begin(), copy.end());//O(n log n)
//         int  i;
//         for ( i = 1; i < n; i++)
//         {
//             if (copy[i] == copy[i - 1])
//             {
//              break;   
//             }
//         }
// return copy[i-1];
//     }
// };
//[optimized]  time : O(n) space :O(1) 
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

//can solve also using unordered map OR set time : O(n) space :O(n)

//[optimized]  time : O(n) space :O(1) 
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set <int >uSet;
        int i;
        for ( i = 0; i < n; i++)
        {
            if (uSet.count(nums[i]) )
                break;
            else
                uSet.insert(nums[i]);
        }
        return nums[i];
    }
};
