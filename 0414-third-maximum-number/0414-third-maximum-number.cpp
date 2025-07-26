// class Solution {
// public:
//     int thirdMax(vector<int>& nums) {
//         if (nums.size() < 3)
//             return *max_element(nums.begin(), nums.end());
//         sort(nums.begin(), nums.end());
//             return nums[nums.size() - 3];
//     }
// };
// 1 2 2 3
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int > mySet(nums.begin(), nums.end());
        int mySetSize = mySet.size();
        if (mySetSize < 3)
            return *max_element(nums.begin(), nums.end());
        int i = 0;
        nums.resize(mySet.size());
        for (auto it = mySet.begin(); i< mySet.size(); it++)
        {
            nums [i++] = *it;
        }
        return nums[nums.size()- 3];
    }
};