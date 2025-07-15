class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return 0;
        bool flag = true;
        while (n != 1 && flag)
        {
            if ((n / 3.0) != ceil(n / 3.0))
                flag = false;

            n = n / 3;
        }
        return flag;
    }
};