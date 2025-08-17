class Solution {
public:
    // helper function to check if s is a subsequence of t
    bool isSubsequence(string &s, string &t) {
        int i = 0, j = 0;
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) i++;
            j++;
        }
        return i == s.size();
    }

    int findLUSlength(vector<string>& strs) {
        int n = strs.size();
        int res = -1;

        for (int i = 0; i < n; i++) {
            bool uncommon = true;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (isSubsequence(strs[i], strs[j])) {
                    uncommon = false;
                    break;
                }
            }
            if (uncommon) {
                res = max(res, (int)strs[i].size());
            }
        }

        return res;
    }
};
