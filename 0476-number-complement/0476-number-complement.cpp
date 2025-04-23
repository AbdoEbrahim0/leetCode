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
class Solution {
public:
    int findComplement(int num) {
        if (num == 0) return 1;
        int howManyDigits;
            howManyDigits = floor(log2(num)) + 1;; //last added 1 for ceiling;
    //cout << howManyDigits;//3
        for (int i = 0; i < howManyDigits; i++)
        {
            if (num & (1<<i))  //if digit is 1 true then set the bit to 0 
                num &= ~(1 << i);
            else            //if digit is 0 fasle then set the bit to 1
                num |= (1 << i);
        }
        return num;
    }
};