class Solution {
public:
    int minBitFlips(int start, int goal) {
        if (start == 0 && goal == 0)return 0;
        int maxDigits = (start >= goal) ? ((int)log2(start)) + 1 : ((int)log2(goal)) + 1;

        //string s1(maxDigits, '0');
        //string s2(maxDigits, '0');
        int count = 0;
        char ch1, ch2;
        for (int i = maxDigits - 1; (start != 0) || (goal != 0); i--)
        {
            (start % 2) ? ch1 = '1' : ch1 = '0';
            start = start / 2;
            (goal % 2) ? ch2 = '1' : ch2 = '0';
            goal = goal / 2;
            if (ch1 != ch2)
                count++;
        }
        return count;
    }
};