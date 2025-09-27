// //2,147,483,647
// //-2, 147, 483, 648

//wrong approach
// class Solution {
// public:
// int maxInt[10]={2,1,4,7,4,8,3,6,4,7};
// int minInt[10]={-2,-1,-4,-7,-4,-8,-3,-6,-4,-8};
//     int reverse(int x) {
// int res=0;
// bool postive=true;
// if (x<0)postive=false;
// int power;    
//     if(x==0) 
//     power=1;
//     else
//     {
// int cnt=0;
// int copyOfX=x;
// while(copyOfX!=0)
//         {
//         cnt++;
//         copyOfX=copyOfX/10;
//         }
//         power= cnt;
//     }

//     for(int i=0;i<10 && x!=0;i++)
//     {
//         cout<<x%10<<endl;
//         if(postive && (x%10) <=maxInt[i])
//         res+=(x%10)*pow(10,power--);
//         else if(!postive && (x%10) >=minInt[i])
//         res+=(x%10)*pow(10,power--);
//         else 
//             return 0;
//             x=x/10;
//     }

// return res;
//     }
// };


class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x != 0) {
            int digit = x % 10;
            x /= 10;

            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > 7)) return 0;
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && digit < -8)) return 0;

            res = res * 10 + digit;
        }
        return res;
    }
};
