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

//methode [1]//O(N) *O(M=diff) *O(sqrt(n))
// bool checkPrime(int x)
// {
//     if (x < 2)
//         return false;
//     //12
//     //1 2 3 4 | 3 4 6 12
//     for (int i = 2; i * i <= x; i++)
//     {
//         if (x % i == 0)
//             return false;
//     }
//     return true;
// }
// class Solution {
// public:

//     bool primeSubOperation(vector<int>& nums) {
//         int diff = 0;
//         for (int i = 0; i < nums.size(); i++) //O(N)
//         {
//             if (i == 0)
//                 diff = nums[i];
//             else
//             {
//                 diff = nums[i] - nums[i - 1];
//             }
//             if (diff <= 0)
//                 return false;

//             while (--diff && (!checkPrime(diff))); //O(M=diff) *O(sqrt(n))
//             nums[i] = nums[i] - diff;
//             if ( i && nums[i] <= nums[i - 1])
//                 return false;
//         }
//         return true;
//     }
// };
// methode [2] //O(n) + O(m log n)
class Solution {
public:
    vector<int> findprimesbefore(int maxnumberinarray) {
        vector<bool> isprime(maxnumberinarray +1, true);

        isprime[0] = isprime[1] = false; // 0 and 1 are not primes

        for (int i = 2; i * i <= maxnumberinarray; i++) {
            if (isprime[i]) {
                for (int j = i * i; j <= maxnumberinarray; j += i) {
                    isprime[j] = false;
                }
            }
        }
        vector<int> primes;
        for (int i = 0; i <= maxnumberinarray; i++)
        {
            if (isprime[i])
                primes.emplace_back(i);
        }
        return primes;
    }
    bool primeSubOperation(vector<int>& nums) {
        int diff = 0;
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int >primes = findprimesbefore(maxi);
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
            auto it = lower_bound(primes.begin(), primes.end(), diff); //binSearch on number greater or equal diff
            if (it != primes.begin())
         {
                   it--;
                nums[i] = nums[i] - *it;
        }
            
            if ( i && nums[i] <= nums[i - 1])
                return false;
        }
        return true;
    }
};

    //vector<int> v = { 4, 9, 6, 10 };
    //vector<int> v = { 6,8,11,12 };
    //vector<int> v = { 5,8,3};

    //vector<int> v = { 2,2 };
    //vector<int> v = { 11, 2, 10, 15, 19 };
    //vector<int> v = { 4, 3, 7, 4 };
    vector<int> v = { 15, 20, 17, 7, 16 };
    //vector<int> v = { 18, 12, 14, 6 };