//fail in next test case
//nums = [1, 72, 32, 2, 95, 67],  k = 121
// class Solution {
// public:
//     int minimumSubarrayLength(vector<int>& nums, int k) {
    
//         int maxi = nums[0];
//         int indx=0;
//         int sizeNums = nums.size();
//         for (int i = 1; i < sizeNums; i++)
//         {
//             // if (nums[i] <= k)
//             // {
                
//                 if (max(nums[i], maxi) > maxi )
//                 {
//                     maxi = max(nums[i], maxi);
//                     indx = i;
//                 }
//             // }
//         }
//         if (maxi >= k)
//             return 1;
//         int cnt_right= 200000, cnt_left= 200000,len=1;
//         int sum = nums[indx], sum_r,sum_l;
//         int j = indx + 1;//right
//         int jj = indx - 1;//left

//         for (; (j < sizeNums) || (jj >= 0); )
//         {
//             if((j < sizeNums))
//             sum_r = sum | nums[j];
//             if((jj >= 0))
//             sum_l = sum | nums[jj];
//             if ((sum_r > sum_l) && sum_r < k) //right
//             {
//                 sum = sum_r;
//                 len++;
//                 j++;
//             }
//             else if ((sum_l > sum_r) && sum_l < k)//left
//             {
//                 sum = sum_l;
//                 len++;
//                 jj--;
//             }
//             else
//             {
//                 sum = max(sum_r, sum_l);
//                 len++;
//                 break;
//             }       
//         }
//         if (sum >= k)
//             cnt_right = len;
//         if (cnt_right == 200000)
//             return -1;
//         return  cnt_right;
//     }
// };
// another way but not pass if sol is containing the nums[i] not on left or right 
//class Solution {
//public:
//    int minimumSubarrayLength(vector<int>& nums, int k) {
//    
//        int maxi = nums[0];
//        int indx=0;
//        int sizeNums = nums.size();
//        int window = 0;
//        if (sizeNums >= 3)
//        {
//            window = nums[0] | nums[1] | nums[2];
//        }
//        //[36,2,12,1]
//        
//        for (int i = 1; i < sizeNums ; i++)
//        {
//            //if (nums[i] <= k)
//            //{
//            if (sizeNums >= 3 && i< sizeNums -1)
//            {
//                
//                    
//                    if ((nums[i - 1] | nums[i] | nums[i + 1]) >= window && nums[i - 1] > nums[i] && nums[i - 1] > nums[i + 1])
//                    {
//                        window = (nums[i - 1] | nums[i] | nums[i + 1]);
//                        maxi = max(nums[i - 1], max(nums[i], nums[i + 1]));
//                        indx = i - 1;
//                    }
//                    else if ((nums[i - 1] | nums[i] | nums[i + 1]) >= window && nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
//                    {
//                        window = (nums[i - 1] | nums[i] | nums[i + 1]);
//                        maxi = max(nums[i - 1], max(nums[i], nums[i + 1]));
//                        indx = i;
//                    }
//                    else if ((nums[i - 1] | nums[i] | nums[i + 1]) >= window && nums[i + 1] > nums[i - 1] && nums[i + 1] > nums[i])
//                    {
//                        window = (nums[i - 1] | nums[i] | nums[i + 1]);
//                        maxi = max(nums[i - 1], max(nums[i], nums[i + 1]));
//                        indx = i + 1;
//                    }
//                
//            }
//            //else
//            //{
//            //    if (max(nums[i], maxi) > maxi)
//            //    {
//            //        maxi = max(nums[i], maxi);
//            //        indx = i;
//            //    }
//            //}
//            
//            //}
//        }
//        if (maxi >= k)
//            return 1;
//        int cnt_right= 200000, cnt_left= 200000,len=1;
//        int sum = nums[indx], sum_r,sum_l;
//        int j = indx + 1;//right
//        int jj = indx - 1;//left
//
//        for (; (j < sizeNums) || (jj >= 0); )
//        {
//            if((j < sizeNums))
//            sum_r = sum | nums[j];
//            if((jj >= 0))
//            sum_l = sum | nums[jj];
//            if ((sum_r > sum_l) && sum_r < k) //right
//            {
//                sum = sum_r;
//                len++;
//                j++;
//            }
//            else if ((sum_l > sum_r) && sum_l < k)//left
//            {
//                sum = sum_l;
//                len++;
//                jj--;
//            }
//            else
//            {
//                sum = max(sum_r, sum_l);
//                len++;
//                break;
//            }
//                
//        }
//        if (sum >= k)
//            cnt_right = len;
//        if (cnt_right == 200000)
//            return -1;
//        return  cnt_right;
//    }
//};

/////////// TLE 
// class Solution {
// public:
//     int minimumSubarrayLength(vector<int>& nums, int k) {
//         int n = nums.size();
//         int minLength = n + 1;

//         for (int i = 0; i < n; ++i) {
//             int curr_or = 0;
//             for (int j = i; j < n; ++j) {
//                 curr_or |= nums[j];
//                 if (curr_or >= k) {
//                     minLength = min(minLength, j - i + 1);
//                     break; // No need to continue from this i
//                 }
//             }
//         }
        
//         return (minLength == n + 1) ? -1 : minLength;
//     }
// };
//////////////////////////////
class Solution {
public:
    void update(int x, vector<int>& vis, int val)
    {
        for (int i = 0; i < 32; i++)
        {
            if ((x >> i) & 1)
                vis[i] += val;
        }
    }
    int getVal(vector<int>& vis)
    {
        int x = 0;
        for (int i = 0; i < 32; i++)
        {
            if(vis[i])
            x |= (1 << i);
        }
        return x;
    }
     int minimumSubarrayLength(vector<int>& nums, int k) {
         int n = nums.size();
         int st = 0, ed = 0, cur = INT_MAX;
         vector<int> vis(32);
         while (true)
         {
             if (getVal(vis) >= k && st < ed)
             {
                 cur = min(cur, ed - st);
                 update(nums[st], vis, -1);
                 st++;

             }
             else
             {
                 if (ed == n) break;
                 update(nums[ed++], vis, 1);
             }
         }
         if (cur == INT_MAX)
             return -1;

         return cur;
     }
 };
