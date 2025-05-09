// class Solution {
// public:
//     bool checkIfExist(vector<int>& arr) {
//         sort(arr.begin(), arr.end());
//         int i = 0;
//         for (int j = arr.size() - 1; j >= 0; j--)
//         {
//             /*if (arr.end()-1 == arr.begin() + j )
//                 cout << "TRUE";*/
//                 int half=(arr[j] / 2); //to pass test case [0,-2,2]
//                 if(half != arr[j])
//                 {
//                 if ((arr[j] %2==0) &&binary_search(arr.begin(), arr.begin() + j ,half ))
//                 return true;    
//     //wrong
//     // if (i < arr.size())
//     // {
//     //     if ((arr[j] %2==0) && binary_search(arr.begin() + (i + 1), arr.end(), (arr[i] / 2)))
//     //         return true;
//     // }
//                  }
//     //wrong
//     // if (binary_search(arr.begin(), arr.end(), arr[i] * 2)) {
//     //     return true;
//     //   }
//             if (binary_search(arr.begin(), arr.end(), arr[i] * 2)) {
//                 if (arr[i] != 0 || count(arr.begin(), arr.end(), 0) > 1)
//                     return true;
//             }
//             i++;
//         }
//         return false;
//     }
// };
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map <int, bool> unMap;
        for (int i = 0; i < arr.size(); i++)
        {
            if (unMap.count(arr[i] * 2))
                return true;
            if (arr[i]%2 ==0 && unMap.count(arr[i]/2))
                return true;
            unMap[arr[i]] = true;//to not check 2 times 
        }
    return false;
    }
};