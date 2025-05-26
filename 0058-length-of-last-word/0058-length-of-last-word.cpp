class Solution {
public:
    int lengthOfLastWord(string s) {
        int  x =s.size() - 1;

        while (! (isalpha(s[x])))
        {
            x--;
        }
        int ct = 0;
        for (int i = x ; i >= 0; i--)
        {
            if (( isalpha(s[i]) ))
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