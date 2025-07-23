// class Solution {
// public:
//     bool wordPattern(string pattern, string s) {
       
//         unordered_map<char, string> charStringMap;
//         unordered_map<string,char> stringCharMap;
        
//         vector<string>vS;
//         string val="";
//         int sSize = s.size();
//         int i;
//         for (i= 0; i < sSize; i++)
//         {
//             if ( s[i] == ' ' || (i== sSize -1))
//             {
//                 if (i == sSize - 1)
//                     val += s[i];
//                 vS.emplace_back(val);
//                 val = "";
//             }else
//                 val += s[i];   
//         }
        
//          if (vS.size() != pattern.size() )
//             return false;
//         for (int i = 0; i < vS.size(); i++)
//         {
//             if (stringCharMap.count(vS[i]))
//             {
//                 if (stringCharMap[vS[i]] != pattern[i])
//                     return false;
//             }
//             else
//                 stringCharMap[vS[i]] = pattern[i];
//             ///-----------
//             if (charStringMap.count(pattern[i]))
//             {
//                 if (charStringMap[pattern[i]] != vS[i])
//                     return false;
//             }
//             else
//             charStringMap[pattern[i]] = vS[i];

//         }

//         return true;
//     }
// };
class Solution {
public:
    bool wordPattern(string pattern, string s) {
            unordered_map<string, int> words; 
            vector<string> word;
            unordered_map<char, string> keys;
            string s2;
            for(int i = 0;  i < s.size(); i ++){
                s2 = "";
                while(s[i] != ' ' && i < s.size()){
                    s2 += s[i];
                    i++;
                }
                word.push_back(s2);
            }

            if (word.size() != pattern.size() ) return 0;

            for(int i = 0;  i < word.size(); i ++){
                if (keys.count(pattern[i])) {
                    if(keys[pattern[i]] != word[i]) return 0;
                } else {
                    if(words[word[i]] >= 1){return  0;}
                    keys[pattern[i]] = word[i];
                    words[word[i]] += 1;
                }
            }
           
        return 1;
    }
};