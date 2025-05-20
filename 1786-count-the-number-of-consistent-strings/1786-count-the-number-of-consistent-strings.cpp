class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        bitset<26>visted;
        for (char& ch : allowed)
        {
            visted[ch - 'a'] = 1;
        }
        bool valid = true;
        int counter = 0;
        for (const string &word : words)
        {
            valid = 1;
            for (const char &ch : word)
            {
                if (visted[ch - 'a'] == false)
                {
                    valid = 0;
                    break;
                }
            }
            if (valid)
                counter++;

        }
        return counter;
    }

};