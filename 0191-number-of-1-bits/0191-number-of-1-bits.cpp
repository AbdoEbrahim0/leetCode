// class Solution {
// public:
//     int hammingWeight(int n) {
//         int cnt = 0;
//         while (n!=0)
//         {
//             if (n & 1)
//                 cnt++;
//             n = n >> 1;
//         }      
//         return cnt;
//     }
// };
class Solution {
public:
    int hammingWeight(int n) {
        int cnt = 0;
        for (int i=0;i<32;i++)
        {
            //int  digit = (1 << i); //1 2 4 8 16 32 64 128
            
            if (n & (1 << i))  //128 =10000000   & 1=00000001   =0 
                            //128 =10000000   & 1=00000010   =0
                cnt++;   
        }
        
        return cnt;
    }
};