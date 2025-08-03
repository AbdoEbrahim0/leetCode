class Solution {
public:
    string addStrings(string num1, string num2) {
        int maxSize = max(num1.size(), num2.size());
        vector<short>arr1(maxSize);
        vector<short>arr2(maxSize);
        int copyofMaxSize = maxSize-1;
        for (int i = num1.size() - 1; i >= 0; i--)
        {
            arr1[copyofMaxSize--] = num1[i]-'0';
        }
        copyofMaxSize = maxSize-1;
        for (int j = num2.size() - 1; j >= 0; j--)
        {
            arr2[copyofMaxSize--] = num2[j]-'0';
        }
        string s = "";
        //num1 = "456", num2 = "77"
        int reminder = 0;
        int mod;
        for (int z = maxSize - 1; z >= 0; z--)
        {
            mod = (arr1[z] + arr2[z]) % 10;
            s +=  (mod + reminder)%10 + '0';
            if((mod + reminder) <10)
            {reminder = (arr1[z] + arr2[z]) / 10;}
            else 
            {reminder=1;}
           
        }
        if (reminder )
            s += '1';
        reverse(s.begin(), s.end());
        
        return s;
    }
};
//gpt
// class Solution {
// public:
//     string addStrings(string num1, string num2) {
//         int i = num1.size() - 1;
//         int j = num2.size() - 1;
//         int carry = 0;
//         string result = "";

//         while (i >= 0 || j >= 0 || carry) {
//             int digit1 = i >= 0 ? num1[i--] - '0' : 0;
//             int digit2 = j >= 0 ? num2[j--] - '0' : 0;
//             int sum = digit1 + digit2 + carry;
//             result += (sum % 10) + '0';
//             carry = sum / 10;
//         }

//         reverse(result.begin(), result.end());
//         return result;
//     }
// };
