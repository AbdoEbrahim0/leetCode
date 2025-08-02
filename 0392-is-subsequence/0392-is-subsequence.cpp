
class Solution {
public:
    bool isSubsequence(string s, string t) {
        short i = 0;
        int tSize=t.size();
        for (char &ch : s)
        {   
            while (i <tSize  && ch != t[i])
            {
                i++;
            }
            if (ch != t[i])
                return false;
            i++;
        }
        return true;
    }
};