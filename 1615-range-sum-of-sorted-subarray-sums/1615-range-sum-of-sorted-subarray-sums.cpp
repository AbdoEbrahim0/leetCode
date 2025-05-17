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
//         sort(combutedSubArray.begin(), combutedSubArray.end());
//         const long long ONE_BILLION = 1e9;
//         return accumulate(combutedSubArray.begin() + left-1, combutedSubArray.begin() + right, 0LL) % (ONE_BILLION +7);
        
//     }
// };

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {


        int* arr = new int[n];
        arr[0] = nums[0];
        priority_queue<int, vector<int>, greater<>>pr;
        pr.push(arr[0]);
        for (int i = 1; i < n; i++)//O(n)
        {
            arr[i] = arr[i - 1] + nums[i];
            pr.push(arr[i]);
        }

        for (int z = n - 1; z >= 0; z--)//O(n) *O(n--) O(n^2)
        {
            int j = z - 1;
            while (j >= 0)// O(n--)
            {
                pr.push(arr[z] - arr[j]);
                j--;
            }

        }
        vector<int >combutedSubArray;
        while (!pr.empty())//O(size of subarray)
        {
            combutedSubArray.emplace_back(pr.top());
            pr.pop();
        }
        const long long ONE_BILLION = 1e9;
        return accumulate(combutedSubArray.begin() + left - 1, combutedSubArray.begin() + right, 0LL) % (ONE_BILLION + 7);

    }
};
