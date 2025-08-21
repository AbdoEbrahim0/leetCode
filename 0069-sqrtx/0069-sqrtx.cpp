// class Solution {
// public:
//     int mySqrt(int x) {
//         if(x==1)
//         return 1;
//         else if (x==0)
//         return 0;
//         int i;
//         for ( i=0;i<= x/2;i++)
//         {
//         if (i>=46341 ||i*i > x)
//         {
//             break;
//         }

//         }
//         return i-1;
//     }
// };

class Solution {
public:
    int mySqrt(int x) {
        if (x == 1)
            return 1;
        else if (x == 0)
            return 0;

        int st = 0, end = x / 2;
        long mid, cur;
        
            //if (st== 46341) break;
            long poweredBy2 ;
            while (st <= end)
            {
                mid = (st + end) / 2;
                 poweredBy2 = mid * mid;
                if (x ==  poweredBy2)
                return mid;
                if(poweredBy2 < x)
                {
                    cur = mid;
                    st = mid + 1;
                }
                else
                    end = mid - 1;
            }
        
        return cur;
    }
};