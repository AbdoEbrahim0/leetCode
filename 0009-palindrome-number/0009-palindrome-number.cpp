#include<string>
using namespace std;
//methode 1
// class Solution {
// public:
//     bool isPalindrome(int x) {
//         if (x < 0) return false;
//         int copyOfX = x;
//         string str="";
//         int digit;
//         while (x > 0)
//         {
//             digit = x % 10;
//             str += to_string(digit);
//             x = x / 10;
//         }
//         if (str.empty()) 
//             str = "0";
//         if (str ==to_string(copyOfX) )
//             return true;
//         else
//             return false;

//     }
// };
//methode 2
// class Solution {
// public:
//     bool isPalindrome(int x) {
//         if (x < 0) return false;
//         if (x ==0) return true;   
//         int copyOfX = x;
//         int how_many_digits = log10(x) +1;     
//         unsigned  long long reversedNum=0;
//         while (how_many_digits !=0)
//         {
//             reversedNum = reversedNum + (x % 10)*pow(10, --how_many_digits);
//             x = x / 10;
//         }
//         if (reversedNum==copyOfX )
//             return true;
//         else
//             return false;
//     }
// };
//methode 2 [optimized]
 class Solution {
 public:
     bool isPalindrome(int x) {
         if (x < 0) return false;
         if (x ==0) return true;   
         int how_many_digits = log10(x) +1;
         int hundreds= pow(10, how_many_digits -1);
         int f_digit = x / hundreds;
         int numAfterRemoveF_d=x;
         while (true) 
         {
             //hundreds = pow(10, --how_many_digits);//100
             if (x % 10 != (int)(f_digit))
                 return false;
             numAfterRemoveF_d = (numAfterRemoveF_d - (numAfterRemoveF_d / hundreds) * hundreds);//121 - (121/100) *100 =121-1*100=21
             if (hundreds == 1) break;
             hundreds /= 10;
             f_digit = (numAfterRemoveF_d) / (hundreds);//2
             x = x / 10;
         }
             return true;
     }
 };
//method 2 [optimized]
// class Solution {
// public:
//     bool isPalindrome(int x) {
//         if (x < 0) return false; 
//         string str = to_string(x);
//         int digit;
//         int indx = 0;
//         while (x>0)
//         {
//             digit =(x % 10);
//             if (digit != (str[indx++] - '0'))
//                 return false;
//             x = x / 10;
//         }
//             return true;
//     }
// };  