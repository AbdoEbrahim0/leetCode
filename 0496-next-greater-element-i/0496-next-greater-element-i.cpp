// //O(n2) + O(n1)*O(n2-startIndx)  space: O(1)
// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//                 int arr[10001] = {};
//         // nums1 = [4,1,2], nums2 = [1,3,4,2]
//         vector<int>ans;
//         for (int i = 0; i< nums2.size(); i++)//O(n2)
//         {
//             arr[nums2[i]]=i;
//         }

//         for (int j = 0; j < nums1.size(); j++)//o(n1)
//         {
//             int s =arr[nums1[j]] ;
//             ans.emplace_back(-1);
//             while (s<nums2.size())//O(n2)
//             {
//                 if (nums1[j] < nums2[s])
//                 {
//                     ans.pop_back();
//                     ans.emplace_back(nums2[s]);
//                     break;
//                 }
//                 s++;
//             }
//         }

//         return ans;
//     }
// };
//[optimized] dynamic vector
//O(n2) + O(n1)*O(n2-startIndx)  space: O(maxE)
// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         short maxE = *max_element(nums2.begin(), nums2.end());
//         vector<int>arr(maxE+1);
//         short n2Size = nums2.size();
//         short n1Size =nums1.size();
//         vector<int>ans(n1Size);
//         fill(ans.begin(), ans.end(), -1);
//         for (int i = 0; i < n2Size; i++)
//         {
//             arr[nums2[i]] = i;
//         }
// int s;
//         for (int j = 0; j < n1Size; j++)
//         {
//             s = arr[nums1[j]];
//             while (s < nums2.size())
//             {
//                 if (nums1[j] < nums2[s])
//                 {
//                     ans[j] =nums2[s];
//                     break;
//                 }
//                 s++;
//             }

//         }

//         return ans;

//     }
// };
//monotonic stack  [optimized]
// Time: O(n1)+ O(n2-startIndx)  space: O(maxE) 

// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         short n1Size = nums1.size();
//         short n2Size = nums2.size();
//         vector<int>ans(n1Size);
//         stack<int> stk;
//         // nums1 = [4,1,2], nums2 = [1,3,4,2]
//         short maxE = *max_element(nums2.begin(), nums2.end());
//         vector<int>arr(maxE + 1);
//         fill(arr.begin(), arr.end(), -1);
//         for (int i = n2Size-1; i >=0; i--)
//         {
//             while(stk.size() && nums2[i] > stk.top())
//                 stk.pop();
        
//             if (stk.size() && nums2[i] < stk.top())
//             {
//                 arr[nums2[i]] = stk.top();
//                 stk.push(nums2[i]);
//             }
//             stk.push(nums2[i]);
//         }
//         for (int j = 0; j < n1Size; j++)
//         {
//             ans[j] = arr[nums1[j]];
//         }
//         return ans;

//     }
// };

//monotonic stack  [MEM optimized]
// Time: O(n1)+ O(n2-startIndx)  space: O(maxE) 

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        short n1Size = nums1.size();
        short n2Size = nums2.size();
        //vector<int>ans(n1Size);
        
        stack<int> stk;
        // nums1 = [4,1,2], nums2 = [1,3,4,2]
        short maxE = *max_element(nums2.begin(), nums2.end());
        vector<int>arr(maxE + 1);
        fill(arr.begin(), arr.end(), -1);
        for (int i = n2Size-1; i >=0; i--)
        {
            while(stk.size() && nums2[i] > stk.top())
                stk.pop();
            
            if (stk.size() && nums2[i] < stk.top())
            {
                arr[nums2[i]] = stk.top();
                stk.push(nums2[i]);
            }
            stk.push(nums2[i]);
        }
        for (int j = 0; j < n1Size; j++)
        {
            nums1[j] = arr[nums1[j]];
        }
        return nums1;
    }
};