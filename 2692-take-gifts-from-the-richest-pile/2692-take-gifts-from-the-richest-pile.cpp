class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int > pr;
        for (int i = 0; i < gifts.size(); i++)
        {
            pr.push(gifts[i]);

        }
        long long val;
        while ((k--) >= 1)
        {
            val= sqrt(pr.top());
            pr.pop();
            pr.push(val);
        }
        val = 0;
        while ( ! pr.empty())
        {
            val += pr.top();
            pr.pop();
        }
        return val;
    }
};