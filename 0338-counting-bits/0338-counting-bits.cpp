class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for (int i = 0; i <= n; i++)
        {
            int cnt = 0;
            int copyOfI = i;
            for (short x = 0; x < 32; x++)
            {
                int z = (1 << x);
                if (i &  z)
                    cnt++;
                copyOfI = (copyOfI >> 1);
            }
            res.emplace_back(cnt);
        }
        return res;
    }
};