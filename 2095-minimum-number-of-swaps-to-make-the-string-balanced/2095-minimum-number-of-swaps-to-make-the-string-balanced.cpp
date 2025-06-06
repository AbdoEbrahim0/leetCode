//method 1 
// class Solution {
// public:
//     int minSwaps(string s) {
//         //note that it is guranteed to be couple number not individual
//         //][][ 
//         //if (s.empty()) return true;
//         stack<char>stk;
//         int counter = 0;
//         for (auto& it : s) //4/2 =2 //[0],[0+2]  
//         {
//             if (it == '[') stk.push(it);
//             else
//             {
//                 if (stk.size())
//                     stk.pop();
//                 //else counter--;       
//             }
//         }
//         counter = stk.size();
//         return ceil(counter / 2.0);
//     }
// };
//method 1 [optimized]
// class Solution {
// public:
//     int minSwaps(string s) {  
// int  open = 0;
// for (auto & it : s)
//  {
//     if (it == '[')
//         open++;
//     else 
//     //if (open) // use this if to pass this test :"][]["
//         open--;
        
// }
// return ceil((double)open/2);
//     }
// };

// class Solution {
// public:
//     int minSwaps(string s) {
        
//         //stack<char>stk;
//         int counter =0;
//         for (auto & c : s)
//         {
//             if (c == '[')
//                 //stk.push(c);
//                 counter++;
//             else if
//                 (c == ']' && counter>0)
//                 //if(stk.size())
//                 //stk.pop();
//                 counter--;
//         }
//         return ceil(counter / 2.0);
//     }
// };

///////////////
class Solution {
public:
    int minSwaps(string s) {
        //stack<char>stk;
        int counter = 0;
        for (char &c: s)
        {
            if (c == '[')
                counter ++;
            else if (counter && c == ']')
                counter --;
            
        }
        return ceil( (counter) /2.0);
    }
};
