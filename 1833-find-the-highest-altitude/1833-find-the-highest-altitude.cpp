class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int MaxAltitude=0;
        int res=0;
        for(int &val :gain)
        {
            res+=val;
            if(res>MaxAltitude)
            MaxAltitude=res;
        }
        return MaxAltitude;
    }
};