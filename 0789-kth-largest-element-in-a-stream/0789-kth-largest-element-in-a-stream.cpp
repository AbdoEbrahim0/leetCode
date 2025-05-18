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

//without change default multiset
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

//with change deafult multiset to avoid combute index [sorting in Descending  order]
// class KthLargest {
// public:
//     //priority_queue <int, vector<int>, less<int>> pr;
//     multiset<int, std::greater<>> myMultiSet;
//     int k;
//     KthLargest(int k, vector<int>& nums) {
//         for (int& val : nums)
//             myMultiSet.insert(val);
//         int mulSetSize = myMultiSet.size();
//         this->k= k-1;
//     }

//      int add(int val) {
//         myMultiSet.insert(val);
//         auto it = myMultiSet.begin();
//         std::advance(it, k);  // Move to the element at index
//         return *it;
//     }
// };

class KthLargest {
    priority_queue <int, vector<int>, greater<int>> pr;
    int k;
public:
    
    KthLargest(int k, vector<int>& nums) {
       this->k=k;
        for (int& val : nums)
        {
            pr.push(val);
            if (pr.size() > k)
                pr.pop();
        }
        
    }

    int add(int val) {
        pr.push(val);
        if (pr.size() > k)
            pr.pop();
        return  pr.top();
    }
};

