// O(N)+O(N)
// class Solution {
// public:
//     // [1,4,3,3,2]
//     int longestMonotonicSubarray(vector<int>& nums) {
//         int mx = 0;
//         int cnt =1;
//         for (int i = 1; i < nums.size(); i++)
//         {
//             if (nums[i] > nums[i - 1])
//             {
//                 cnt++;
//             }
//             else
//             {
//                 mx = max(mx, cnt);
//                 cnt = 1;
//             }
//         }
//         mx = max(mx, cnt);
//         cnt = 1;
//         for (int i = 1; i < nums.size(); i++)
//         {
//             if (nums[i] < nums[i - 1])
//             {
//                 cnt++;
//             }
//             else
//             {
//                 mx = max(mx, cnt);
//                 cnt = 1;
//             }
//         }
//         return max(mx, cnt);
//     }
// };

class Solution {
public:
    // [1,4,3,3,2]
    int longestMonotonicSubarray(vector<int>& nums) {
        int mx = 1;
        
        stack<int>stkInc;
        stack<int>stkDec;
        stkInc.push(nums[0]);

        for (int i = 1; i < nums.size(); i++)
        {
            while(stkInc.size()&& nums[i] <= nums[i - 1])
            {
                stkInc.pop();
            }
            stkInc.push(nums[i]);
            mx = max(mx , (int)stkInc.size());
        }
        stkDec.push(nums[0]);
        for (int i = 1; i < nums.size(); i++)
        {
            while (stkDec.size() && nums[i] >= nums[i - 1])
            {
                stkDec.pop();
            }
            stkDec.push(nums[i]);
            mx = max(mx, (int)stkDec.size());
        }
        return mx;
    }
};