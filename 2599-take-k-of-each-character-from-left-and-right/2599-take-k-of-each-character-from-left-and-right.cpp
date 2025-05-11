class Solution {
public:
    bool ok(int mid, string s, int k)
    {
        array <int, 3>arrR = { 0,0,0 };
        vector<array<int, 3>>vR;

        array <int, 3>arrL = { 0,0,0 };
        vector<array<int, 3>>vL;

        int sizeString = s.size();
        vL.emplace_back(array<int, 3> {0, 0, 0}); //when no taking any substring 
        for (int z = s.size() - 1; z >= sizeString - mid ; z--)
        {
            arrL[s[z] - 'a']++;
            vL.emplace_back(arrL);
        }
        reverse(vL.begin(), vL.end());
        
        vR.emplace_back(array<int, 3> {0, 0, 0});
        for (int z = 0; z < mid; z++)
        {
            arrR[s[z] - 'a']++;
            vR.emplace_back(arrR);
        }
        
        for (int i = 0; i < vL.size(); i++)
        {
            if (vR[i][0] + vL[i][0] >= k && vR[i][1] + vL[i][1] >= k && vR[i][2] + vL[i][2] >= k)
                return true;
        }
        return false;
    }
    int takeCharacters(string s, int k) {
        int n = s.size();
        int start = 0, end = n, cur = -1;
        int mid = 3 * k;

        while (start <= end)
        {
            mid = (start + end) >> 1; // divide on 2
            //mid = 10;
            if (ok(mid, s, k)) //try to minimize
            {
                cur = mid;
                end= mid - 1;
            }
            else
                start = mid + 1;
        }
        return cur;
    }
};