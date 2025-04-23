class Solution {
public:
    int minBitFlips(int start, int goal) {
        if (start == 0 && goal == 0)return 0;
        int maxDigits = (start >= goal) ? ((int)log2(start) ) +1: ((int)log2(goal)) + 1;
        
        string s1(maxDigits, '0');
        string s2(maxDigits, '0');
        for(int i= maxDigits -1 ; (start != 0) || (goal != 0);i--)
        {
             (start % 2) ? s1[i] = '1': s1[i] = '0';
                start = start / 2;
             (goal % 2) ? s2[i] = '1' : s2[i] = '0';
                goal = goal / 2;
        }
        int count=0;
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] != s2[i])
                count++;
        }
        return count;
    }
};
