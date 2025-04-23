// class Solution {
// public:
//     int minBitFlips(int start, int goal) {
//         if (start==0 && goal==0)return 0;
//         int maxDigits = (start >= goal) ? ((int)log2(start)) : ((int)log2(goal));
//         int count = 0;
//         char ch1, ch2;
//         for (int i = maxDigits; (start != 0) || (goal != 0); i--)
//         {
//             (start % 2) ? ch1 = '1' : ch1 = '0';
//             start = start / 2;
//             (goal % 2) ? ch2 = '1' : ch2 = '0';
//             goal = goal / 2;
//             if (ch1 != ch2)
//                 count++;
//         }
//         return count;
//     }
// };

// class Solution {
// public:
//     int minBitFlips(int start, int goal) {
//         int res = start ^ goal;
//         int counter = 0;
//         while (res!=0)
//         {
//             // if (res % 2)
//             //     counter++;
//             //res = res / 2; 
//             //OR shift right to divise by 2
//             if(res &1)
//             counter++;
//             res = res >>1;;  
//         }
//         return counter;
//     }
// };

class Solution {
public:
    int minBitFlips(int start, int goal) {
        
        int counter = 0;
        while (start || goal)
        {
            if ((start & 1) != (goal & 1))
                counter++;
            start=start >> 1;
                goal=goal >> 1;
        }
        return counter;
    }
};