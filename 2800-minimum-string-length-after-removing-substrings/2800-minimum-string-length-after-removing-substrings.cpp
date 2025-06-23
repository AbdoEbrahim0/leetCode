//methode  1  O(N^2)    
//class Solution {
//public:
//    int minLength(string s) {
//        bool foundAB = false, foundCD = false;
//         unsigned int indx;
//        while (true)
//        {
//
//            if ( s.find ( "AB") != string ::npos ) 
//            {
//                indx = s.find("AB");
//                foundAB = true;
//                s.erase(s.begin() + indx);
//                s.erase(s.begin() + indx);
//            }
//            if (s.find("CD") != string::npos)
//            {
//                indx = s.find("CD");
//                foundCD = true;
//                s.erase(s.begin() + indx);
//                s.erase(s.begin() + indx );
//            }
//            if (!(foundAB || foundCD)) 
//                break;
//            foundAB = false;
//            foundCD = false;
//        }       
//        return s.size();
//    }
//};

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
// class Solution {
// public:
//     int minLength(string s) {
//         string stack = "";
//         stack += s[0];
//         for (int i = 1; i < s.size(); i++)
//         {
//             if (s[i] == 'B' && !stack.empty() && stack.back() == 'A')
//                         stack.pop_back();
//             else if (s[i] == 'D' && !stack.empty()&& stack.back() == 'C')
//                         stack.pop_back();
//             else
//                 stack += s[i];
//         }
//         return stack.size();
//     }
// };

//methode 1 [optimized^3]  O(N)   
// class Solution {
// public:
//     int minLength(string s) {
//         if (s.size() == 0) return 0;
//         int indx=0;
//         //string stk;
//         for (int i=0; i < s.size(); i++)
//         {
//             if (s[i]  == 'B' && indx >0 && s[indx-1] == 'A')
//             {
//                 indx--;
//             }
//             else if (s[i] == 'D' && indx > 0 && s[indx-1] == 'C')
//             {
//                 indx--;
//             }
//             else
//             {
//                 s[indx] = s[i];
//                 indx++;
//             }   
//         }
//         return indx;
//     }
// };

// class Solution {
// public:
//     int minLength(string s) {
//         stack<char>stk;
//         //if (s.size() == 1) return 1;
//         for (char val : s)
//         { 
//             if (val == 'D' && !stk.empty() && stk.top() == 'C')
//             {
//                         stk.pop();
//             }
//             else if (val == 'B' && !stk.empty() && stk.top() == 'A')
//                     {
//                           stk.pop();
//                     }
//             else
//                 stk.push(val);   
//         }
//         return stk.size();
//     }
// };
///////////////////////////// crack interview matb3a
class Solution {
public:
    int minLength(string s) {
        //string s = "ABFCACDB";
        //"ACBBD"
        string myS = "";
        for (int i = 0; i < s.size(); i++)
        {
            
            if (myS.size() && s[i] == 'B' && myS.back() == 'A')
            {
                //if()
                myS.pop_back();
                
            }
            
            else if (myS.size() && s[i] == 'D' && myS.back() == 'C')
            {
                //if()
                myS.pop_back();
                
            }
            else myS+=s[i];
        }
        return myS.size();
    }
};
