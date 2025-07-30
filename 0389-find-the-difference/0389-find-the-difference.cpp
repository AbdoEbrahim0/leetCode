class Solution {
public:
    char findTheDifference(string s, string t) {
        bitset<26>arr;
        for (char& chS : s)
        {
            arr[chS - 'a'] = ~arr[chS - 'a'];
        }
        for (char& chT : t)
        {
            arr[chT - 'a'] = ~arr[chT - 'a'];
            
        }
        for(int i=0;i<26;i++)
        {
            if (arr[i] == 1)
                return char(i+'a');
        }
        return 'A';// will not reach any way
    }
};