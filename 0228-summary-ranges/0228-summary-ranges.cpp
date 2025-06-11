class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size()==0)
        return {};
        vector<string> v;
        string s="";
        int end= nums[0],st = nums[0];
        /*
        Input: nums = [0,1,2,4,5,7]
        Output: ["0->2","4->5","7"]
        */
        for (int i=0 ;i< nums.size();i++)
        {

            while (i+1 < nums.size() && nums[i + 1] == nums[i] + 1)
            {
                end = nums[i + 1];
                i++;
            }
            if (i == nums.size() - 1)
                end = nums[i];
//            if (st == end)
            if (i + 1 < nums.size() && st == end)
            {
                v.push_back(to_string(nums[i])) ;
            }
            else
            {
                
                if (st < end)
                    s = to_string(st) + "->" + to_string(end);
                else
                    s = to_string(st);
                v.push_back(s);
            }
                if(i + 1 <nums.size())
                st = nums[i+1];
        }
        
        return v;
    }
};
