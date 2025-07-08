// 1>>A
// 28>>AB
// 701>>ZY    
// 52>>AZ
  
//2147483647 >>"FXSHRXW"
//2147483647%26=23 arr[23-1]=W
//82,595,524.884615384615384615384615  82,595,524%26=24 arr[24-1]=X 
//  not valid >>> 82,595,524+1 %26 =25 arr[25-1]=Y

// class Solution {
// public:
//     string convertToTitle(int columnNumber) {
//         char arr[26];
//         for (int i = 0; i < 26; i++)
//             arr[i] = char('A' + i);
//         string res;
//         while ( columnNumber >26)
//         {
//             res += arr[(--columnNumber) % 26 ];//decrement to as our array 0 based
//                         columnNumber = columnNumber / 26;
//         }
//         res += arr[columnNumber-1];
//         reverse(res.begin(), res.end());
//         return res;
//     }
// }; 


class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res;
        while ( columnNumber >0)
        {
           short reminder= (--columnNumber)% 26;
            res +=char('A'+reminder);//decrement to as our array 0 based
            columnNumber = columnNumber / 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
}; 