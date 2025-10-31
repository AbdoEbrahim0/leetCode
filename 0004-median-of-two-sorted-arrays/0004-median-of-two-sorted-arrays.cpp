class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      vector<int> BothArraysSorted;
      int TotSize=0;
      for(int i=0;i<nums1.size();i++)
      {
        TotSize++;
        BothArraysSorted.push_back(nums1[i]);
      }
      for(int j=0;j<nums2.size();j++)
      {
        TotSize++;
        BothArraysSorted.push_back(nums2[j]);
      }
       sort(BothArraysSorted.begin(), BothArraysSorted.end());
      if(!(TotSize&1))
      {
        return (BothArraysSorted[TotSize/2 ]+ BothArraysSorted[TotSize/2 -1 ])/2.0;
      }
      return BothArraysSorted[TotSize/2 ];


    }
};