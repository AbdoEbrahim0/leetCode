class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for (int i = 0; i <= n; i++)
        {
            int cnt = 0;
            int copyOfI = i;
            for (int x = 0; i>0 && x < 32 ; x++)
            {
                //int z = (1 << x); //MEM care
                if (i & (1 << x) )
                    cnt++;
                copyOfI = (copyOfI >> 1);
            }
            res.emplace_back(cnt);
        }
        return res;
    }
};