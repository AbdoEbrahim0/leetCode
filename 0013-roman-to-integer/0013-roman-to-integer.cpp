

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, short>ump;
        ump['I'] = 1;
        ump['V'] = 5;
        ump['X'] = 10;
        ump['L'] = 50;
        ump['C'] = 100;
        ump['D'] = 500;
        ump['M'] = 1000;
        int res = 0;
        for (int i=0; i< s.size();i++)
        {//"MCMXCIV";
        //i=3 1890       //i=4 1990     //i=5 1989      //i=6 1994
            if (i + 1 < s.size() && ump[s[i]] < ump[s[i + 1]])
            {
                res += (-ump[s[i]]);
            }
            else
            res += ump[s[i]];
        }
        return res;
    }
};
//[optimized] using array faster in lookup than unordered map 
// class Solution {
// public:
//     int romanToInt(string s) {
//         //'A' 65; 'Z' 90;
//         int values[26] = {}; // Map 'A'-'Z' to 0-25
//         values['I' - 'A'] = 1;
//         values['V' - 'A'] = 5;
//         values['X' - 'A'] = 10;
//         values['L' - 'A'] = 50;
//         values['C' - 'A'] = 100;
//         values['D' - 'A'] = 500;
//         values['M' - 'A'] = 1000;

//         int res = 0;
//         for (int i = 0; i < s.size(); ++i) {
//             int curr = values[s[i] - 'A'];
//             int next = (i + 1 < s.size()) ? values[s[i + 1] - 'A'] : 0;
//             if (curr < next)
//                 res -= curr;
//             else
//                 res += curr;
//         }
//         return res;
//     }
// };
