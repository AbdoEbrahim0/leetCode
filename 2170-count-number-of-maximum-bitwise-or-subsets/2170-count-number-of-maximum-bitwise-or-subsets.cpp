// //using mask
// class Solution {
// public:
//     int countMaxOrSubsets(vector<int>& nums) {

//         int maxOr = 0;
//         for (int &val : nums)
//         {
//             maxOr |= val;
//         }
//         short n = nums.size();
//         int counter = 0;
//         for (int i = 0; i < (1 << n); i++)
//         {
//             int mask = i;
//             int curOr = 0;
//             for (int j = 0; j < n; j++)
//             {
//                 if (mask & 1)
//                 {
//                     curOr |= nums[j];
//                 }
//                 mask = mask >> 1; // mask= mask/2
//             }
            
//             counter += (curOr == maxOr);
//         }
//         return counter;
//     }
// };
//using recursion

class Solution {
public:
    int solve (int idx,int curOr,vector<int> nums,int sizeOfArray,int maxOr)
    {
        if(idx==sizeOfArray)
        return maxOr==curOr;
        int first=solve(idx+1 ,curOr,nums,sizeOfArray,maxOr) ;
        int second =solve(idx+1 ,curOr | nums[idx],nums,sizeOfArray,maxOr);
        return first + second;
        

    }
    int countMaxOrSubsets(vector<int>& nums) {

        int maxOr = 0;
        for (int &val : nums)
        {
            maxOr |= val;
        }
        int n=nums.size();
        return solve(0,0,nums,n,maxOr); 
    }
};