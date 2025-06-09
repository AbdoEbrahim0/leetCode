class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int st = 0;
        int half = ceil(n / 2.0);
        for (int i = n - 1; i >= 0; i--)
        {
        if(!isalpha(s[i]) && !isdigit(s[i]))
            s.erase(s.begin() + i);
        }
        n = s.size();
        for (int i = n - 1; i>=0 && st < half; )
        {
            
            if (s.empty())
                return true;
            if (tolower(s[st]) != tolower(s[i]))
                return false;
            st++;
            i--;
        }
        return true;
    }
};
