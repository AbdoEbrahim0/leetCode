class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        short n=strs.size();
        string res="";
        short smallestSize = strs[0].size();
        
        for (string val : strs)
        {
            smallestSize = min((int)smallestSize,(int)val.size());
        }
        short val;
        short cnt;
        for (int x = 0; x <smallestSize;)
            {
             val = 0;
             cnt = 1;
            while (val < n - 1 && x < smallestSize && strs[val][x] == strs[1 + val][x])
            {
                cnt++;
                val++;
            }
            if (cnt == n)
                res = res+ strs[val][x];
            else break; 
            x++;
            }
            return res;
    }
};