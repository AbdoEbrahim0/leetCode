// class Solution {
// public:
//     string makeFancyString(string s) {

//         int cnt = 1;
//         //string s = "leeetcode";
//         //           "aab"
//         string myS = "";
//         int sSize = s.size();
//         for (int i = 0; i < sSize; i++)
//         {
//             while (i && s[i] == s[i - 1])
//             {
//                 cnt++;
//                 i++;
//             }
//             if (i && i <= sSize && cnt >= 2)
//             {
//                 myS += s[i - 1];
//             }
//             if (i)
//                 myS += s[i - 1];

//             if (i == sSize - 1)
//                 myS += s[i];
//             cnt = 1;
//         }
//         return myS;
//     }
// };

class Solution {
public:
    string makeFancyString(string s) {

        int cnt = 1;
        //string s = "leeetcode";
        //           "aab"
        string myS = "";
        int sSize = s.size();
        int i = 0;
        while (i < sSize)
        {
            if (i && s[i] == s[i - 1])
            {
                cnt++;
            }
            else 
            {
                cnt = 1;
            }
            if (i&& cnt < 3)
                myS += s[i - 1];
            i++;
        }
        myS += s.back();
        return myS;
    }
};