class Solution {
public:
    int mySqrt(int x) {
        if(x==1)
        return 1;
        else if (x==0)
        return 0;
        int i;
        for ( i=0;i<= x/2;i++)
        {
        if (i>=46341 ||i*i > x)
        {
            break;
        }

        }
        return i-1;
    }
};