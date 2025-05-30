// 100% 61%
// class Solution {
// public:
//     //'(', ')', '{', '}', '[' and ']'
    
//     bool isValid(string s) {
//         stack<char> st;
//         for (char& ch : s)
//         {
//             if (ch == '(')
//             {
//                 st.push(ch);
//             }
//             else if (ch == ')')
//             {
//                 if (st.size() && st.top() == '(')
//                     st.pop();
//                 else
//                     return false;
//             }

//             if (ch == '{')
//             {
//                 st.push(ch);
//             }
//             else if (ch == '}')
//             {
//                 if (st.size() && st.top() == '{')
//                     st.pop();
//                 else
//                     return false;
//             }

//             if (ch == '[')
//             {
//                 st.push(ch);
//             }
//             else if (ch == ']')
//             {
//                 if ( st.size() && st.top() == '[')
//                     st.pop();
//                 else
//                     return false;
//             }
//         }
//         return 0 == st.size();
//     }
// };
//[optimized in logic and repeatestion]
// class Solution {
// public:
//     //'(', ')', '{', '}', '[' and ']'

//     bool isValid(string s) {
//         stack<char> st;
//         for (char& ch : s)
//         {
//             if (ch == '(' || ch == '{' || ch == '[')
//             {
//                 st.push(ch);
//             }

//             else if (ch == ')')
//             {
//                 if (st.size() && st.top() == '(')
//                     st.pop();
//                 else
//                     return false;
//             }
//             else if (ch == '}')
//             {
//                 if (st.size() && st.top() == '{')
//                     st.pop();
//                 else
//                     return false;
//             }
//             else if (ch == ']')
//             {
//                 if (st.size() && st.top() == '[')
//                     st.pop();
//                 else
//                     return false;
//             }
//         }
//         return 0 == st.size();
//     }
// };
//[optimized in logic and repeatestion]
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char ch : s) {
            if (ch == '(') st.push(')');
            else if (ch == '{') st.push('}');
            else if (ch == '[') st.push(']');
            else {
                if (st.empty() || st.top() != ch)
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
