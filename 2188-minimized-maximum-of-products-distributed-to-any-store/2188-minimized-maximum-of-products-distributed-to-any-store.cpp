class Solution {
    struct  data
    {
        int quantity, stores;
        bool operator <(const data& other) const {
            return 1LL*quantity* other.stores <  1LL*stores* other.quantity;
        }
    };
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        priority_queue<data> pr;
        int m = quantities.size();
        for (int z = 0; z < m; z++)
        {
            pr.push({ quantities[z], 1 });
        }
        
        for (int i = 0; i < n - m; i++)
        {
            auto cur =pr.top() ;
            pr.pop();
            pr.push({ cur.quantity,cur.stores + 1 });

        }
        return ceil(1.0 * pr.top().quantity / pr.top().stores);
        //return ceil(pr.top().quantity / pr.top().stores);
    }
};