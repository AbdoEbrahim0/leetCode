// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         /*int nd = -1;
//         int ndSize = needle.size();
//         for (char& c: haystack)
//         {
//             if (c == needle[++nd]) { ndSize--; }
//             if (ndSize != 0)
//                 nd = -1;

//         }*/
//        int x= haystack.find(needle);
//        return (x == string::npos) ? -1 : x;
//     }
// };
// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         int nd = 0;
//         int ndSize = needle.size();
//         for (int c=0 ;c<  haystack.size();c++)
//         {
//             if (nd< ndSize && haystack[c] == needle[nd]) { nd++; }
//             else
//             {
//                 if (nd == ndSize)
//                     return c - nd;
//                 else
//                     nd = 0;
//             }

//         }
//        return -1;
//     }
// };


// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         int nd = 0;
//         int ndSize = needle.size();
//         int c;
//         for (c=0 ;c<  haystack.size();c++)
//         {
//             if (nd< ndSize && haystack[c] == needle[nd]) { nd++; }
//             else
//             {
//                 if (nd == ndSize)
//                     return c - nd;
//                 else
//                     nd = 0;
//             }
//         }
//         if (nd == ndSize)
//             return c - nd;
//        return -1;
//     }
// };

// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         int nd = 0;
//         int ndSize = needle.size();
//         int c;
//         for (c=0 ;c<  haystack.size();c++)
//         {
//             if (nd< ndSize && haystack[c] == needle[nd])
//             { nd++; }
//             else
//             {
//                 if (nd == ndSize)
//                     return c - nd;
//                 else
//                 {
//                     nd = 0;
//                      // c--;
//                 }
//             }
//         }
//         if (nd == ndSize)
//             return c - nd;
//        return -1;
//     }
// };

// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         int nd = 0;
//         int ndSize = needle.size();
//         int c=0;
//         for (;c<  haystack.size();c++ )
//         {
            
//             while (nd< ndSize && haystack[c] == needle[nd])
//             {
//                 nd++,c++;
//             }
            
//             if (nd == ndSize)
//                 return c - nd;
//             nd = 0;
//             if(c>=1)
//             c=c-2;
            
//         }
//         if (nd == ndSize)
//             return c - nd;
//        return -1;
//     }
// };
//It's O(n * m) in worst-case, but fast enough for typical LeetCode constraints.
class Solution {
public:
    int strStr(string haystack, string needle) {
        int hSize = haystack.size();
        int nSize = needle.size();

        if (nSize == 0) return 0;
        if (hSize < nSize) return -1;

        for (int i = 0; i <= hSize - nSize; ++i) {
            int j = 0;
            while (j < nSize && haystack[i + j] == needle[j]) {
                ++j;
            }
            if (j == nSize) return i; // Full match found
        }

        return -1;
    }
};

// //KMP algorithmIt's O(n + m) in worst-case
// class Solution {
// public:
//     // Build the LPS array for the pattern (needle)
//     void buildLPS(const string& pattern, vector<int>& lps) {
//         int len = 0;  // length of the previous longest prefix suffix
//         lps[0] = 0;
//         for (int i = 1; i < pattern.size(); ) {
//             if (pattern[i] == pattern[len]) {
//                 len++;
//                 lps[i] = len;
//                 i++;
//             } else {
//                 if (len != 0) {
//                     len = lps[len - 1];  // fallback
//                 } else {
//                     lps[i] = 0;
//                     i++;
//                 }
//             }
//         }
//     }

//     int strStr(string haystack, string needle) {
//         if (needle.empty()) return 0;
//         int n = haystack.size();
//         int m = needle.size();
//         // Step 1: build LPS array
//         vector<int> lps(m);
//         buildLPS(needle, lps);
//         // Step 2: search
//         int i = 0; // index for haystack
//         int j = 0; // index for needle

//         while (i < n) {
//             if (haystack[i] == needle[j]) {
//                 i++; j++;
//                 if (j == m) return i - j;  // match found
//             } else {
//                 if (j > 0) {
//                     j = lps[j - 1];  // use the prefix info
//                 } else {
//                     i++;
//                 }
//             }
//         }
//         return -1;  // no match
//     }
// };
