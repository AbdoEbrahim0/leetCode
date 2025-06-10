// class Solution {
// public:
//     bool isPalindrome(string s) {
//         int n = s.size();
//         int st = 0;
//         int half = ceil(n / 2.0);
//         for (int i = n - 1; i >= 0; i--)
//         {
//         if(!isalpha(s[i]) && !isdigit(s[i]))
//             s.erase(s.begin() + i);
//         }
//         n = s.size();
//         for (int i = n - 1; i>=0 && st < half; )
//         {   
//             if (tolower(s[st]) != tolower(s[i]))
//                 return false;
//             st++;
//             i--;
//         }
//         return true;
//     }
// };

// class Solution {
// public:
//     bool isPalindrome(string s) {
//         int left = 0;
//         int right = s.size() - 1;
//         while (left < right) {
//             // Skip non-alphanumeric from the left
//             while (left < right && !isalnum(s[left])) {
//                 ++left;
//             }
//             // Skip non-alphanumeric from the right
//             while (left < right && !isalnum(s[right])) {
//                 --right;
//             }
//             // Compare characters (case-insensitive)
//             if (tolower(s[left]) != tolower(s[right])) {
//                 return false;
//             }
//             ++left;
//             --right;
//         }

//         return true;
//     }
// };

//wrong approach
// class Solution {
// public:
//     bool isPalindrome(string s) {
//         int n = s.size();
//         int st = 0;
//         int half = ceil(n / 2.0); 
//         n = s.size();
//         for (int i = n - 1; i > 0 && st < half; )
//         {
//             while (st < half && !isalnum(s[st]))
//             {
//                 st++;
//             }
//             while (i > 0 && !isalnum(s[i]))
//             {
//                 i--;
//             }
//             if (tolower(s[st]) != tolower(s[i]))
//             {
//                 return false;
//             }
//             st++;
//             i--;
//         }
//         return true;
//     }
// };
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            // Skip non-alphanumeric from the left
            while (left < right && !isalnum(s[left])) {
                ++left;
            }

            // Skip non-alphanumeric from the right
            while (left < right && !isalnum(s[right])) {
                --right;
            }

            // Compare characters (case-insensitive)
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            ++left;
            --right;
        }

        return true;
    }
};


// class Solution {
// public:
//     bool isPalindrome(string s) {
//         int n = s.size();
//         int st = 0;
//         int half = ceil(n / 2.0);
        
//         n = s.size();
//         for (int i = n - 1; i > 0 && st < half; )
//         {

//             while (st < half && !isalpha(s[st]) && !isdigit(s[st]))
//             {
//                 st++;
//             }
//             while (i > 0 && !isalpha(s[i]) && !isdigit(s[i]))
//             {
//                 i--;
//             }
//             int st2=0;
//             if (tolower(s[st]) != tolower(s[i]))
//             {
//              while(!isalpha(s[st2++]))
//              s.erase(s.begin()+i);
//              if(s.empty())
//                 return true;
//                 return false;
//             }
//             st++;
//             i--;
//         }
//         return true;
//     }
// };
