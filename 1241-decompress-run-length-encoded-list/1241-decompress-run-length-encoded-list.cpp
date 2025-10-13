class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector <int> res;
        for(short i=0;i<nums.size();i+=2)
        {
                for(int j=0;j<nums[i];j++)
                res.emplace_back(nums[i+1]);

        } 
        return res;
    }
};