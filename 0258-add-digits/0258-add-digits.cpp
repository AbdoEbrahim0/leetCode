class Solution {
public:
    int addDigits(int num) {
        int newNum = 0;
        while (num != 0)
        {
            newNum += num % 10;
            num = num / 10;
        }
        if (newNum / 10 == 0)
            return newNum;
        return addDigits(newNum);
    }
};