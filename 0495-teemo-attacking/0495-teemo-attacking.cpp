//wrong ans
// class Solution {
// public:
//     int findPoisonedDuration(vector<int>& timeSeries, int duration) {
//         int cnt=0;
//         int total_poisioned = 0;
//         unordered_set<int>set;
//         int endInterval;
//         int previousEndInterval= (timeSeries[0] + duration - 1);
//         int fTerm, sTerm;
//         //[1,2]   [3]  
//         for (int i = 0; i < timeSeries.size(); i++)
//         {
//             endInterval = timeSeries[i] + duration - 1; //4-1=3
//             if (i && timeSeries[i] <= previousEndInterval)
//                 cnt += endInterval- previousEndInterval ;
//             else if (i && timeSeries[i] > previousEndInterval)
//             cnt += endInterval- timeSeries[i] +1 ;
//             else
//                 cnt += endInterval;

//             previousEndInterval = endInterval;
//         }
//         return cnt;
//     }
// };

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty()) return 0;
        
        int total = 0;
        for (int i = 1; i < timeSeries.size(); ++i) {
            int diff = timeSeries[i] - timeSeries[i-1];
            total += min(diff, duration); // Add overlapping or full duration
        }
        total += duration; // Add the last attack's full duration
        return total;
    }
};