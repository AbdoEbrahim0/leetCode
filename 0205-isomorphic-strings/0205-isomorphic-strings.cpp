// class Solution {
// public:
//     bool isIsomorphic(string s, string t) {
//         if (s.size() != t.size())
//             return false;
//         unordered_map<char,char> m1;
//         unordered_map<char, bool> appearAgain;
//         for (int i=0;i< s.size();i++)
//         {
//             if (m1.find(s[i]) != m1.end())
//             {
//                 if (m1[s[i]] != t[i])
//                 {
//                 if(appearAgain[s[i]] ==false)
//                     return false;
//                 }
                
//             }
//             else
//             {
//                 m1[s[i]] = t[i];
//                 appearAgain[t[i]] = true;
//             }
            
//         }
//         return true;

//     }
// };

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // if (s.size() != t.size())
        //     return false;
        unordered_map<char,char> m1;
        unordered_map<char, bool> appearAgain;
        for (int i=0;i< s.size();i++)
        {
            if (m1.find(s[i]) != m1.end())
            {
                if (m1[s[i]] != t[i])
                    return false;
            }
            else
            {
                if (appearAgain.find(t[i]) != appearAgain.end())
                    return false;
                m1[s[i]] = t[i];
                appearAgain[t[i]] = true;
            }
        }
        return true;

    }
};



















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
