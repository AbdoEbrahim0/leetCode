//[optimized using LOG10]
// class Solution {
// public:
//     int findNumbers(vector<int>& nums) {
//         int EvenNumbersOfDigits=0;
//         for(int &val :nums)
//         {
//             if(int(log10(val) +1) %2==0)
//             EvenNumbersOfDigits++;
//             //cout<< log10(val)+1<< "|" <<val << "#\n";
//         }
//         return EvenNumbersOfDigits;
//     }
// };

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int EvenNumbersOfDigits=0;
        for(int &val :nums)
        {
        int digits=0;
        while (val !=0)
        {
        digits++;
        val/=10;
        }
        if(digits%2==0)
        EvenNumbersOfDigits++;
        }
        return EvenNumbersOfDigits;
    }
};
