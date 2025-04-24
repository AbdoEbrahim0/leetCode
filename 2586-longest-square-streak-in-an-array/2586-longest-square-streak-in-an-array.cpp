    //the next sol give TLE
// class Solution {
// public:
//     int longestSquareStreak(vector<int>& nums) {
//         set<int> mySet;
//         for (int &val : nums)
//         {
//             mySet.insert(val);
//         }
//         long temp;
//         int maxi = 0;
//         int cnt = 0;
//         for (set<int>::iterator it = mySet.begin(); it != mySet.end(); ++it)
//         {
//             temp = *it;
//             temp = temp * temp;
//             for (set<int>::iterator it_j = it; it_j != mySet.end(); ++it_j)
//             {
//                 if (mySet.find(temp ) != mySet.end() )
//                 {
//                     temp = temp * temp;
//                     cnt++;
//                 }
//             }
//             maxi = max(maxi, cnt+1);
//             cnt = 0;
//         }
//         if (maxi == 1) return -1;
//         return maxi;
//     }
// };
//TLE [optimized]

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int maxElement= *max_element(nums.begin(), nums.end());
        set<int> mySet;
        for (int &val : nums)
        {
            mySet.insert(val);
        }
        long long temp;
        int maxi = 0;
        int cnt = 0;//,power=2;
        for (set<int>::iterator it = mySet.begin(); it != mySet.end(); ++it)
        {
            temp = *it;
            temp = temp * temp;
            for (set<int>::iterator it_j = it; (it_j != mySet.end()) ; ++it_j)
            {
                if ((*it_j > temp) && (*it_j > maxElement))
                    break;
                if (temp > 100000)
                    break;
                if (mySet.find(temp ) != mySet.end() )
                {
                    temp = temp * temp;
                    cnt++;
                //    power++;
                }

            }
            maxi = max(maxi, cnt+1);
            cnt = 0;
            //power = 2;
        }
        if (maxi == 1) return -1;
        return maxi;
    }
};