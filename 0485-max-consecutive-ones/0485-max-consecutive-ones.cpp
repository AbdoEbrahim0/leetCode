class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0, maxi = 0;
        
        for (int& val : nums)
        {
            if (val == 1)
                cnt++;
            else
                cnt = 0;

            maxi = max(maxi, cnt);
        }
        return maxi;
    }
};