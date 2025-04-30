//next code fail in 588/654 test case [15,20,17,7,16]
// vector<bool> findPrimesBefore(int maxNumberInArray) {
//     vector<bool> isPrime(maxNumberInArray, true);

//     isPrime[0] = isPrime[1] = false; // 0 and 1 are not primes

//     for (int i = 2; i * i < maxNumberInArray; i++) {
//         if (isPrime[i]) {
//             for (int j = i * i; j < maxNumberInArray; j += i) {
//                 isPrime[j] = false;
//             }
//         }
//     }
//     return isPrime;
// }
// bool isStrictlySorted(int st_i, vector<int>vv)
// {
//     while (st_i < vv.size()-1)
//     {
//         if (vv[st_i+1] > vv[st_i])
//         {
//             st_i++;
//         }
//         else
//         {
//             st_i++;
//             if (st_i && vv[st_i]<= vv[st_i -1])
//                 return false;
//         }       
//     }
//     if ((st_i >=2) && vv[st_i-1] <= vv[st_i - 2]  || ( st_i && vv[st_i] <= vv[st_i - 1] ))
//         return false;
//     return true;
// }

// class Solution {
// public:
//     bool primeSubOperation(vector<int>& nums) {
//         int MaxElement = *max_element(nums.begin(), nums.end());
//         vector<bool> Primes = findPrimesBefore(MaxElement);
//         int sub;
//         int largePrime;
//         for (int i = 0; i < nums.size();i++)
//         {
//             if ( (i && nums[i] <= nums[i - 1]))
//                 return false;
//             if (isStrictlySorted(i, nums))
//             {return true; }
//             else if (nums[i] <= 2)
//             {
//                 nums[i] = nums[i];
//             }
//             else
//             {
//                 largePrime = nums[i] - 1;
//                 while (!Primes[largePrime])
//                 {
//                     largePrime--;
//                 }
//                     sub = nums[i] - largePrime;
//                     nums[i] = sub;
//                     if ((i && nums[i] <= nums[i - 1]))
//                         return false;   
//             }   
//         }
//         return false;
//     }
// };
bool checkPrime(int x)
{
    if (x < 2)
        return false;
    //12
    //1 2 3 4 | 3 4 6 12
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}
class Solution {
public:

    bool primeSubOperation(vector<int>& nums) {
        int diff = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0)
                diff = nums[i];
            else
            {
                diff = nums[i] - nums[i - 1];
            }
            if (diff <= 0)
                return false;

            while (--diff && (!checkPrime(diff)));
            nums[i] = nums[i] - diff;
            if ( i && nums[i] <= nums[i - 1])
                return false;
        }
        return true;
    }
};