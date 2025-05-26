class Solution {
public:
    int lengthOfLastWord(string s) {
        int  x =s.size() - 1;

        while (! ((s[x] >= 'a' && s[x] <= 'z') || (s[x] >= 'A' && s[x] <= 'Z')))
        {
            x--;
        }
        int ct = 0;
        for (int i = x ; i >= 0; i--)
        {
            if ((  (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')))
                ct++;
            else
                break;
        }
        // while (x >= 0 && isalpha(s[x])) {
        //     ct++;
        //     x--;
        // }
        return ct;
    }
};