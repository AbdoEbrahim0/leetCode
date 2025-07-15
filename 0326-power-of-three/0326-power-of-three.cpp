//O(N/3) =N
// class Solution {
// public:
//     bool isPowerOfThree(int n) {
//     if (n <= 0) return 0;
//         bool flag = true;
//         while (n != 1 && flag)
//         {
//             if ((n / 3.0) != ceil(n / 3.0))
//                 flag = false;

//             n = n / 3;
//         }
//         return flag;
//     }
// };

//optimized^2 in MEM and time
// class Solution {
// public:
//     bool isPowerOfThree(int n) {
//         if (n <= 0) return false;
//         while (n > 1) {
//                 if (n % 3 != 0) 
//                 return false;
//                 n /= 3;
//                     }
// return n == 1;

//     }
// };
// time: O(1) optimized^3 in MEM and time constant Math trick
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
};



