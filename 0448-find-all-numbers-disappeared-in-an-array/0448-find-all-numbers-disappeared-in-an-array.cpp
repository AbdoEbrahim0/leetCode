class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        set<int> mySet(nums.begin(), nums.end());
        
        vector<int>res;
        //4,3,2,7,8,2,3,1
        //1,2,3,4,7,8
        int n = nums.size();
        auto it =mySet.begin();
        for (int i = 1; i <= n; i++)
        {
            if (i != *(it))
                res.emplace_back(i);
            else
                it++;
        }
        return res;
    }
};