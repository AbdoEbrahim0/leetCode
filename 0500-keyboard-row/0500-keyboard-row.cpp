// class Solution {
// public:
//     vector<string> findWords(vector<string>& words) {
//         string Q = "qwertyuiop";
//         string A = "asdfghjkl"; //capslock
//         string Z = "zxcvbnm"; //capslock
//         bool Qarr[26] = {};
//         bool Aarr[26] = {};
//         bool Zarr[26] = {};
        
//         for (short i = 0; i < Q.size(); i++)
//             Qarr[Q[i] - 'a'] = 1;
//         for (short i = 0; i < A.size(); i++)
//             Aarr[A[i] - 'a'] = 1;        
//         for (short i = 0; i < Z.size(); i++)
//             Zarr[Z[i] - 'a'] = 1;

//         bool flagToDelete=false;
//         //words = ["Hello","Alaska","Dad","Peace"]
//         for (int x=0;x<words.size();x++)
//         {
            
            
//             char myX = words[x][0];
//             if (A.find(tolower(myX) ) != string::npos)
//             {
//                 for (char& c : words[x])
//                 {
//                     if ( Aarr[tolower(c) - 'a'] == false)
//                     {
//                         flagToDelete = true;
//                         break;
//                     }
//                 }
//             }
//             else if (!flagToDelete &&  Z.find(tolower(myX)) != string::npos)
//             {
//                 for (char& c : words[x])
//                 {
//                     if (Zarr[tolower(c) - 'a'] == false)
//                     {
//                         flagToDelete = true;
//                         break;
//                     }
//                 }
//             }
//             else if (!flagToDelete)
//             {
//                 for (char& c : words[x])
//                 {
//                     if (Qarr[tolower(c) - 'a'] == false)
//                     {
//                         flagToDelete = true;
//                         break;
//                     }
//                 }
//             }
//             if (flagToDelete)
//             {
//                 words.erase(words.begin() + x);
//                 x--;
//             }
//             flagToDelete=false;
//         }
//         return words;
//     }
// };


//more optimized as erase fn tak O(N) so total com :O(n)*O(n)=O(n^2) 
// class Solution {
// public:
//     vector<string> findWords(vector<string>& words) {
//         string Q = "qwertyuiop";
//         string A = "asdfghjkl"; //capslock
//         string Z = "zxcvbnm"; //shift
//         bool Qarr[26] = {};
//         bool Aarr[26] = {};
//         bool Zarr[26] = {};
//         short i;
//         for (i= 0; i < 10; i++)
//             Qarr[Q[i] - 'a'] = 1;
//         i = 0;
//         for ( i = 0; i < 9; i++)
//             Aarr[A[i] - 'a'] = 1;        
//         i = 0;
//         for (i = 0; i < 7; i++)
//             Zarr[Z[i] - 'a'] = 1;

//         bool flagToDelete;
//         vector<string> res;
//         //words = ["Hello","Alaska","Dad","Peace"]
//         for (int x=0;x<words.size();x++)
//         {
//             flagToDelete = false;
//             char whichRow = tolower(words[x][0]);
//             if (Aarr[whichRow - 'a'])
//             {
//                 for (char& c : words[x])
//                 {
//                     if ( Aarr[tolower(c) - 'a'] == false)
//                     {
//                         flagToDelete = true;
//                         break;
//                     }
//                 }
//             }
//             else if (!flagToDelete && Zarr[whichRow - 'a'])
//             {
//                 for (char& c : words[x])
//                 {
//                     if (Zarr[tolower(c) - 'a'] == false)
//                     {
//                         flagToDelete = true;
//                         break;
//                     }
//                 }
//             }
//             //"Qwertyuiop"
//             else if (!flagToDelete)
//             {
//                 for (char& c : words[x])
//                 {
//                     if ( Qarr[tolower(c) - 'a'] == false)
//                     {
//                         flagToDelete = true;
//                         break;
//                     }
//                 }
//             }
//             if (flagToDelete==false)
//             {
//                 res.emplace_back(words[x]);
//             }
//         }
//         return res;
//     }
// };


//[optimized ^3] in maintablility and simple logic
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        // Map each letter to a row: 0 -> QWERTY, 1 -> ASDFG, 2 -> ZXCVB
        unordered_map<char, int> rowMap;
        string rows[3] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        for (int i = 0; i < 3; i++) {
            for (char c : rows[i]) {
                rowMap[c] = i;
            }
        }

        vector<string> result;
        for (const string& word : words) {
            int row = rowMap[tolower(word[0])];
            bool valid = true;
            for (char c : word) {
                if (rowMap[tolower(c)] != row) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                result.push_back(word);
            }
        }

        return result;
    }
};
