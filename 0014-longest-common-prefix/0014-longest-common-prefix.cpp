class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string res="";
        
        int smallestSize = strs[0].size();
        for (string val : strs)
        {
            smallestSize = min(smallestSize,(int)val.size());
        }
        for (int x = 0; x <smallestSize;)
            {
            int val = 0;
            int cnt = 1;
            while (val < n - 1 && x < smallestSize && strs[val][x] == strs[1 + val][x])
            {
                cnt++;
                val++;
            }
             
            if (cnt == n)
                res = res+ strs[val][x];
            else 
            break;
            x++;
            }
            return res;
    }
};