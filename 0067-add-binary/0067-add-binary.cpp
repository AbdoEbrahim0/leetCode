// class Solution {
// public:
//     string addBinary(string a, string b) {
//         string result;
//         int i = a.size() - 1;
//         int j = b.size() - 1;
//         int carry = 0;

//         while (i >= 0 || j >= 0 || carry) {
//             int sum = carry;

//             if (i >= 0) sum += a[i--] - '0';
//             if (j >= 0) sum += b[j--] - '0';

//             result += (sum % 2) + '0';
//             carry = sum / 2;
//         }

//         reverse(result.begin(), result.end());
//         return result;
//     }
// };
//optimized sol ignore rest of string if it is longer
class Solution {
public:
    string addBinary(string a, string b) {
        
        
        int carry = 0;
        if (!(a.size() > b.size()))
            swap(a, b);
        string result = a;
        int i = a.size() - 1;
        int j = b.size() - 1;
        short sum;
        //    "100"              100
        // "110010"           110010
        //expected "110110"   110110
        while (i >= 0 && j >= 0 || (i >= 0 && carry)  || (j >= 0 && carry) ) {
            sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            result[1+i]= (sum % 2) + '0';
            carry = sum / 2;
        }
        if ((a[0] - '0' & b[0] - '0' & carry) || (b[0] - '0' & carry) || (a[0] - '0' & carry))
            result.insert(result.begin(), '1');

        //reverse(result.begin(), result.end());
        return result;
    }
};