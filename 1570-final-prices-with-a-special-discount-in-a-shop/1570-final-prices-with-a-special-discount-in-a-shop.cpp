// class Solution {
// public:
//     vector<int> finalPrices(vector<int>& prices) {
//      //wrong at test 12
//      for(int i=0,j=i+1;j < prices.size() && i< prices.size()-1;i++,j++)
//        {
//    if (j > i && prices[j] <= prices[i])
//    {
//        prices[i] = prices[i] - prices[j];
//        j--;
//    }
//    else
//        i--;
//        }
//    return prices;   
//     }
// };
//wrong because not creating new vector
// class Solution {
// public:
//     vector<int> finalPrices(vector<int>& prices) {
  
//         stack<int>stk;
//         for (int j = prices.size() - 1; j >= 0; j--)
//         {
//             while ( stk.size() &&(prices[j] < stk.top()))
//             {
//                 stk.pop();
//             }
//             if (! stk.empty())
//             {
//                 prices[j] = prices[j] - stk.top();
//             }
//             stk.push(prices[j]);
//         }
//         return prices;
//     }
// };

// class Solution {
// public:
//     vector<int> finalPrices(vector<int>& prices) {
//         vector<int>res =prices;
//         stack<int>stk;
//         for (int j = prices.size() - 1; j >= 0; j--)
//         {
//             while ( stk.size() &&(prices[j] < stk.top()))
//             {
//                 stk.pop();
//             }
//             if (! stk.empty())
//             {
//                 res[j] = res[j] - stk.top();
//             }
//             stk.push(prices[j]);
//         }
//         return res;
//     }
// };
//////////////////

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int>stk;
        vector<int> res = prices;
        for (int i = prices.size()-1 ; i>= 0; i--)
        {
            while (stk.size() && prices[i] < stk.top())
                stk.pop();

                if ( stk.size() && prices[i] >= stk.top())
                    res[i] = prices[i] - stk.top();
            stk.push(prices[i]);

        }
        return res;
    }
};