#include<string>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int copyOfX = x;
        string str;
        int digit;
        while (x > 0)
        {
            digit = x % 10;
            str += to_string(digit);
            x = x / 10;
        }
        if (str.empty()) 
            str = "0";
        if (str ==to_string(copyOfX) )
            return true;
        else
            return false;

    }
};