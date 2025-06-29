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

// class Solution {
// public:
//     vector<int> finalPrices(vector<int>& prices) {
//         stack<int>stk;
//         //vector<int> res = prices;
//         for (int i = prices.size()-1 ; i>= 0; i--)
//         {
//             while (stk.size() && prices[i] < stk.top())
//                 stk.pop();
//                 int temp=prices[i];
//                 if ( stk.size() && prices[i] >= stk.top())
//                     prices[i] = temp - stk.top();
//             stk.push(temp);

//         }
//         return prices;
//     }
// };

// class Solution {
// public:
//     vector<int> finalPrices(vector<int>& prices) {
//         /*stack<int>stk;*/
//         vector<int> res = prices;
//         for (int i = 0; i < prices.size(); i++)
//         {
//             int j = i + 1;
//             while (j < prices.size() &&! (prices[j] <= prices[i])  )
//             {
//                 j++;
//             }
//             if(j < prices.size())
//             res[i] = res[i] - prices[j];
//         }
//         return res;
//     }
// };

// class Solution {
// public:
//     vector<int> finalPrices(vector<int>& prices) {
//         /*stack<int>stk;*/
//         vector<int> res = prices;
//         int j;
//         for (int i = prices.size() - 2; i >= 0; i--)
//         {
//             j = i + 1;
//             while ( j <prices.size() &&!(prices[j] <= prices[i])  )
//             {
//                 j++;
//             }
//             if(j < prices.size() &&prices[j] <= prices[i])
//             res[i] = prices[i] - prices[j];
//         }
//         return res;
//     }
// };
//crack interview 60 pronblem
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        // if (is_sorted(prices.begin(), prices.end()))
        //     return prices;
        int i = 0;
        for (int j = i+1; i,j < prices.size();j++ )
        {
            j = i + 1;
            while  (j < prices.size() && prices[j] > prices[i])
            {
                j++;
            }
            if (j < prices.size() && prices[j] <= prices[i])
            {
                prices[i] = prices[i] - prices[j];
                
            }
            i++;
            j = i ;
        }
    return prices;
    }
};