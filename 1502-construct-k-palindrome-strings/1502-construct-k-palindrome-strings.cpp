// class Solution {
// public:
//     bool canConstruct(string s, int k) {
//         short arr[26];
//         bool term1, term2;
//         int valid=0;
//         for (char c : s)
//         {
//             arr[c - 'a']++;
//             if (arr[c - 'a'] == k && !term1)
//                 term1 = true;
//             else if (arr[c - 'a'] == k && !term2)
//                 term2 = true;
//             else
//                 return true;
//         }
//         return false;
//     }
// };
/*
"annabelle"  "leetcode"    "true"   "annabezxlee"k=12 "annabezxlee"k=11    "annabezxxlee"k=12   "annabezxxllee" k=13 "annabezxxllee" k=14
 112211122    11211113      1111     11221111123       11221111123          112211112123         1122111121223        1122111121223 
expected        false       true        false             true                  true                 true                 fasle
*/  
// class Solution {
// public:
//     bool canConstruct(string s, int k) {
//         if (k>s.size())
//         return false;
//         short arr[26];

//         int valid = 0;
//         for (char c : s)
//         {
//             arr[c - 'a']++;
//             if(arr[c - 'a']==2- )
//             return true;
//         }
//         valid = 0;
//         for (int i = 0; i < 26; i++)//count 1's 
//         {
//             if (arr[i] == 1)
//                 valid++;
//         }
//         if (valid == s.size() && valid==k)
//             return true;
//         return false;
//     }
// };

// class Solution {
// public:
//     bool canConstruct(string s, int k) {
//         if (k>s.size())
//         return false;
//         short arr[26];
//         bool out=false;
//         int valid = 0;
//         for (char c : s)
//         {
//             arr[c - 'a']++;
//             if(arr[c - 'a']==2 && arr[c - 'a']%2==0)
//             {out= true,arr[c - 'a']=0;}
//             else if (arr[c-'a']%2==1)
//             {
//                out=false; 
//             }
//         }
//         valid = 0;
//         for (int i = 0; i < 26; i++)//count 1's 
//         {
//             if (arr[i] == 1)
//                 valid++;
//         }
//         if (valid == s.size() && valid==k)
//             return true;
//         return out;
//     }
// };

//all i care about is odd as 3 =2+1 neglect 2 as it is palindrome by nature 
//so count odds and compare to k if odd<= k then can make k number of palidrome
// class Solution {
//  public:
//      bool canConstruct(string s, int k) {
//          if (k>s.size())
//          return false;
//          short arr[26];
//          int odd = 0;
//          for (char c : s)
//              arr[c - 'a']++;
//          for (int i = 0; i < 26; i++)//count 1's 
//          {
//              if (arr[i] & 1)
//                  odd++;
//          }
//          if (odd > k)
//              return false;
//          return true;
//      }
//  };
//optimized^2
class Solution {
 public:
     bool canConstruct(string s, int k) {
         if (k>s.size())
         return false;
         bool arr[26];
         int odd = 0;
         for (char c : s)
             arr[c - 'a'] =!arr[c - 'a'];
         for (int i = 0; i < 26; i++)//count 1's 
         {
             if (arr[i] & 1)
                 odd++;
         }
         if (odd > k)
             return false;
         return true;
     }
 };