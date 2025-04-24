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
//TLE [optimized]^2

// class Solution {
// public:
//     int longestSquareStreak(vector<int>& nums) {
//         int maxElement= *max_element(nums.begin(), nums.end());
//         set<int> mySet;
//         for (int &val : nums)
//         {
//             mySet.insert(val);
//         }
//         long long temp;
//         int maxi = 0;
//         int cnt = 0;//,power=2;
//         for (set<int>::iterator it = mySet.begin(); it != mySet.end(); ++it)
//         {
//             temp = *it;
//             temp = temp * temp;
//             for (set<int>::iterator it_j = it; (it_j != mySet.end()) ; ++it_j)
//             {
//                 if ((*it_j > temp) && (*it_j > maxElement))
//                     break;
//                 if (temp > 100000)
//                     break;
//                 if (mySet.find(temp ) != mySet.end() )
//                 {
//                     temp = temp * temp;
//                     cnt++;
//                 //    power++;
//                 }

//             }
//             maxi = max(maxi, cnt+1);
//             cnt = 0;
//             //power = 2;
//         }
//         if (maxi == 1) return -1;
//         return maxi;
//     }
// };
    //TLE [optimized]^3
// class Solution {
// public:
//     int longestSquareStreak(vector<int>& nums) {
//         int maxElement= *max_element(nums.begin(), nums.end());
//         unordered_set <int> mySet;
//         for (int &val : nums)
//         {
//             mySet.insert(val);
//         }
//         long long temp;
//         int maxi = 0;
//         int cnt = 0;//,power=2;
//         for (int val :mySet)
//         {
//             temp = val;
//             temp = temp * temp;
//             for (int val_j : mySet)
//             {
//                 if ((val_j > temp) && (val_j > maxElement) )
//                     break;
//                 if (temp > 100000)
//                     break;
//                 if (mySet.find(temp ) != mySet.end() )
//                 {
//                     temp = temp * temp;
//                     cnt++;
//                 //    power++;
//                 }

//             }
//             maxi = max(maxi, cnt+1);
//             cnt = 0;
//             //power = 2;
//         }
//         if (maxi == 1) return -1;
//         return maxi;
//     }
// };
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set <int> mySet;
        for (int &val : nums)
        {
            mySet.insert(val);
        }
        long long temp;
        int maxi = 0;
        int cnt = 0;
        for (int &val :nums)
        {
            temp = val;
            temp = temp * temp;
            for (int& val_j : nums)
            {
                if (temp > 100000)
                    break;
                if (mySet.count(temp ))
                {
                    temp = temp * temp;
                    cnt++;
                }else
                break;
            }
            maxi = max(maxi, cnt+1);
            cnt = 0;
        }
        if (maxi == 1) return -1;
        return maxi;
    }
};

    //TLE [optimized]^4 (binary search)
// class Solution {
// public:
//     int longestSquareStreak(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         long long temp ;
//         int counter = 0;
//         int maxi = 0;
//         for (int& val : nums)
//         {
//             temp = 1LL* val * val;
//             counter = 0;
//             while (binary_search(nums.begin(), nums.end(), temp))
//             {
//                 counter++;
//                 temp = temp * temp;
//             }
//             maxi = max(maxi, counter +1);
//         }
//         if (maxi <= 1) return -1;
//         return maxi;
//     }
// };