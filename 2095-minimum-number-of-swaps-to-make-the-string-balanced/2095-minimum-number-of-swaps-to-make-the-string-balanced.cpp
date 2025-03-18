// class Solution {
// public:
//     int minSwaps(string s) {  
// int open = 0;//, problem = 0;
// for (int i = 0; i < s.size(); i++) {
//     if (s[i] == '[')
//         open++;
//     else {
//         if (open)
//             open--;
//        // else problem++;
//     }
// }
// return ceil((double)open/2);
//     }
// };

class Solution {
public:
    int minSwaps(string s) {  
int open = 0;
for (auto it : s)
 {
    if (it == '[')
        open++;
    else 
    if (open)
        open--;
        
}
return ceil((double)open/2);
    }
};
