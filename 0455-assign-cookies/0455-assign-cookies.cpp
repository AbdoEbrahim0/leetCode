class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int gSize = g.size();
        int sSize = s.size();
        for (int i = 0; i < gSize; i++)
            cout << g[i] << " ";
        cout << "\n";
        for (int i = 0; i < sSize; i++)
            cout << s[i] << " ";
        int indxS = 0;
        int satisfied = 0;
        // g = [1, 2, 3], s = [1, 1] out:1
        //Input: g = [1,2], s = [1,2,3] out:2
        //Input: g = [1,2,3], s = [3] out:1

//g = { 2, 16, 32, 34, 34, 41, 45 };
//s= { 2, 3, 4, 6, 6, 7, 10, 13, 18, 21, 23, 23, 23, 27, 30, 30, 33, 36, 39, 39, 40, 43, 45 };
        for (int i = 0; i < gSize; i++)
        {
            while (indxS < sSize  && s[indxS] < g[i])
                indxS++;
            if (indxS >= sSize)
            {
                break;
            }
            if (i < gSize && g[i] <= s[indxS])
            {
                satisfied++;
                s[indxS] = 0;
            }
                
            //g[i] = g[i] - s[indxS];
            // found equal or bigger than needed
            
            if (satisfied == gSize)
                return satisfied;
        }
        return satisfied;
    }
};
