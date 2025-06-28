// class Solution {
// public:
//     int minimumLength(string s) {
//         //abaacbcbb
//           //112312234
//           //    a b c
//           //    3%2=1 4%2=0  2/2=1 
//         int arr[26] = {};
//         for (char c : s)
//         {
//             arr[c - 'a']++;
//         }
//         int len=0;
//         for (int i = 0; i < 26; i++)
//         {
//             if (arr[i] && arr[i] % 2 == 0)
//                 len += 2;
//             else if (arr[i] && arr[i] % 2 == 1)
//                 len += 1;
//         } 
//         return len;
//     }
// };

//[optimized^2 in  time]
// class Solution {
// public:
//     int minimumLength(string s) {
//         //abaacbcbb
//           //112312234
//           //    a b c
//           //    3%2=1 4%2=0  2/2=1 
//         int arr[26] = {};
//         int sSize = s.size();
//         for (char c : s)
//         {
//             arr[c - 'a']++;
//             if (arr[c - 'a'] > 2)
//             {
//                     sSize -= 2;
//                     arr[c - 'a']=arr[c - 'a']-2;
//             }
//         }
        
//         return sSize;
//     }
// };
////[optimized^3 in  time and mem]
class Solution {
public:
    int minimumLength(string s) {
        //abaacbcbb
          //112312234
          //    a b c
          //    3%2=1 4%2=0  2/2=1 

        /*lyqkwhyy
        11111123*/
        bitset<26>vis1,vis2;
        
        int remove = 0;
        for (char c : s)
        {
            if (!vis1[c - 'a'])
                vis1[c - 'a'] = 1;
            else if (!vis2[c - 'a'])
                vis2[c - 'a'] = 1;
            else
            {
                remove += 2;
                vis2[c - 'a'] = 0;
            }
        }
        
        return s.size()-remove;
    }
};