class Solution {
public:
    string reverseVowels(string s) {
        //char('i') == 105; char('I') == 105  73
    /*char small[5] = { 'i', 'o', 'a', 'e', 'u' };
    char capital[5] = {'I', 'o', 'a', 'e', 'u' };*/

        vector<char>v;
        for (char c : s)
        {
            if (c == 'i' || c == 'o' || c == 'a' || c == 'e' || c == 'u')
            {
                v.emplace_back(c);
            }
            else if (c == 'I' || c == 'O' || c == 'A' || c == 'E' || c == 'U')
            {
                v.emplace_back(c);
            }
        }

        int vSize = v.size() - 1;
        for (char& c : s)
        {
            if (c == 'i' || c == 'o' || c == 'a' || c == 'e' || c == 'u')
            {
                c = v[vSize--];
            }
            else if (c == 'I' || c == 'O' || c == 'A' || c == 'E' || c == 'U')
            {
                c = v[vSize--];
            }
        }
        return s;
    }
};