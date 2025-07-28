// class Solution {
// public:
//     int thirdMax(vector<int>& nums) {
//         if (nums.size() < 3)
//             return *max_element(nums.begin(), nums.end());
//         sort(nums.begin(), nums.end());
//             return nums[nums.size() - 3];
//     }
// };
// 1 2 2 3
// class Solution {
// public:
//     int thirdMax(vector<int>& nums) {
//         set<int > mySet(nums.begin(), nums.end());
//         int mySetSize = mySet.size();
        
//         if (mySetSize < 3)
//         {
//             auto it=mySet.end();
//             it--;
//             return *it;
//         }
//         int i = 0;
//         nums.resize(mySet.size());
//         for (auto it = mySet.begin(); i< mySet.size(); it++)
//         {
//             nums [i++] = *it;
//         }
//         return nums[nums.size()- 3];
//     }
// };

// class Solution {
// public:
//     int thirdMax(vector<int>& nums) {
//         set<int > mySet(nums.begin(), nums.end());
//         int mySetSize = mySet.size();
//         auto it=mySet.end();
//         if (mySetSize < 3)
//         {
//             it--;
//             return *it;
//         }
//         it--;
//         it--;
//         it--;
//         return *(it);
//     }
// };
//priorty queue
// class Solution {
// public:
//     int thirdMax(vector<int>& nums) {
//         unordered_set<int> mySet;
//         priority_queue<int, vector<int>, greater<int>> pr;
//         for (int val :nums)
//         {
//             //{ 3,5,8,20 };
//             //{ 1,2,5,3,5,20 }
//             if ( mySet.count(val) ==0)
//             {
//                 pr.push(val);
//                 mySet.insert(val);
//             }
//             if (pr.size() > 3)
//                 pr.pop();
//         }

//         if (mySet.size()<3)
//             return *max_element(nums.begin(), nums.end());
//         return pr.top();
//     }
// };
// priorty queue
// class Solution {
// public:
//     int thirdMax(vector<int>& nums) {
//         unordered_set<int> mySet(nums.begin(), nums.end());
//         if (mySet.size() < 3)
//             return *max_element(nums.begin(), nums.end());
//         priority_queue<int, vector<int>, greater<int>> pr;
//         for (auto it=mySet.begin();it !=mySet.end();it++)
//         {
//             //{ 3,5,8,20 };
//             //{ 1,2,5,3,5,20 }
//                 pr.push(*it);
//             if (pr.size() > 3)
//                 pr.pop();
//         }
//         return pr.top();
//     }
// };

//
//optimized ^4
// class Solution {
// public:
//     int thirdMax(vector<int>& nums) {
//         unordered_set<int> mySet(nums.begin(), nums.end());

//         if (mySet.size() < 3)
//             return *max_element(mySet.begin(), mySet.end());

//         priority_queue<int, vector<int>, greater<int>> minHeap;

//         for (int num : mySet) {
//             minHeap.push(num);
//             if (minHeap.size() > 3)
//                 minHeap.pop(); // Remove smallest to keep 3 largest
//         }

//         return minHeap.top(); // Third maximum
//     }
// };


//gpt best performance 
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;

        for (int num : nums) {
            if (num == first || num == second || num == third)
                continue;

            if (num > first) {
                third = second;
                second = first;
                first = num;
            }
            else if (num > second) {
                third = second;
                second = num;
            }
            else if (num > third) {
                third = num;
            }
        }

        return third == LONG_MIN ? first : third;
    }
};
