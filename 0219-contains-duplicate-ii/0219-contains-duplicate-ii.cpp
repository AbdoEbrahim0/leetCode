// class Solution {
// public:
//     bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        
//     }
// };

// class Solution {
// public:
//     bool containsNearbyDuplicate(vector<int>& nums, int k) {
//         unordered_set<int> window;
//         for (int i = 0; i < nums.size(); ++i) {
//             if (window.count(nums[i])) return true;
//             window.insert(nums[i]);
//             if (window.size() > k) {
//                 window.erase(nums[i - k]);
//             }
//         }
//         return false;
//     }
// };












class Solution {
public:
    //can not use array of integer as (-1e9 <= nums[i] <= 1e9)
    //int indxOf1stAppearance[1000000000];
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>ump(n);
        
         for (int i = 0; i < n; i++)
         {
             if (ump[nums[i]] == 0) //not found
             {
                 ump[nums[i]] = i+1; //plus 1 to avoid case of saving index 0
             }
             else //found num before
             {
                 if (abs(i - (ump[nums[i]] -1)) <= k) //sub 1 to return to real index 
                 {
                     return true;
                 }else
                 ump[nums[i]] = i+1; ///plus 1 to avoid case of saving index 0
             }
         }
         return false;
    }
};









