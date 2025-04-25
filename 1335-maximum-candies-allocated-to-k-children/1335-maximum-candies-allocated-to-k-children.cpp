// class Solution {
// public:
//     bool ok(int mid, vector<int>& candies, long long k)
//     {
//         long long cnt=0;
//         for (int& val : candies)
//             {cnt += val/mid;}
//         return cnt >= k;
//     }
//     int maximumCandies(vector<int>& candies, long long k) {
//         int start = 1, end = 1e7;
//         int cur = 0, mid;
//         while (start<=end)
//         {
//             mid = (start + end) / 2;
//             if ( ok(mid,candies,k) )
//             {
//                 cur = mid;
//                 start = mid + 1;
//             }
//             else
//                 end = mid -1;
//         }
//         return cur;
//     }
// };
class Solution {
public:
    bool ok(int mid, vector<int>& candies, long long k)
    {
        long long cnt=0;
        // long   sum=0;
        for (int& val : candies)
            {cnt += val/mid;
            // sum+=val;
            
            }
            // if(k>sum)
            // return 0;
        return cnt >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int start = 1, end = *max_element(candies.begin(),candies.end());
        int cur = 0, mid;
        while (start<=end)
        {
            mid = (start + end) / 2;
            if ( ok(mid,candies,k) )
            {
                cur = mid;
                start = mid + 1;
            }
            else
                end = mid -1;
        }
        return cur;
    }
};