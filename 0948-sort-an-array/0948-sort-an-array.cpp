class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        
        priority_queue<int>pr(nums.begin(), nums.end());;
        int x=nums.size()-1;
        while (pr.size())
        {
            nums[x--] = pr.top();
            pr.pop();
            
        }
        return nums;
    }
};