class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int min = 100001;
        for(int i=1;i<arr.size();i++)
        if(arr[i] - arr[i-1] <min)
            min= arr[i] - arr[i - 1];

        vector<vector<int>> res;
        for (int z = 1; z < arr.size(); z++)
        {
            if (arr[z] - arr[z - 1] == min)
            {
                res.push_back({arr[z-1] ,arr[z]});// 
                //push_back can take variable vector or directly numbers [values]
                //emplace_back expects constructor arguments,
            }
        }
        return res;
    }
};