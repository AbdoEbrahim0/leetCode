class Solution {
public:
    void reverseString(vector<char> &s) {
        int end = s.size() - 1;
        for (int i = 0; i < s.size() >> 1;)
        {
            swap(s[i++], s[end--]);
        }
    }
};
