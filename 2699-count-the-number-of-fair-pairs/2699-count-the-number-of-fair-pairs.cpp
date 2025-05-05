//naive TLE O(n^2)
//class Solution {
//public:
//    long long countFairPairs(vector<int>& nums, int lower, int upper) {
//        int n = nums.size();
//        long long sum;
//        int counter = 0;
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = i + 1; j < n; j++)
//            {
//                    sum = nums[i] + nums[j];
//                    if (sum <= upper && sum >= lower)
//                        counter++;
//            }
//        }
//        return counter;
//    }
//
//};
// 2 pointers
class Solution {
public:
    long long solve(vector<int>& nums, int sum)
    {
        int i = 0, j = nums.size() - 1;
        long long cnt = 0;
        while (i<j)
        {
            if (nums[i] + nums[j] <= sum)
            {
                cnt += (j - i);
                i++;
            }
            else
                j--;
        }
        return cnt;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        
        sort(nums.begin(), nums.end());
        
        return solve(nums, upper) - solve(nums, lower - 1);
    }

};