// class Solution {
// public:
//     string convertToTitle(int columnNumber) {
//         char arr[26];
//         for (int i = 0; i < 26; i++)
//             arr[i] = char('a' + i);
//         string res;
//         for(int i = 0; i < columnNumber / 26;i++)
//         {
//             res += toupper(arr[i]);
//         }
//         res += toupper(arr[columnNumber % 26]) ;
        

//         return res;
//     }
// };
// class Solution {
// public:
//     string convertToTitle(int columnNumber) {
//         char arr[26];
//         for (int i = 0; i < 26; i++)
//             arr[i] = char('A' + i);
//         string res;
//         for (int i = 0; i < columnNumber / 26; i++)
//         {
//             res += arr[i];
//         }
//         res += arr[(columnNumber % 26 )-1];


//         return res;
//     }
// }; 

// class Solution {
// public:
//     string convertToTitle(int columnNumber) {
//         char arr[26];
//         for (int i = 0; i < 26; i++)
//             arr[i] = char('A' + i);
//         string res;
//         int lastChar = (columnNumber % 26) - 1;
//         for (int i = 0; i < columnNumber / 26; i++)
//         {
//             res += arr[columnNumber / 26 -1];
//             columnNumber = columnNumber / 26;
//         }
//         res += arr[lastChar];


//         return res;
//     }
// }; 

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res;

        while (columnNumber > 0) {
            columnNumber--;  // adjust for 1-based indexing
            int remainder = columnNumber % 26;
            res += (char)('A' + remainder);
            columnNumber /= 26;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
