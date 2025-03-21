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
//methode 2 O(N) 
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int  maxWidth = 0;
        int i;
        stack<int>stk;
        stk.push(0);
        for ( i = 1 ; i < nums.size() ; i++ )
        {
            if (nums[i] <= nums[stk.top()])
                stk.push(i);
        }

        for (int j = nums.size() - 1; j >= 0; j--)
        {
            
            while (nums[j] >= nums[stk.top()])
            {
                
                maxWidth = max(maxWidth, j - stk.top());
                stk.pop();
                if (stk.empty())
                    return maxWidth;
            }

        }
        return maxWidth;
    }
};