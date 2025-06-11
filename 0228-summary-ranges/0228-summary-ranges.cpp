// class Solution {
// public:
//     vector<string> summaryRanges(vector<int>& nums) {
//         if(nums.size()==0)
//         return {};
//         vector<string> v;
//         string s="";
//         int end= nums[0],st = nums[0];
//         /*
//         Input: nums = [0,1,2,4,5,7]
//         Output: ["0->2","4->5","7"]
//         */
//         for (int i=0 ;i< nums.size();i++)
//         {

//             while (i+1 < nums.size() && nums[i + 1] == nums[i] + 1)
//             {
//                 end = nums[i + 1];
//                 i++;
//             }
//             if (i == nums.size() - 1)//last element
//                 end = nums[i];
// //            if (st == end)
//             if (i + 1 < nums.size() && st == end)
//             {
//                 v.push_back(to_string(nums[i])) ;
//             }
//             else
//             {
//                 if (st < end)
//                     s = to_string(st) + "->" + to_string(end);
//                 else
//                     s = to_string(st);
//                 v.push_back(s);
//             }
//                 if(i + 1 <nums.size())
//                 st = nums[i+1];
//         }
//         return v;
//     }
// };

//after cleaning up
// class Solution {
// public:
//     vector<string> summaryRanges(vector<int>& nums) {
//         if (nums.size() == 0)
//             return {};
//         vector<string> v;
        
//         int end= nums[0],st = nums[0];
//         /*
//         Input: nums = [0,1,2,4,5,7]
//         Output: ["0->2","4->5","7"]

//         Input: nums = [0,2,3,4,6,8,9]
//         Output: ["0","2->4","6","8->9"]
//         */
//         int n = nums.size();

//         for (int i=0 ;i< nums.size();i++)
//         {

//             while (i+1 < n && nums[i + 1] == nums[i] + 1)
//             {
//                 end = nums[i + 1];
//                 i++;
//             }
//             if (i == n - 1)
//                 end = nums[i];
//             if (i + 1 < n && st == end)
//             {
//                 v.emplace_back(to_string(nums[i])) ;
//             }
//             else
//             {
//                 if (st < end)
//                     v.emplace_back(to_string(st) + "->" + to_string(end));
//                 else
//                     v.emplace_back(to_string(st));
//             }
//                 if(i + 1 < n)
//                 st = nums[i+1];
//         }
//         return v;
//     }
// };
//after simplyify logic and deal with edge case 
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = nums.size();
        if (n == 0) return res;

        int start = nums[0];

        for (int i = 1; i <= n; ++i) {
            // If we're at the end or the sequence breaks
            if (i == n || nums[i] != nums[i - 1] + 1) {
                if (nums[i - 1] == start) {
                    res.emplace_back(to_string(start));
                } else {
                    res.emplace_back(to_string(start) + "->" + to_string(nums[i - 1]));
                }
                // If not at end, start a new range
                if (i < n) start = nums[i];
            }
        }

        return res;
    }
};

