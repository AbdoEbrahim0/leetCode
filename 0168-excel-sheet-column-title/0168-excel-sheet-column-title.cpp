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

class Solution {
public:
    string convertToTitle(int columnNumber) {
        char arr[26];
        for (int i = 0; i < 26; i++)
            arr[i] = char('A' + i);
        string res;
        //int lastChar = (columnNumber % 26) - 1;
        while ( columnNumber >26)
        {
            // if((columnNumber % 26) -1 <0)
            // res+='Z';
            // else
            res += arr[(--columnNumber) % 26 ];
            columnNumber = columnNumber / 26.0;
        }
        res += arr[columnNumber-1];
        // to produce result at coulmn number =2147483647  out :"FXSHRXW"
        //2147483647%26=23 arr[23-1]=W
        //82,595,524.884615384615384615384615  82,595,524%26=24 arr[24-1]=X   not valid >>> 82,595,524+1 %26 =25 arr[25-1]=Y
        reverse(res.begin(), res.end());
        return res;
            // 1>>A
    // 28>>AB
    // 701>>ZY    
    // 52>>AZ
    }
}; 