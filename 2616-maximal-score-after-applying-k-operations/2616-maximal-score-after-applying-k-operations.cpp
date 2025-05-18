class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long score = 0;
        priority_queue<int, vector<int>, less<int>>pr;

        for (int& val : nums)
            pr.push(val);
        
        int largeKth;
        for (int i = 0; i < k; i++)
        {
            largeKth = pr.top();
            pr.pop();
            score += largeKth;
            
            pr.push(ceil(largeKth/3.0));

        }
        return score;
    }
};
