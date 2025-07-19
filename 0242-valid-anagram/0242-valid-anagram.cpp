class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        short arrS[26] = {};
        short arrT[26] = {};
        for (int i = 0; i < s.size(); i++)
        {
            arrS[s[i] - 'a']++;
            arrT[t[i] - 'a']++;
        }
        for (int i = 0; i <26; i++)
        {
            if (arrS[i] != arrT[i])
                return false;
        }
        return true;
    }
};