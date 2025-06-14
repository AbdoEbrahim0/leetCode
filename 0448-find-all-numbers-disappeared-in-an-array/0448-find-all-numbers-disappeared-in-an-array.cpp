// class Solution {
// public:
//     vector<int> findDisappearedNumbers(vector<int>& nums) {
//         set<int> mySet(nums.begin(), nums.end());
        
//         vector<int>res;
//         //4,3,2,7,8,2,3,1
//         //1,2,3,4,7,8
//         int n = nums.size();
//         auto it =mySet.begin();
//         for (int i = 1; i <= n; i++)
//         {
//             if (i != *(it))
//                 res.emplace_back(i);
//             else
//                 it++;
//         }
//         return res;
//     }
// };


////o(n log n) space o(n)
// visted array
// class Solution {
// public:
//     vector<int> findDisappearedNumbers(vector<int>& nums) {
//         set<int> mySet(nums.begin(), nums.end());
        
//         vector<int>res;
//         //4,3,2,7,8,2,3,1
//         //1,2,3,4,7,8
//         int n = nums.size();
//         auto it =mySet.begin();
//         for (int i = 1; i <= n; i++)
//         {
//             if (i != *(it))
//                 res.emplace_back(i);
//             else
//                 it++;
//         }
//         return res;
//     }
// };
//o(n) space o(1)
// class Solution {
// public:
//     vector<int> findDisappearedNumbers(vector<int>& nums) {
//         set<int> mySet(nums.begin(), nums.end());
        
//         vector<int>res;
//         //4,3,2,7,8,2,3,1
//         //1,2,3,4,7,8
//         int n = nums.size();
//         auto it =mySet.begin();
//         for (int i = 1; i <= n; i++)
//         {
//             if (i != *(it))
//                 res.emplace_back(i);
//             else
//                 it++;
//         }
//         return res;
//     }
// };

//o(n) space o(n)
// class Solution {
// public:
//     vector<int> findDisappearedNumbers(vector<int>& nums) {
//         //bool arr[100001] = {};
//         int n = nums.size();
//         vector<bool> arr(n);
        
//         vector<int>res;
        

//         for (int j = 0; j < n; j++)
//         {
//             arr[nums[j]] =1;
//         }
//         for (int i = 1; i <= n; i++)
//         {
//             if (arr[i] ==false)
//                 res.emplace_back(i);

//         }
//         return res;
//     }
// };

//most optimized with memory care
class Solution {
public:
vector<int> findDisappearedNumbers(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        int index = abs(nums[i]) - 1;
        nums[index] = -abs(nums[index]);  // Mark as visited
    }
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0)
            res.push_back(i + 1);  // Index + 1 is missing
    }
    return res;
}

};