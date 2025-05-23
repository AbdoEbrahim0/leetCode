// value of vector >> key 
//  [state]        >> indx
class Solution {
public:
    int findTheLongestSubstring(string s) {
        bool checkCharVowel[26] = {};
        for (char ch : std::string("aeiou"))
        {
            checkCharVowel[ch - 'a'] = true;
        }
        int ans = 0;
        vector<bool> vis(26) ;
        map<vector< bool>, int>mp;
        mp[vis] = -1;
        
        
        for (int j = 0; j < s.size(); j++)
        {
            if (checkCharVowel[s[j] - 'a'])//flip current digit if vowel
            {
                int idx = s[j] - 'a';
                vis[idx] = !vis[idx];
            }
            
            if  (mp.find(vis) == mp.end())//if state  not exist store the new state in map
                mp[vis] = j;
            else
            {
                ans = max(ans, j - mp[vis]);
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     int findTheLongestSubstring(string s) {
//         int occuranceOFVowels[26] = {};
//         bool checkCharVowel[26] = {};
//         for (char ch : s)
//         {
//             if (ch == 'a' || ch == 'o' || ch == 'i' || ch == 'e' || ch == 'u')
//             {
//                 occuranceOFVowels[ch - 'a']++;
//                 checkCharVowel[ch - 'a'] = true;
//             }
//         }
//         int LongestSubString = 0;
//         int len = 0;//a=97 e=101 i=105 o=111 u=117  a=0 e =4 i=8 o =14 u=20
//         string subString = "";
//         for (char ch : s)
//         {
//             if ( (subString.size() )   ||  ( occuranceOFVowels[0] >= 2 || occuranceOFVowels[4] >= 2 || occuranceOFVowels[8] >= 2 ||
//                 occuranceOFVowels[14] >= 2 || occuranceOFVowels[20] >= 2 ))
//             {
//                         if (checkCharVowel[ch - 'a'] == false)
//                         {
//                             //len++;
//                             subString += ch;
//                         }
//                         else if (checkCharVowel[ch - 'a'])
//                         {
//                             //len++;
//                             subString += ch;
//                             occuranceOFVowels[ch - 'a']--;
//                             if (occuranceOFVowels[ch - 'a'] == 0)
//                             {
//                                 LongestSubString = max(LongestSubString, ((int)subString.size() - 1)); //dont take it
//                                 //LongestSubString = max(LongestSubString, (len-1)); //dont take it
//                                 //len = 0;
//                                 if(!( 
//                                     (occuranceOFVowels[0] >= 2 || occuranceOFVowels[4] >= 2 
//                                     || occuranceOFVowels[8] >= 2 ||occuranceOFVowels[14] >= 2
//                                     || occuranceOFVowels[20] >= 2)))
//                                         {subString = "";}
//                             }
//                         }
//             }
//             else
//                 break;
//             //                LongestSubString = max(LongestSubString, len);
//             LongestSubString = max(LongestSubString, (int)subString.size());             
//         }
//         return LongestSubString;
//     }
// };

// class Solution {
// public:
//     int findTheLongestSubstring(string s) {
//         bool checkCharVowel[26] = {};
//         for (char ch : std::string("aeiou"))
//         {
//                 checkCharVowel[ch - 'a'] = true;   
//         }
//         int mask = 0;
        
//         map<int, int>mp;
//         mp[mask] = -1;
//         int ans = 0;
//         for (int j = 0; j < s.size(); j++)
//         {
//             if (checkCharVowel[s[j] - 'a'])
//             {
//                 int idx = s[j] - 'a';
//                 mask ^= (1 << idx);
//             }
//             if (mp.find(mask) == mp.end())
//                 mp[mask]=j;
//             else
//             {
//                 ans = max(ans, j - mp[mask]);
//             }
//         }
//         return ans;
//     }
// };

