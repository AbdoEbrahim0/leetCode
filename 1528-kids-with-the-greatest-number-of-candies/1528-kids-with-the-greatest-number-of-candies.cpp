class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxElement=*max_element(candies.begin(),candies.end());
        vector<bool> res;
        for(int var:candies)
        {
                if(var+extraCandies>=maxElement)
                res.emplace_back(1);
                else
                res.emplace_back(0);
        }
        return res;
    }
};