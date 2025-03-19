//8.31 MB Beats 81.16%
// class Solution {
// public:
//     int minAddToMakeValid(string s) { 
//                int stk=0; //cntOpenWithClosed
//        int cnt_closedWithoutOpen = 0;
//        for (char c : s)
//        {
//            if (c == '(')
//                stk++;
//            else
//                if (stk )
//                {
//                    stk--;
//                }
//                else
//                {
//                    cnt_closedWithoutOpen++;
//                }
//        }
//        return stk + cnt_closedWithoutOpen;
//     }
// };

//methode  1  using stack optimized for memory & runtime
class Solution {
public:
   int minAddToMakeValid(string s) {
       int stk = 0; //cntOpenWithClosed
       int cnt_closedWithoutOpen = 0;
       for (char c : s)
       {
           (c == '(') ? stk++ : (stk)? stk--: cnt_closedWithoutOpen++;
       }
       return stk + cnt_closedWithoutOpen;
   }
};