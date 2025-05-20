//Unordered Set	times:O(n * m)	space: O(26)
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> allowedChars(allowed.begin(), allowed.end());
        int count = 0;
        
        for (const string& word : words) {//O(n)
            bool isValid = true;
            for (char ch : word) {
                if (allowedChars.find(ch) == allowedChars.end()) { //O(m)
                    isValid = false;
                    break;
                }
            }
            if (isValid) {
                count++;
            }
        }
        return count;
    }
};
// //Bitset	 times: O(n * m)	space: O(1)
// class Solution {
// public:
//     int countConsistentStrings(string allowed, vector<string>& words) {
//         bitset<26>visted;
//         for (const char& ch : allowed)
//         {
//             visted[ch - 'a'] = 1;
//         }
//         bool valid = true;
//         int counter = 0;
//         for (const string &word : words)
//         {
//             valid = 1;
//             for (const char &ch : word)
//             {
//                 if (visted[ch - 'a'] == false)
//                 {
//                     valid = 0;
//                     break;
//                 }
//             }
//             if (valid)
//                 counter++;

//         }
//         return counter;
//     }

// };