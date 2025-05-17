// //O(n^2log n)
// class Solution {
// public:
//     int rangeSum(vector<int>& nums, int n, int left, int right) {
//         //int sum = 0;
//         int* arr=new int[n];
//         arr[0] = nums[0];
//         //vector<int > combutedSubArray(n * (n + 1) / 2);
//         vector<int> combutedSubArray;
//         combutedSubArray.emplace_back(arr[0]);
//         for (int i = 1; i < n; i++)
//         {
//             arr[i] = arr[i - 1] + nums[i];
//             combutedSubArray.emplace_back(arr[i]);
//         }
//         for (int z =n- 1; z >= 0; z--)
//         {
//             int j = z - 1;
//             while (j >= 0)
//             {
//                 combutedSubArray.emplace_back(arr[z] - arr[j]);
//                 j--;
//             }
//         }
//         sort(combutedSubArray.begin(), combutedSubArray.end()); //O(n^2 log n^2)
//         const long long ONE_BILLION = 1e9;
//         return accumulate(combutedSubArray.begin() + left-1, combutedSubArray.begin() + right, 0LL) % (ONE_BILLION +7);
//     }
// };

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        
        vector<int>combutedSubArray;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += nums[j];
                combutedSubArray.emplace_back(sum);
            }
        }
        
        sort(combutedSubArray.begin(), combutedSubArray.end());
        const int mod= 1e9+7;
        return accumulate(combutedSubArray.begin() + left-1, combutedSubArray.begin() + right, 0LL) % mod;
        
    }
};
// //O(n^2 log n^2)
// class Solution {
// public:
//     int rangeSum(vector<int>& nums, int n, int left, int right) {


//         int* arr = new int[n];
//         arr[0] = nums[0];
//         priority_queue<int, vector<int>, greater<>>pr;
//         pr.push(arr[0]);
//         for (int i = 1; i < n; i++)//O(n)
//         {
//             arr[i] = arr[i - 1] + nums[i];
//             pr.push(arr[i]);
//         }

//         for (int z = n - 1; z >= 0; z--)//O(n) *O(n--) O(n^2)
//         {
//             int j = z - 1;
//             while (j >= 0)// O(n--)
//             {
//                 pr.push(arr[z] - arr[j]);
//                 j--;
//             }

//         }
//         vector<int >combutedSubArray;
//         while (!pr.empty())//O(size of subarray)
//         {
//             combutedSubArray.emplace_back(pr.top());
//             pr.pop();
//         }
//         const long long ONE_BILLION = 1e9;
//         return accumulate(combutedSubArray.begin() + left - 1, combutedSubArray.begin() + right, 0LL) % (ONE_BILLION + 7);

//     }
// };

// class Solution {
// public:
//     int rangeSum(vector<int>& nums, int n, int left, int right) {
//         const int MOD = 1e9 + 7;
//         using T = tuple<int, int, int>; // (sum, start_index, next_index)

//         priority_queue<T, vector<T>, greater<T>> minHeap;

//         // Initialize: each element nums[i] is a subarray starting and ending at i
//         for (int i = 0; i < n; ++i) {
//             minHeap.emplace(nums[i], i, i + 1);
//         }

//         long long result = 0;
//         int count = 0;

//         while (count < right) {
//             auto [sum, start, next] = minHeap.top();
//             minHeap.pop();
//             count++;

//             if (count >= left) {
//                 result = (result + sum) % MOD;
//             }

//             // If next < n, push the next subarray starting from 'start'
//             if (next < n) {
//                 int newSum = sum + nums[next];
//                 minHeap.emplace(newSum, start, next + 1);
//             }
//         }

//         return result;
//     }
// };
