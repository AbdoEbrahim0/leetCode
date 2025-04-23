class Solution {
public:
    int minBitFlips(int start, int goal) {
        if (start==0 && goal==0)return 0;
        int maxDigits = (start >= goal) ? ((int)log2(start)) : ((int)log2(goal));
        int count = 0;
        char ch1, ch2;
        for (int i = maxDigits; (start != 0) || (goal != 0); i--)
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