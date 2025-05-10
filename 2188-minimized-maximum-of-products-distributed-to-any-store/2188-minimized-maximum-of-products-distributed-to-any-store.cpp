//priorty ques and operator overloading

// class Solution {
//     struct  data
//     {
//         int quantity, stores;
//         bool operator <(const data& other) const {
//             return 1LL*quantity* other.stores <  1LL*stores* other.quantity;
//         }
//     };
// public:
//     int minimizedMaximum(int n, vector<int>& quantities) {
//         priority_queue<data> pr;
//         int m = quantities.size();
//         for (int z = 0; z < m; z++)
//         {
//             pr.push({ quantities[z], 1 });
//         }
//         for (int i = 0; i < n - m; i++)
//         {
//             auto cur =pr.top() ;
//             pr.pop();
//             pr.push({ cur.quantity,cur.stores + 1 });
//         }
//         return ceil(1.0 * pr.top().quantity / pr.top().stores);
//         //return ceil(pr.top().quantity / pr.top().stores);
//     }
// };

class Solution {
    struct data {
        int quantity, stores;
    };

public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        auto cmp = [](const data& a, const data& b) {
            return 1LL * a.quantity * b.stores < 1LL * a.stores * b.quantity;
        };
        priority_queue<data, vector<data>, decltype(cmp)> pr(cmp);

        int m = quantities.size();
        for (int z = 0; z < m; z++) {
            pr.push({ quantities[z], 1 });
        }

        for (int i = 0; i < n - m; i++) {
            auto cur = pr.top();
            pr.pop();
            pr.push({ cur.quantity, cur.stores + 1 });
        }

        auto top = pr.top();
        return (top.quantity + top.stores - 1) / top.stores; // Ceil division without floating point
    }
};