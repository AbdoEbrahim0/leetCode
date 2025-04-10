//methode 1 naive N^2
// class Solution {
// public:
//     int maxWidthRamp(vector<int>& nums) {
//         int  maxWidth = 0;
//         int i = 0, j = 0;
//         for (i = 0; i < nums.size(); i++)
//         {
//             for (j = i+1; j < nums.size(); j++)
//             {
//                 if (nums[j] >= nums[i]) //we replace this cond:&& j >= i with starting j from (i+1)
//                 {
//                     if ((j - i) >= maxWidth)
//                         maxWidth = j - i;
//                 }
//             }
//         }
//         return maxWidth;
//     }
// };
//methode 2 using stack O(N) 
// class Solution {
// public:
//     int maxWidthRamp(vector<int>& nums) {
//         int  maxWidth = 0;
//         unsigned short i;
//         stack<unsigned short>stk;
//         stk.push(0);
//         //which i < j 
//         for ( i = 1 ; i < nums.size() ; i++ )
//         {
//             if (nums[i] <= nums[stk.top()])
//                 stk.push(i);
//         }
        
//         for (unsigned short j = nums.size() - 1; j >= 0; j--)
//         {
//             while (nums[j] >= nums[stk.top()])
//             {
//                 maxWidth = max(maxWidth, j - stk.top());
//                 stk.pop();
//                 if (stk.empty())
//                     return maxWidth;
//             }
//         }
//         return maxWidth;
//     }
// };

///////////////
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int>stk;
        int maxRamp = 0;
        int i = 0;

        for (i = 0; i < nums.size(); i++)
        {
            if (stk.empty() || nums[i] <= nums[stk.top()])// is there a value small than exist in value of TOP
                stk.push(i);
        }
        //{ 9, 8, 1, 0, 1, 9, 4, 0, 4, 1 };
        //{ 6,0,8,2,1,5 };
        for (int j = nums.size() - 1; j >= 0;j-- )
        {
            while (nums[j] >= nums[stk.top()])
            {
                maxRamp = max(maxRamp, j - stk.top());
                stk.pop();
                    if (stk.empty())
                    return maxRamp;
            }

        }
        return maxRamp;
    }
};
