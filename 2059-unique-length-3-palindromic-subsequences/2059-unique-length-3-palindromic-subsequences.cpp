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
//optimized ^2
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        
        unordered_map<char, pair<int, int>>myMap;
        //aabca
        bool caontainPalindrome = false;
        vector< char> mapValues;
        //O(N)
        for (int i=0;i<s.size();i++)
        {
            if (myMap.find(s[i]) == myMap.end())
            {
                myMap[s[i]].first = i;
                mapValues.emplace_back(s[i]);
            }
            else
                myMap[s[i]].second = i;

            if (myMap[s[i]].second != 0)
                caontainPalindrome = true;
        }
        
        if (caontainPalindrome == false)
            return 0;
        int cnt = 0;
        //aabca
        //bbcbaba
        unordered_set<string> mySet;
        string Uniq = "123";
        for (int x=0;x<mapValues.size();x++)
        {   

            for (int i = myMap[mapValues[x]].first + 1; i < myMap[mapValues[x]].second; i++)//iterate on string
            {
                Uniq[0]= mapValues[x];
                Uniq[1] = s[i];
                Uniq[2] = mapValues[x];

                if ((!mySet.count(Uniq)))
                {
                    //cnt++;
                    mySet.insert(Uniq);
                }
            }
            
        }
        
        return mySet.size();
    }
};