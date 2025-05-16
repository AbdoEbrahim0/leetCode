// //priorty queue
// class Solution {
// public:
//     long long pickGifts(vector<int>& gifts, int k) {
//         priority_queue<int ,vector<int>,less<>> pr;
//         for (int i = 0; i < gifts.size(); i++)
//         {
//             pr.push(gifts[i]);

//         }
//         long long val;
//         while ((k--) >= 1)
//         {
//             val= sqrt(pr.top());
//             pr.pop();
//             pr.push(val);
//         }
//         val = 0;
//         while ( ! pr.empty())
//         {
//             val += pr.top();
//             pr.pop();
//         }
//         return val;
//     }
// };

//heap
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        make_heap(gifts.begin(), gifts.end());
        while (k-- )
        {    
            pop_heap(gifts.begin(), gifts.end());
            // Take the square root of the largest element
            gifts.back() = sqrt(gifts.back());
            // Push the modified element back into the heap
            push_heap(gifts.begin(), gifts.end());
        }
        return accumulate(gifts.begin(),gifts.end(),0LL);
    }
};