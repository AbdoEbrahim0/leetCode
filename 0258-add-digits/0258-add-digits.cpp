class Solution {
public:
int solve(int & num)
{
int newNum = 0;
        while (num != 0)
        {
            newNum += num % 10;
            num = num / 10;
        }
        if (newNum / 10 == 0)
            return newNum;

        return solve(newNum);

}
    int addDigits(int num) {
        return solve(num);
    }
};