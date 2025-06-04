class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //{ 4, 1, 2, 1, 2 };
        int n = nums.size();
        vector<int> negative ;
        //fill(negative.begin(), negative.end(), false);
        int maxE = *max_element(nums.begin(), nums.end());
        vector< int >arr (maxE + 1);
        //fill(negative.begin(), negative.end(), false);
        for (int i=0;i<nums.size();i++)
        {
            if (nums[i] < 0)
                negative.emplace_back(nums[i]*-1);
            else
                arr[nums[i]]++;
        }
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == 1)
                return i;
        }

        //ceck negative vals
        maxE = *max_element(negative.begin(), negative.end());
        vector< int >arr2(maxE + 1);
        for (int i = 0; i < negative.size(); i++)
        {
                arr2[negative[i]]++;
        }
        for (int i = 0; i < arr2.size(); i++)
        {
            if (arr2[i] == 1)
                return i*-1;
        }
        
        return 0;
    }
};