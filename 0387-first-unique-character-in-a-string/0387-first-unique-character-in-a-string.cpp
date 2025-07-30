class Solution {
public:
    int firstUniqChar(string s) {
        int arr[26] = {};
        int sSize=s.size();
        for (char &ch : s)
        {
            if(arr[ch - 'a']<=1)
            arr[ch - 'a']++;
        }

        for (int i = 0; i <sSize; i++)
        {
            if (arr[s[i]-'a'] == 1)
                return i;
        }
        return -1;
    }
};