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

// class Solution {
// public:
//     int maxWidthRamp(vector<int>& nums) {
//         short my_size = nums.size();
//         int maxi = 0;
//         for (int i = 0; i < my_size; i++)
//         {
//             for (int j = i + 1; j < my_size; j++)
//             {
//                 if (j > i && nums[j] >= nums[i])
//                     maxi= max(maxi, j - i);
//             }
//         }
//         return maxi;
//     }
// };

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> rightMax(n);

        // Fill rightMax array with the maximum values from the right
        rightMax[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], nums[i]);
        }

        int left = 0, right = 0;
        int maxWidth = 0;

        // Traverse the array using left and right pointers
        while (right < n) {
            // Move left pointer forward if current left exceeds rightMax
            while (left < right && nums[left] > rightMax[right]) {
                left++;
            }
            maxWidth = max(maxWidth, right - left);
            right++;
        }

        return maxWidth;
    }
};