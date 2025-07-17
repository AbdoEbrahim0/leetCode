// O(N)
// class Solution {
// public:
//     vector<int> countBits(int n) {
//         vector<int> res;
//         for (int i = 0; i <= n; i++)
//         {
//             int cnt = 0;
//             int copyOfI = i;
//             for (int x = 0; i>0 && x < 32 ; x++)
//             {
//                 //int z = (1 << x); //MEM care
//                 if (i & (1 << x) )
//                     cnt++;
//                 copyOfI = (copyOfI >> 1);
//             }
//             res.emplace_back(cnt);
//         }
//         return res;
//     }
// };
// Optimized ^2 in MEM O(N)
// class Solution {
// public:
//     vector<int> countBits(int n) {
//         vector<int> res;
//         for (int i = 0; i <= n; i++) //O(N)
//         {
//             bitset<32>bits(i);   
//             res.emplace_back(bits.count());
//         }
//         return res;
//     }
// };
// Optimized ^3 in time & MEM O(N) dynamic programming [Memoization] approach
/*
//res[0]=0 //base case
0    000  
1    001
res[1]=res[1>>1 =0] +(1&1) =0 + 1 =1                       
2    010
res[2]=res[2>>1 =1] +(2&1) =1 + (10 & 01 ))  =0 + 1=1
3    011
res[3]=res[3>>1 =2] +(3&1) =1 + (11 & 01 ))  =1 + 1=2
4    100
res[4]=res[4>>1 =2] +(4&1) =1 + (100 & 001)) =1 + 0=1
5    101 
res[5]=res[5>>1 =2] +(5&1) =1 + (101 & 001)) =1 + 1=2
*/
class Solution {
public:

    vector<int> countBits(int n) {
        vector<int> res(n + 1);
        res[0] = 0; // base case
        for (int i = 1; i <= n; ++i) {
            res[i] = res[i >> 1] + (i & 1);
        }
        return res;
    }
};
