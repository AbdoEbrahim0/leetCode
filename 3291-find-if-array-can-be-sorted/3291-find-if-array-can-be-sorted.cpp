//total O(n^2) *O(n)
// class Solution {
// public:
//     bool canSortArray(vector<int>& nums) {
//         unordered_map <int, int>mp;
//         for (int& val : nums)//o(1e8) =O(26.5) *O(n)
//         {
//             int x = val;
//             int ct = 0;
//             while (x != 0)
//             {
//                 if (x & 1) ct++;
//                 x = x >> 1; //shift right
//             }
//             mp[val] = ct;
//         }
//         //bubble sort O(n^2)
//         int n = nums.size();
//         for (int i = 0; i < n - 1; i++)
//         {
//             for (int j = 0; j < n - i - 1; j++)
//             {
//                 if (nums[j] > nums[j + 1])
//                 {
//                     if (mp[nums[j]] == mp[nums[j+1]])
//                         swap(nums[j], nums[j + 1]);
//                     else
//                         return false;
//                 }
//             }
//         }
//         return true;
//     }
// };

class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        unordered_map <int, int>mp;
        for (int& val : nums)//o(log2(1e8) ) =O(26.5) *O(n)
        {
            int x = val;
            int ct = 0;
            while (x != 0)
            {
                if (x & 1) ct++;
                x = x >> 1; //shift right
            }
            mp[val] = ct;
        }
        //divide into segments to sort O(n log n)
        int n = nums.size();
        int last = 0;
        for (int i = 0; i < n-1 ; i++) //o(n)
        {
                if (mp[nums[i]] != mp[nums[i + 1]])
                {
                    sort(nums.begin() + last, nums.begin() + i+1);// o(n log n)
                    last = i+1;
                }
        }
        sort(nums.begin() + last, nums.end());// o(n log n)

        return is_sorted(nums.begin(),nums.end());
    }
};