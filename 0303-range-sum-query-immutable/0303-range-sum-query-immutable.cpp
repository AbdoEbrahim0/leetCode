// class NumArray {
// private:
//     vector<int> _nums;
// public:
//     NumArray(vector<int>& nums) {
//         this->_nums = nums;
//     }

//     int sumRange(int left, int right) {
//         int sum = 0;
//         for (int i = left; i <= right ; i++)
//         {
//             sum += _nums[i];
//         }
//         return sum;
//     }
// };


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

 //prefix sum
//  class NumArray {
// private:
//     vector<int> _nums;
//     int total = 0;
// public:
//     NumArray(vector<int>& nums) {
//         this->_nums = nums;
//         total = accumulate(nums.begin(), nums.end(), 0);
//     }
//     // [[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
//     int sumRange(int left, int right) {
//         int resLeft = 0, resRight = 0;
//         for (int i = 0; i < left; i++)
//         {
//             resLeft += _nums[i];
//         }
//         for (int i = right+1; i < _nums.size(); i++)
//         {
//             resRight += _nums[i];
//         }
//         return total-resLeft-resRight;
//     }
// };

 //prefix sum [optimized]
class NumArray {
private: vector<int> prefix;
public:
    NumArray(vector<int>& nums) {
        //{ -2, 0, 3, -5, 2, -1 }
        prefix.resize(nums.size() + 1, 0);
        for (int i = 0, j = 1; i < nums.size(); ++i, ++j) {
            prefix[j] = nums[i] + prefix[i];
        }
    }
    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};
