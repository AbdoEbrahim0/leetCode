class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() !=t.size())
        return false;
        int vis1[26]={};
        int vis2[26]={};
        

        for(int i=0;i<s.size();i++)
        {
            vis1[s[i]-'a'] ++;
            vis2[t[i]-'a'] ++;
        }

        for(short i=0;i<26;i++)
        {
            if (vis1[i]!= vis2[i])
            return false;
        }
        return true;
    }
};