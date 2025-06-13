class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        //unordered_set <int>set1;
        unordered_set <int>set2;
        for (int i = 0; i < n2; i++)
        {
            set2.insert(nums2[i]);
        }
        vector<int>res;
        for (int i = 0; i < n1 ; i++)
        {
            if (set2.count(nums1[i]))
                res.emplace_back(nums1[i]);
        }
        set2.clear();
        for (int z = 0; z < res.size(); z++)
        {
            set2.insert(res[z]);
            
        }
        res = vector<int>(set2.begin(), set2.end());
        return res;
    }
};