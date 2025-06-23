class Solution {
public:
    string makeFancyString(string s) {

        int cnt = 1;
        //string s = "leeetcode";
        //           "aab"
        string myS = "";
        for (int i = 0; i < s.size(); i++)
        {
            while (i && s[i] == s[i - 1])
            {
                cnt++;
                i++;
            }
            if (i && i <= s.size() && cnt >= 2)
            {
                myS += s[i - 1];
            }
            if (i)
            myS += s[i - 1];

            if(i==s.size()-1)
                myS += s[i];
            cnt = 1;
        }
        return myS;
    }
};