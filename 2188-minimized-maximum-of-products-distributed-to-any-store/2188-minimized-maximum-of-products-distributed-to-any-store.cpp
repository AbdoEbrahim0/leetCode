//priorty ques and operator overloading
//O(m) +O(n-m) *log*O(n-m)
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

// class Solution {
//     struct data {
//         int quantity, stores;
//     };

// public:
//     int minimizedMaximum(int n, vector<int>& quantities) {
//         auto cmp = [](const data& a, const data& b) {
//             return 1LL * a.quantity * b.stores < 1LL * a.stores * b.quantity;
//         };
//         priority_queue<data, vector<data>, decltype(cmp)> pr(cmp);

//         int m = quantities.size();
//         for (int z = 0; z < m; z++) {
//             pr.push({ quantities[z], 1 });
//         }
//         //When you push/pop in priority_queue, it will use your overloaded operator< for sorting automatically.
//         for (int i = 0; i < n - m; i++) {
//             auto cur = pr.top(); 
//             pr.pop();
//             pr.push({ cur.quantity, cur.stores + 1 }); //add 1 safley as we always store old res in cur which can add 1 every time and save change inside pr_queue always
//         }
//         return ceil(1.0 * pr.top().quantity / pr.top().stores);
//     }
// };

//TLE
// class Solution {
// public:
//     int minimizedMaximum(int n, vector<int>& quantities) {
//         int sumQ = 0;
//         for (int val : quantities)
//             sumQ += val;
//         int sizeQ = quantities.size();
//         int mid = sumQ / n;
//         int stores = 0;
//         while (stores !=n)
//         {
//             stores = 0;
//             for (int i = 0; i < sizeQ; i++)
//             {
//                 if (quantities[i] % mid != 0)
//                     stores = stores + (quantities[i] / mid) + 1;
//                 else
//                     stores = stores + (quantities[i] / mid);
//             }
//             if (stores == n)
//                 return mid;
//             if (stores > n) mid++;
//             else if (stores < n) mid--;
//         }
//         return mid;
//     }
// };

//n log n
class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        //sort(quantities.begin(), quantities.end());
        int sizeQ = quantities.size();
        int st = 1;
        int end =100000;

        int mid, cur;
        int stores = 0;
                while (st<=end)
                {
                    mid = (st + end) / 2;
                    stores = 0;
                    // for (int i = 0; i < sizeQ; i++)
                    // {
                    // if (quantities[i] % mid != 0)
                    //     stores = stores + (quantities[i] / mid) + 1;
                    // else
                    //     stores = stores + (quantities[i] / mid);
                    // }
                    for(auto x: quantities)
                    {stores+=(x+mid-1 )/mid;}

                    if (stores <= n)
                    {
                        cur = mid;
                        end = mid - 1;
                    }else 
                        st = mid + 1;

                }
                return cur;
    }
};

