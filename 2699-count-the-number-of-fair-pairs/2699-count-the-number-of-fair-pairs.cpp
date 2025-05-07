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
// class Solution {
// public:
//     long long solve(vector<int>& nums, int sum)
//     {
//         int i = 0, j = nums.size() - 1;
//         long long cnt = 0;
//         while (i<j)
//         {
//             if (nums[i] + nums[j] <= sum)
//             {
//                 cnt += (j - i);
//                 i++;
//             }
//             else
//                 j--;
//         }
//         return cnt;
//     }
//     long long countFairPairs(vector<int>& nums, int lower, int upper) {
//         sort(nums.begin(), nums.end());
//         return solve(nums, upper) - solve(nums, lower - 1);
//     }

// };
//binary search  O(n) * O(log n) *O(log n)
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long counter = 0;
        sort(nums.begin(), nums.end());
        int startRange, endRange;
        for (int i = 0; i < nums.size(); i++)
        {            
            startRange = lower_bound(nums.begin() + i, nums.end(), lower - nums[i]) - nums.begin();
            endRange= upper_bound(nums.begin() + i, nums.end(), upper- nums[i]) - nums.begin();
            endRange--;
                //cout<<i<<"  "<<startRange<<"  "<<endRange<<"\n";
            if(startRange<=endRange)
            counter += ( endRange-startRange ) + 1 -(i>=startRange && i<=endRange);
            /*
              testcase [0,1,4,4,5,7] upper =6 lower =3
                0  2  4     0>=2 Not  0>=54 Not  cnt=2 +1 =3
                1  2  4      1>=2 Not  1>=4 Not  cnt=2 +1 =3
                2  2  1      end < start then not valid     counter wil be negative
                3  3  2      end < start then not valid     counter wil be negative
                4  4  3      end < start then not valid     counter wil be negative
                5  5  4      end < start then not valid     counter wil be negative
                                                    total cnt =6
                
                ---------------------
              testcase [0,1,3,7,4,4,5] upper =6 lower =3
                0  2  5     0>=2 Not  0>=5 Not  cnt=3 +1 =4
                1  2  5      1>=2 Not  1>=5 Not  cnt=3 +1 =4
                2  2  2  (i=j=2) nums[i=2] =nums[j=2] =3  pair can not be (2,2)
                3  3  2      end < start then not valid     counter wil be negative
                4  4  3      end < start then not valid     counter wil be negative
                5  5  4      end < start then not valid     counter wil be negative
                6  6  5      end < start then not valid     counter wil be negative
                0  0  5
                --------------
                [0,0,0,0,0,0]
                0  0  5  0>=0 valid  0>=5 Not  cnt=5 +1 -1 =5
                1  1  5  1>=1 valid  1>=5 Not   cnt=4 +1 -1 =4
                2  2  5  2>=2 valid  2>=5 Not   cnt=3 +1  -1=3
                3  3  5  3>=3 valid  3>=5 Not   cnt=2 +1  -1=2
                4  4  5  4>=4 valid  4>=5 Not   cnt=1 + 1  -1=1
                5  5  5  5>=5 valid  5>=5 valid then  subtract 1 cnt=0-1 +1 = 0
                                                                total cnt = 15
            */
        }      
        return counter;
    }
};