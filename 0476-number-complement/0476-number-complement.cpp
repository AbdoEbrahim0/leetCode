// class Solution {
// public:
//     int findComplement(int num) {
//         int x=0;
//         int power = 0;
//         while (num != 0)
//         {
//             if (num % 2 ==0)
//             {
//              //   x += pow(2, power); 
//              //Or 
//                 x += 1<< power;
//             }
//             num = num / 2;
//             power++;
//         }
//         return x;
//     }
// };

//cout << (5 & (1<<2)); 5& 2^2 
//101
//100
//out : 100
//if even fasle then set the bit to 1
//if odd true then set the bit to 0 
// class Solution {
// public:
//     int findComplement(int num) {
//         if (num == 0) return 1;
//         int howManyDigits;//log base 2 beacuse we need digits in Bin if we want digits in decimal use log10
//             howManyDigits = floor(log2(num)) + 1;; //last added 1 for ceiling;
//         for (int i = 0; i < howManyDigits; i++)
//         {
//             if (num & (1<<i))  //if digit is 1 true then set the bit to 0 
//                 num &= ~(1 << i);
//             else            //if digit is 0 fasle then set the bit to 1
//                 num |= (1 << i);
//         }
//         return num;
//     }
// };

// class Solution {
// public:
//     int findComplement(int num) {
//         if (num == 0) return 1;
//         for (int i = 0; i < 31; i++)
//         {
//             if (num & (1<<i))  //if digit is 1 true then set the bit to 0 
//                 num &= ~(1 << i);
//             else            //if digit is 0 fasle then set the bit to 1
//                 num |= (1 << i);
//         }
//         return num;
//     }
// };

// class Solution {
// public:
//     int findComplement(int num) {
//         if (num == 0) return 1;
//         for (int i = 0; i < 31 && num>= (1<<i); i++)
//         {
//             if (num & (1 << i))  //if digit is 1 true then set the bit to 0 
//                 num &= ~(1 << i);
//             else            //if digit is 0 fasle then set the bit to 1
//                 num |= (1 << i);
//         }
//         return num;
//     }
// };

class Solution {
 public:
     int findComplement(int num) {
         //8->  1000
         //16-> 10000
         unsigned int maxi= (log2(num)) + 1;   //4 digits  //8->  1000
         maxi =(1<< maxi); //make it 5digits 
         return (num ^ (maxi - 1));
     }
 };