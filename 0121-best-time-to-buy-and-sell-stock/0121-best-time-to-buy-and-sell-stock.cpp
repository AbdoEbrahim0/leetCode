// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         int mini=prices[0];
//         int dx = 0;
//         for (int i = 1; i < n; i++)
//         {
//             if (prices[i] < mini)
//             {
//                 mini = prices[i];
//                 dx = i;
//             }
//         }
//         int maxi = 0;
//         for (int s = dx+1; s < n; s++)
//         {
//             maxi = max(maxi, prices[s]- prices[dx] );
//         }
//         return maxi;
//     }
// };
// //TLE
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         int maxi = 0;
//         for (int i = 0; i < n; i++)
//         {
//             //vector<int>v = { 7,1,5,3,6,4 };
//             for (int j = i + 1; j < n; j++)
//             {
//                 if (prices[j] > prices[i])
//                 {
//                     maxi = max(maxi, prices[j] - prices[i]);
//                 }
//             }
            
//         }
        
//         return maxi;
//     }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxi = 0;
        int mini = prices[0];
        for (int i = 1; i < n; i++)
        {
            //vector<int>v = { 2,4,1 };
            //vector<int>v = { 7,1,5,3,6,4 };
            mini = min(mini, prices[i]);
                    maxi = max(maxi, prices[i] - mini);            
        }
        return maxi;
    }
};