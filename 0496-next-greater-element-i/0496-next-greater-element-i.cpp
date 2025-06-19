class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
                int arr[10001] = {};
        // nums1 = [4,1,2], nums2 = [1,3,4,2]
        vector<int>ans;
        for (int i = 0; i< nums2.size(); i++)
        {
            arr[nums2[i]]=i;
        }
        for (int j = 0; j < nums1.size(); j++)
        {
            int s =arr[nums1[j]] ;
            ans.emplace_back(-1);
            while (s<nums2.size())
            {
                if (nums1[j] < nums2[s])
                {
                    ans.pop_back();
                    ans.emplace_back(nums2[s]);
                    break;
                }
                s++;
            }
        }

        return ans;
    }
};