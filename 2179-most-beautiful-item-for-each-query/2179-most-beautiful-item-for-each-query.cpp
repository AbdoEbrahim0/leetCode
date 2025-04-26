// class Solution {
// public:
//     vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {

//         sort(items.begin(), items.end(), [](const vector<int>& a, const vector<int>& b)
//             {
//             return a[0] < b[0];
//             });

//         vector<int>itemsPrices;
//         for (vector<int> &val : items)
//             itemsPrices.emplace_back(val[0]);
        
//         int itemsSize = items.size();
//         vector<int>itemsBeauty(itemsSize);
//         int maxi = 0;
//         for (int i=0;i<itemsSize;i++)
//         {
//             itemsBeauty[i] = items[i][1];
//             if (i)
//             {
//             maxi = max(maxi, items[i][1]);
//             itemsBeauty[i] = maxi;

//             }    
//         }
//         int QuereySize = queries.size();
//         vector<int> ans(QuereySize);
        
//         for (int z=0;z<QuereySize ;z++)
//         {
//             int start = 0, end = itemsSize - 1;
//             int mid,cur=-1;
//             while (start <= end)
//             {
//                 mid =( start + end) / 2;
//                 if (queries[z] >= itemsPrices[mid])
//                 {
//                     cur = mid;
//                     start = mid + 1;
//                 }
//                 else
//                     end = mid - 1;

//             }
//             if (cur == -1)
//                 ans[z]=0;
//             else 
//                 ans[z]=itemsBeauty[cur];
//         }
//         return ans;
//     }
// };
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {

        sort(items.begin(), items.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        vector<int> itemsPrices;
        for (vector<int> &val : items)
            itemsPrices.emplace_back(val[0]);
        
        int itemsSize = items.size();
        vector<int> itemsBeauty(itemsSize);
        int maxi = 0;
        for (int i = 0; i < itemsSize; i++)
        {
            maxi = max(maxi, items[i][1]);  // ✅ fix here
            itemsBeauty[i] = maxi;
        }
        
        int querySize = queries.size();
        vector<int> ans(querySize);
        
        for (int z = 0; z < querySize; z++)
        {
            int start = 0, end = itemsSize - 1;
            int mid, cur = -1;
            while (start <= end)
            {
                mid = (start + end) / 2;
                if (queries[z] >= itemsPrices[mid])
                {
                    cur = mid;
                    start = mid + 1;
                }
                else
                    end = mid - 1;
            }
            if (cur == -1)
                ans[z] = 0;
            else 
                ans[z] = itemsBeauty[cur];
        }
        return ans;
    }
};
