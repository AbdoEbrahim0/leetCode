
// all i care about is odd as 3 =2+1 neglect 2 as it is palindrome by nature 
// so count odds and compare to k if odd<= k then can make k number of palidrome
// class Solution {
//  public:
//      bool canConstruct(string s, int k) {
//          if (k>s.size())
//          return false;
//          short arr[26];
//          int odd = 0;
//          for (char c : s)
//              arr[c - 'a']++;
//          for (int i = 0; i < 26; i++)//count 1's 
//          {
//              if (arr[i] & 1)
//                  odd++;
//          }
//          if (odd > k)
//              return false;
//          return true;
//      }
//  };
//optimized^2
// class Solution {
//  public:
//      bool canConstruct(string s, int k) {
//          if (k>s.size())
//          return false;
//          bool arr[26];
//          int odd = 0;
//          for (char c : s)
//              arr[c - 'a'] =!arr[c - 'a'];
//          for (int i = 0; i < 26; i++)//count 1's 
//          {
//              if (arr[i] & 1)
//                  odd++;
//          }
//          if (odd > k)
//              return false;
//          return true;
//      }
//  };
 //optimized^3 instead of  1 byte for ech boolean we use 1 bit for each 
// class Solution {
//  public:
//      bool canConstruct(string s, int k) {
//          if (k>s.size())
//          return false;
//          bitset<26>freq;
//          int odd = 0;
//          for (char c : s)
//              freq[c - 'a'] =!freq[c - 'a'];
//          for (int i = 0; i < 26; i++)//count 1's 
//          {
//              if (freq[i] & 1)
//                  odd++;
//          }
//          if (odd > k)
//              return false;
//          return true;
//      }
//  };

class Solution {
public:
    bool canConstruct(string s, int k) {
        if (k > s.size())
            return false;
         int freq=0;
        int odd = 0;
        //as int 4 byte and bits=32 bit
        for (char c : s)
            freq=freq ^ (1 << c - 'a');  //shift left to set the  bit by 1  then apply XOR on current state

        for (int i = 0; i < 32; i++)//count 1's 
        {
            if ((freq>>i) &1) //wrong code if (freq>>i )
                odd++;
        }
        if (odd > k)
            return false;
        return true;
    }
};