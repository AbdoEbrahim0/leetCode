//(n1 log n1  +  n2 log n2) space : O(1)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end()); // O(n1 log n1)
        sort(nums2.begin(), nums2.end()); // O(n2 log n2)
        
        int i = 0, j = 0;
        vector<int> res;
        
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                ++i;
            } else if (nums1[i] > nums2[j]) {
                ++j;
            } else {
                // Avoid duplicates in result
                if (res.empty() || res.back() != nums1[i]) {
                    res.push_back(nums1[i]);
                }
                ++i;
                ++j;
            }
        }
        
        return res;
    }


};
//O(n1+n2)  space : O(N)
// class Solution {
// public:
//     vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//         int n1 = nums1.size();
//         int n2 = nums2.size();
//         //unordered_set <int>set1;
//         unordered_set <int>set2;
//         for (int i = 0; i < n2; i++)//o(N2)
//         {
//             set2.insert(nums2[i]);
//         }
//         vector<int>res;
//         for (int i = 0; i < n1 ; i++)//o(N1)
//         {
//             if (set2.count(nums1[i])) // avg O(1)
//                 res.emplace_back(nums1[i]);
//         }
//         set2.clear();
//         for (int z = 0; z < res.size(); z++)
//         {
//             set2.insert(res[z]);
            
//         }
//         res = vector<int>(set2.begin(), set2.end());
//         return res;
//     }
// };

//O(N)  space O(1)
// class Solution {
// public:
//     vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//         int n1 = nums1.size();
//         int n2 = nums2.size();
//         //unordered_set <int>set1;
//         int set2[1001] = {};
//         bool bSet2[1001] = {};
//         for (int i = 0; i < n2; i++)
//         {
//             set2[nums2[i]]++;
//             bSet2[nums2[i]] = true;
//         }
//         vector<int>res;
//         for (int i = 0; i < n1; i++)
//         {
//             if (set2[nums1[i]] && bSet2[nums1[i]])
//             {
//                 res.emplace_back(nums1[i]);
//                 bSet2[nums1[i]] = false;
//             }
            

//         }
//         return res;
//     }
// };