//wrong because you should remove firstly ab or ba with higher score  
// class Solution {
// public:
//     int maximumGain(string s, int x, int y) {
//         int gain = 0;
//         stack<char>stk;
//         for (char& ch : s)
//         {
//             if (stk.size()&& stk.top()=='a' && ch=='b')
//             {
//                 stk.pop();
//                 gain += x;
//             }
//             else if (stk.size()&& stk.top() == 'b' && ch == 'a')
//             {
//                 stk.pop();
//                 gain += y;
//             }else
//             stk.push(ch);
//         }
//         return gain;
//     }
// };

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int total = 0;
        stack<char> st;
        string temp = "";

        // First, remove the higher scoring pair
        char firstA, firstB;
        int firstVal, secondVal;

        if (x > y) {
            firstA = 'a'; firstB = 'b'; firstVal = x; secondVal = y;
        } else {
            firstA = 'b'; firstB = 'a'; firstVal = y; secondVal = x;
        }

        // First pass: remove first pair
        for (char c : s) {
            if (!st.empty() && st.top() == firstA && c == firstB) {
                st.pop();
                total += firstVal;
            } else {
                st.push(c);
            }
        }

        // Collect the remaining string from stack
        while (!st.empty()) {
            temp += st.top();
            st.pop();
        }
        reverse(temp.begin(), temp.end());

        // Second pass: remove second pair
        for (char c : temp) {
            if (!st.empty() && st.top() == firstB && c == firstA) {
                st.pop();
                total += secondVal;
            } else {
                st.push(c);
            }
        }

        return total;
    }
};
