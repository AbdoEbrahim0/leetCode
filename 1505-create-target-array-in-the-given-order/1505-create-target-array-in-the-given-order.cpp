class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> v;
        for (signed char z = 0; z < index.size(); z++)
        {
            v.insert(v.begin() + index[z] ,nums[z]);
        }
        return v;
    }
};