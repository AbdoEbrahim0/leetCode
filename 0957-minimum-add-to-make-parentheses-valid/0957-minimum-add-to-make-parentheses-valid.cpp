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
// class Solution {
// public:
//    int minAddToMakeValid(string s) {
//        int stk = 0; //cntOpenWithClosed
//        int cnt_closedWithoutOpen = 0;
//        for (char& c : s)
//        {
//            (c == '(') ? stk++ : (stk)? stk--: cnt_closedWithoutOpen++;
//        }
//        return stk + cnt_closedWithoutOpen;
//    }
// };

// class Solution {
// public:
//    int minAddToMakeValid(string s) {//fail in last cases
//        int counter = 0;
//        for (char c : s)
//        {
//            if (c == '(')
//                counter++;
//            else
//                counter--;
//        }
//        return abs(counter);
//    }
// };


//////////////////
// class Solution {
// public:
//     int minAddToMakeValid(string s) {//fail in last cases
//         //stack<char >stk; 
//         int stk = 0;
//         int cc = 0;
//         for (char& c : s)
//         {
//             if (c == '(')
//                 //stk.push(c);
//                 stk++;
//             else if (c == ')' && stk)
//                 //stk.pop();
//                 stk--;
//             else
//                 cc++;
//         }
//         return cc + stk;
//     }
// };

class Solution {
public:
    int minAddToMakeValid(string s) {//fail in last cases
        stack<char >stk; 
        
        int cc = 0;
        for (char& c : s)
        {
            if (c == '(')
                stk.push(c);
            else if (c == ')' && stk.size() && stk.top() == '(')
                stk.pop();
            else
                cc++;
        }
        return cc+ stk.size();
    }
};