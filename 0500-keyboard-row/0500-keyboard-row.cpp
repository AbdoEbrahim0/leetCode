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

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string Q = "qwertyuiop";
        string A = "asdfghjkl"; //capslock
        string Z = "zxcvbnm"; //capslock
        bool Qarr[26] = {};
        bool Aarr[26] = {};
        bool Zarr[26] = {};
        
        for (short i = 0; i < Q.size(); i++)
            Qarr[Q[i] - 'a'] = 1;
        for (short i = 0; i < A.size(); i++)
            Aarr[A[i] - 'a'] = 1;        
        for (short i = 0; i < Z.size(); i++)
            Zarr[Z[i] - 'a'] = 1;

        bool flagToDelete=false;
        //words = ["Hello","Alaska","Dad","Peace"]
        for (int x=0;x<words.size();x++)
        {
            
            
            char myX = tolower(words[x][0]);
            if (Aarr[myX - 'a'])
            {
                for (char& c : words[x])
                {
                    if ( Aarr[tolower(c) - 'a'] == false)
                    {
                        flagToDelete = true;
                        break;
                    }
                }
            }
            else if (!flagToDelete && Zarr[myX - 'a'])
            {
                for (char& c : words[x])
                {
                    if (Zarr[tolower(c) - 'a'] == false)
                    {
                        flagToDelete = true;
                        break;
                    }
                }
            }
            //"Qwertyuiop"
            else if (!flagToDelete)
            {
                for (char& c : words[x])
                {
                    if ( Qarr[tolower(c) - 'a'] == false)
                    {
                        flagToDelete = true;
                        break;
                    }
                }
            }
            if (flagToDelete)
            {
                words.erase(words.begin() + x);
                x--;
            }
            flagToDelete=false;
        }
        return words;
    }
};
