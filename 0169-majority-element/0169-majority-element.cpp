//fail in negative numbers

// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         short n = nums.size();
//         int limit = n / 2;

//          vector<int> arr(*max_element(nums.begin(),nums.end()) +1) ;
//         for (int i = 0; i < n; i++)
//         {
//             arr[nums[i]]++;
//         }
//         for (int i = 0; i < arr.size(); i++)
//         {
//             if (arr[i] > limit)
//             {
//                 return i;
//             }
//         }
//         return 0;
//     }
// };
//Wrong Answer in case
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int limit = n / 2;
         unordered_map<int, int>u_mp;
         for (int i = 0; i < n; i++)
         {
             if (u_mp.find(nums[i]) != u_mp.end()) //avg case : O(1) 
             {
                 u_mp[nums[i]] = u_mp[nums[i]] + 1;
             }
             else
                 u_mp.insert({ nums[i], 1});
   
             if (u_mp[nums[i]] > limit)
                 return nums[i];
         }

        return 0;
    }
};

// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         int limit = n / 2;
         
//         long long maxE = *max_element(nums.begin(), nums.end());
//          vector<long long >PostiveOccuranences(maxE+1) ;
//          vector< long long> negativeOccurnences(maxE+1);
//          for (int i = 0; i < n; i++)
//          {
//              if (nums[i] < 0)
//              {
//                  negativeOccurnences[nums[i] * -1]++;
//                  if (negativeOccurnences[nums[i] * -1] > limit)
//                      return nums[i];
//              }
//              else
//              {
//                  PostiveOccuranences[nums[i]]++;
//                  if (PostiveOccuranences[nums[i]] > limit)
//                      return nums[i];
//              }
                
//          }

//         return 0;
//     }
// };

// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         int limit = n / 2;
//          unordered_map<int, int>u_mp;
//          for (int i = 0; i < n; i++)
//          {
             
//             u_mp[nums[i]] ++;
//              if (u_mp[nums[i]] > limit)
//                  return nums[i];
//          }

//         return 0;
//     }
// };

// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         unordered_map<int, int> freq;
//         int limit = nums.size() / 2;

//         for (int num : nums) {
            
//             freq[num]++;
//             if (freq[num] > limit)
//                 return num;
//         }
        
//         return 0; // Shouldn't reach here if input guarantees a majority
//     }
// };
