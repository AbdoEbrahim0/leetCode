class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int Maxi=0;
        for(vector<int> v:accounts)
        {
            int currentWealth= accumulate(v.begin(),v.end(),0);
            if(currentWealth> Maxi)
            Maxi=currentWealth;
        }
        return Maxi;
    }
};