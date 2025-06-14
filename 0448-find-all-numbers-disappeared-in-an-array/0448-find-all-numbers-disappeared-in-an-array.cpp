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


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        bool arr[100001] = {};
        //4,3,2,7,8,2,3,1
        // 1,2,3,4,5,6,7,8
        // 1,2,3,4,7,8
        vector<int>res;
        int n = nums.size();

        for (int j = 0; j < n; j++)
        {
            arr[nums[j]] =1;
        }
        for (int i = 1; i <= n; i++)
        {
            if (arr[i] ==false)
                res.emplace_back(i);

        }
        return res;
    }
};