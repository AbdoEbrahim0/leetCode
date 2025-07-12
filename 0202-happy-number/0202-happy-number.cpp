// class Solution {
// public:
//     bool isHappy(int n) {
//         //n=19 true  ,  n=2 = false
//         // realize that only happy number is when n=1 OR n=10 OR n=100 OR n=1000 etc  
//         //2,147,483,648   1 000 000 000
//         //important  :: in case 2 4 16 37 58 89 145 42 20  4 16
//         int x = 0;
//         unordered_set<int>mySet;
//         string s;
//         while (n!=1 )
//         {
//             s = to_string(n);
//             for (int i = 0; i < s.size(); i++)
//             {
//                 x += (s[i] - '0')* (s[i] - '0');
//             }
//             if (mySet.count(x))
//                 return 0;
//             mySet.insert(x);
//             n = x;
//             x = 0;
//         }
//         return n==1;
//     }
// };
//optimized ^2
// class Solution {
// public:
//     bool isHappy(int n) {
//         //n=19 true  ,  n=2 = false
//         // realize that only happy number is when n=1 OR n=10 OR n=100 OR n=1000 etc  
//         //2,147,483,648   1 000 000 000
//         //important  :: in case 2 4 16 37 58 89 145 42 20  4 16
//         unordered_set<int>mySet;
//         string s;
//         while (n!=1 )
//         {
//             s = to_string(n);
//             n = 0;
//             for (int i = 0; i < s.size(); i++)
//             {
//                 n += (s[i] - '0')* (s[i] - '0');
//             }
//             if (mySet.count(n))
//                 return 0;
//             mySet.insert(n);
//         }
//         return true;
//     }
// };
class Solution {
public:
    bool isHappy(int n) {
        //n=19 true  ,  n=2 = false
        // realize that only happy number is when n=1 OR n=10 OR n=100 OR n=1000 etc  
        //2,147,483,648   1 000 000 000
        //important  :: in case 2 4 16 37 58 89 145 42 20  4 16
        bitset<1000000 + 1> vis;
        //unordered_set<int>mySet;
        string s;
        while (n != 1)
        {
            s = to_string(n);
            n = 0;
            for (int i = 0; i < s.size(); i++)
                n += (s[i] - '0') * (s[i] - '0');
            
            if (vis[n])
                return 0;
            vis[n] = true;
        }
        return true;
    }
};


// class Solution {
//     public:
//     bool isHappy(int n) {
//         unordered_set<int> seen;

//         while (n != 1 && !seen.count(n)) {
//             seen.insert(n);
//             n = getNext(n);
//         }

//         return n == 1;
//     }

// private:
//     int getNext(int n) {
//         int total = 0;
//         while (n > 0) {
//             int digit = n % 10;
//             total += digit * digit;
//             n /= 10;
//         }
//         return total;
//     }
// };