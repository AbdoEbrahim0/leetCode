
//priorty queue time: O(N Log N) space>> pr-Q O(N)
// class Solution {
// public:
//     vector<int> sortArray(vector<int>& nums) { 
//         priority_queue<int>pr(nums.begin(), nums.end());//additiion or removing take log n 
//         //we adding numbers to n so total =n log n
//         int x=nums.size()-1;
//         while (pr.size())
//         {
//             nums[x--] = pr.top();
//             pr.pop();
//         }
//         return nums;
//     }
// };
//using Freq Array time: O(N Log N) space: O(1)
class Solution {
public:
        /*
        1 <= nums.length <= 5 * 104
        -5 * 104 <= nums[i] <= 5 * 104
        */
    vector<int> sortArray(vector<int>& nums) {
        vector<int> posV(5 * 10000 + 1);
        vector<int> negV(5 * 10000 + 1);  
        //{ 5,2,3,1,-10,-500,-1,0,8 };
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= 0)
            {
                posV[nums[i]]++;
            }
            else
            {
                negV[-nums[i]]++;
            }
        }
        //{ 5,2,3,1,-10,-500,-1,0,8 };
        int indx = 0;
        for (int i = negV.size() - 1; i >= 0; i--)
        {
            for (int z = 0; z < negV[i]; z++)
                nums[indx++] = -i;
        }
        for (int i = 0; i < posV.size(); i++)
        {
            for (int z = 0; z < posV[i]; z++)
                nums[indx++] = i;
        }
        return nums;
    }
};