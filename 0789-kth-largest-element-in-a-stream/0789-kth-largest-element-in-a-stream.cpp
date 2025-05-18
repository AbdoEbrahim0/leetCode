// class KthLargest {
//     int k2;
//     priority_queue<int,vector<int> ,greater<int> >pr;
// public:
//     KthLargest(int k, vector<int>& nums) {
//         k2=k;
//         for(int val : nums)
//         pr.push (val);
//         while (pr.size() >k2) 
//         pr.pop();
//     }
    
//     int add(int val) {
//         pr.push (val);
//         if(pr.size() >k2)
//         pr.pop();

//         return pr.top();
//     }
// };

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

class KthLargest {

public:
    //priority_queue <int, vector<int>, less<int>> pr;
    //vector<int>result;
    multiset<int> myMultiSet;
    int index;
    KthLargest(int k, vector<int>& nums) {
        for (int& val : nums)
            myMultiSet.insert(val);
        int mulSetSize = myMultiSet.size();
        index = mulSetSize - k;// index 0 based so minus 1
        
    }

     int add(int val) {
        myMultiSet.insert(val);
        index++;
         
        auto it = myMultiSet.begin();
        if (index >= 0 && index < myMultiSet.size()) {
            
            std::advance(it, index);  // Move to the element at index
                          // Remove that element
        }
        
        return *it;
    }
    /*vector<int> getResult()
    {
        return result;
    }*/

};
