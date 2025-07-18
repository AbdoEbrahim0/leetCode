// class Solution {
// public:
//     int countPalindromicSubsequence(string s) {
//         unordered_map<char, pair<int, int>>myMap;
//         //aabca
//         bool caontainPalindrome = false;
//         vector< char> mapValues;
//         for (int i=0;i<s.size();i++)
//         {
//             if (myMap.find(s[i]) == myMap.end())
//             {
//                 myMap[s[i]].first = i;
//                 mapValues.emplace_back(s[i]);
//             }
//             else
//                 myMap[s[i]].second = i;

//             if (myMap[s[i]].second != 0)
//                 caontainPalindrome = true;

//             //vis[s[i] - 'a']=1;
//         }
        
//         if (caontainPalindrome == false)
//             return 0;
//         int cnt = 0;
//         //aabca
//         //bbcbaba
//         unordered_set<string> mySet;
//         string Uniq = "";
//         for (int x=0;x<mapValues.size();x++)
//         {   
//             for (int i = myMap[mapValues[x]].first +1 ; i < myMap[mapValues[x]].second; i++)//iterate on string
//             if (i> myMap[mapValues[x]].first  && i< myMap[mapValues[x]].second)
//             {
//                 //cnt++;
//                 Uniq = "";
//                 Uniq.push_back(mapValues[x]);
//                 Uniq.push_back(s[i]);
//                 Uniq.push_back(mapValues[x]);
//                 mySet.insert(Uniq);
//             }
//         }
        
//         return mySet.size();
//     }
// };
// optimized ^2
// class Solution {
// public:
//     int countPalindromicSubsequence(string s) {
        
//         unordered_map<char, pair<int, int>>myMap;
//         //aabca
//         bool caontainPalindrome = false;
//         vector< char> mapValues;
//         //O(N)
//         for (int i=0;i<s.size();i++)
//         {
//             if (myMap.find(s[i]) == myMap.end())
//             {
//                 myMap[s[i]].first = i;
//                 mapValues.emplace_back(s[i]);
//             }
//             else
//                 myMap[s[i]].second = i;

//             if (myMap[s[i]].second != 0)
//                 caontainPalindrome = true;
//         }
        
//         if (caontainPalindrome == false)
//             return 0;

//         //aabca
//         //bbcbaba
//         unordered_set<string> mySet;
//         string Uniq = "123";
//         for (int x=0;x<mapValues.size();x++)
//         {   

//             for (int i = myMap[mapValues[x]].first + 1; i < myMap[mapValues[x]].second; i++)//iterate on string
//             {
//                 Uniq[0]= mapValues[x];
//                 Uniq[1] = s[i];
//                 Uniq[2] = mapValues[x];

//                 if ((!mySet.count(Uniq)))
//                 {

//                     mySet.insert(Uniq);
//                 }
//             }
            
//         }
        
//         return mySet.size();
//     }
// };
//optimized ^3
// class Solution {
// public:
//     int countPalindromicSubsequence(string s) {
//         unordered_map<char, pair<int, int>>myMap;
//         //aabca
//         bool caontainPalindrome = false;
//             char mapValuesArr[26];
//         //O(N)
//         for (int i=0;i<s.size();i++)
//         {
//             if (myMap.find(s[i]) == myMap.end())
//                 myMap[s[i]].first = i;
            
//             else
//                 myMap[s[i]].second = i;

//             if (myMap[s[i]].second != 0)// if alll char appear only once so there is no palindrome
//                 caontainPalindrome = true;
//         }
        
//         if (caontainPalindrome == false)
//             return 0;
//         //aabca
//         //bbcbaba
//         unordered_set<string> mySet;
//         string Uniq = "123";// uniqe of lenth 3
//         for (int x=0;x<26;x++)
//         {   
//             for (int i = myMap[x+'a'].first + 1; i < myMap[x + 'a'].second; i++)//iterate on string
//             {
//                 Uniq[0]= x + 'a';
//                 Uniq[1] = s[i];
//                 Uniq[2] = Uniq[0];
//                 if ((!mySet.count(Uniq)))
//                 {
//                     mySet.insert(Uniq);
//                 //    break;
//                 }
//             }
            
//         }
        
//         return mySet.size();
//     }
// };

class Solution {
public:
    int countPalindromicSubsequence(string s) {
     // char : 1st occurence >> last Occurence
     // a    : 0             >> 4
     // b    : 2             >> dont find
     // c    : 3             >> dont find
     
        vector<int> L(26, -1), R(26);
        for (int i = 0; i < s.size(); i++)
        {
            if(L[s[i] - 'a']==-1)
                L[s[i] - 'a'] = i;
            else 
                R[s[i] - 'a'] = i;

        }
        int ans = 0;
        for (int j = 0; j < 26; j++)
        {
            if (R[j] == 0)//if occur once //"adc"
                continue;
            bitset<26>vis;
            for (int st = L[j] + 1; st < R[j]; st++)
            {
                char ch = s[st];
                //check if appear at least once and 
                //to check if it was selected this char before it may lead to same result and we nne unique 
                if (L[ch - 'a'] != -1 && vis[ch - 'a']==0)
                {
                    ans++;
                    vis[ch - 'a'] = 1;
                }
            }
        }
        return ans;
    }
};