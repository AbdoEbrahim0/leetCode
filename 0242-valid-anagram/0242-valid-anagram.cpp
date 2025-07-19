// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if (s.size() != t.size())
//             return false;
//         short arrS[26] = {};
//         short arrT[26] = {};
//         for (int i = 0; i < s.size(); i++)
//         {
//             arrS[s[i] - 'a']++;
//             arrT[t[i] - 'a']++;
//         }
//         for (int i = 0; i <26; i++)
//         {
//             if (arrS[i] != arrT[i])
//                 return false;
//         }
//         return true;
//     }
// };
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        int count[26] = {};
        for (int i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) return false;
        }
        return true;
    }
};


// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if (s.size() != t.size())
//             return false;
//         bitset<26>arrS;
//         bitset<26>arrT;
//         //short arrS[26] = {};
//         //short arrT[26] = {};
//         for (int i = 0; i < s.size(); i++)
//         {
//             arrS[s[i] - 'a']=~arrS[s[i] - 'a'];
//             arrT[t[i] - 'a']= ~arrT[t[i] - 'a'];
//         }
//         for (int i = 0; i <26; i++) //O(1)
//         {
//             if (arrS[i] != arrT[i])
//                 return false;
//         }
//         return true;
//     }
// };