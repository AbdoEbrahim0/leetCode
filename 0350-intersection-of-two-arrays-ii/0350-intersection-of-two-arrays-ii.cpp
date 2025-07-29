class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        vector<int> r1(1001), r2(1001);
        for (int val1 : nums1)
        {
            r1[val1]++;
        }
        for (int val2 : nums2)
        {
            r2[val2]++;
        }
        vector<int>res;
        for (int i = 0; i <= 1000; i++)
        {
            if (r1[i] && r2[i])
            {
                int mini = min(r1[i], r2[i]);
                for (int z = 0; z < mini; z++)
                    res.emplace_back(i);
            }
        }
        return res;
    }
};