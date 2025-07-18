class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // if (s.size() != t.size())
        //     return false;
        unordered_map<char,char> m1;
        unordered_set<char> appearAgain;
        for (int i=0;i< s.size();i++)
        {
            if (m1.count(s[i]))
            {
                if (m1[s[i]] != t[i])
                    return false;
            }
            else
            {
                //s ="badc", t ="baba";
                if (appearAgain.count(t[i]))
                    return false;
                m1[s[i]] = t[i];
                appearAgain.insert(t[i]);
            }
        }
        return true;
    }
};

//optimizd ^2

// class Solution {
// public:
//     bool isIsomorphic(string s, string t) {
//         if (s.length() != t.length()) return false;
//         unordered_map<char, char> mapST, mapTS;
//         for (int i = 0; i < s.length(); ++i) {
//             char c1 = s[i];
//             char c2 = t[i];
//             // Check s → t mapping
//             if (mapST.count(c1) && mapST[c1] != c2) return false;
//             // Check t → s mapping
//             if (mapTS.count(c2) && mapTS[c2] != c1) return false;
//             mapST[c1] = c2;
//             mapTS[c2] = c1;
//         }

//         return true;
//     }
// };
