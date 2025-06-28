class Solution {
public:
    int minimumLength(string s) {
        //abaacbcbb
          //112312234
          //    a b c
          //    3%2=1 4%2=0  2/2=1 
        int arr[26] = {};
        for (char c : s)
        {
            arr[c - 'a']++;
        }
        int len=0;
        for (int i = 0; i < 26; i++)
        {
            if (arr[i] && arr[i] % 2 == 0)
                len += 2;
            else if (arr[i] && arr[i] % 2 == 1)
                len += 1;
        }
        return len;
    }
};