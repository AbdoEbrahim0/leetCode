class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {

        //int sum = 0;
        int* arr=new int[n];
        arr[0] = nums[0];
        //vector<int > combutedSubArray(n * (n + 1) / 2);
        vector<int> combutedSubArray;
        combutedSubArray.emplace_back(arr[0]);
        for (int i = 1; i < n; i++)
        {
            arr[i] = arr[i - 1] + nums[i];
            combutedSubArray.emplace_back(arr[i]);
        }
        
        /*for (int i = 0; i < 4; i++)
        {
            cout << arr[i] << endl;
        }*/
        for (int z =n- 1; z >= 0; z--)
        {
            int j = z - 1;
            while (j >= 0)
            {
                combutedSubArray.emplace_back(arr[z] - arr[j]);
                j--;
            }
        
        }
        sort(combutedSubArray.begin(), combutedSubArray.end());
        const long long ONE_BILLION = 1e9;
        return accumulate(combutedSubArray.begin() + left-1, combutedSubArray.begin() + right, 0LL) % (ONE_BILLION +7);
        
    }
};
