class Solution {
public:
    int addDigits(int num) {
        //int arr[32] = {};
        //int i = 0;
        int newNum = 0;
        while (num != 0)
        {
           // arr[i] = num % 10;
            newNum += num % 10;
            num = num / 10;
            //i++;
        }
        if (newNum / 10 == 0)
            return newNum;
        return addDigits(newNum);
    }
};