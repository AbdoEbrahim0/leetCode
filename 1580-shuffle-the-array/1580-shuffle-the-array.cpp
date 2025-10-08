class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int size=nums.size();
        vector<int> res(n*2);
        int step=0;
        for(int z=0;z<n;z++)
        {
                res[step]=nums[z];
                step=step+2;
        }
            step=2*n -1;
        for(int z=2*n-1;z>=n;z--)
        {
                res[step]=nums[z];
                step=step-2;
        }
        return res;
    }
};