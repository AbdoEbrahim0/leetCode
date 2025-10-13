class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        int size_of_output = 0;
        for (int i = 0; i < nums.size(); i += 2)
        {
            size_of_output += nums[i];
        }
        vector <int> res(size_of_output);
        short cnt = 0;
        for (int i = 0; cnt< size_of_output; i +=2 )
        {
            
            for (int j = 0; j < nums[i]; j++)
            {
                    {res[cnt++] = nums[i + 1];  
                    //cnt++;
                    }     
            }
        }
        
        return res;
    }
};