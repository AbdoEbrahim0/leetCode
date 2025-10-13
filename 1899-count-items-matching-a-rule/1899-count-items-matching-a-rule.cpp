class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        string arr[3]={"type","color","name"};
        short  key_indx;
        for(short i=0;i<3;i++)
            if(ruleKey==arr[i])
                {key_indx=i;break;}
short cnt=0;
        for(vector<string> &v:items)
        {
            if(v[key_indx]==ruleValue)
                cnt++;
        }
return cnt;
    }
};