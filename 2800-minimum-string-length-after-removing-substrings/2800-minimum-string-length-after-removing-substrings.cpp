//methode 1 [optimized]  O(N)   
// class Solution {
// public:
//     int minLength(string s) {
//         string stack = "";
//             stack+=s[0];
//         for (int i=1 ; i<s.size();i++)
//         {
//             if (s[i] == 'B')
//             {
//                 if (!stack.empty())
//                 {
//                     if (stack[stack.size() - 1] != 'A')
//                     {
//                         stack += s[i];
//                     }
//                     else
//                         stack.pop_back();       
//                 }else 
//                 stack += s[i];
//             }
//             else if (s[i] == 'D')
//                 {
//                     if (!stack.empty() )
//                     {
//                         if (stack[stack.size() - 1] != 'C')
//                         {
//                             stack += s[i];
//                         }
//                         else
//                             stack.pop_back();       
//                     }else 
//                         stack += s[i];
//                 }
//             else
//             {
//                 stack += s[i];
//             }    
//         }
//         return stack.size();
//     }
// }; 
//methode 1 [optimized^2]  O(N)   
class Solution {
public:
    int minLength(string s) {
        string stack = "";
        stack += s[0];
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == 'B' && !stack.empty() && stack.back() == 'A')
                        stack.pop_back();
            else if (s[i] == 'D' && !stack.empty()&& stack.back() == 'C')
                        stack.pop_back();
            else
                stack += s[i];
        }
        return stack.size();
    }
};