// class Solution {
// public:
//     vector<int> plusOne(vector<int>& digits) {
//         int power = 0;
        
//         int n = digits.size() - 1;
//         long long num = digits[n];
//         for (int i = n-1; i >= 0; i--)
//         {
//             num += (digits[i] * pow(10, ++power));
//         }
//         num++;
//         int s = log10(num) + 1;
//         vector<int> res(s);
        
//         while (num!=0)
//         {
//             res[--s] = num % 10;
//             num = num / 10;
//         }
//         return res;
//     }
// };

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() - 1;
        int carry = 1;
        for (int i = n; i >= 0; i--)
        {
            //{ 4, 3, 2, 1 }
            //{9,9,9,9}
            if (digits[i]+carry > 9)
            {
                digits[i] = 0;
            }
            else
            {
                carry = 0;
                digits[i]++;
                break;
            }
        }
        if (carry == 1)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};