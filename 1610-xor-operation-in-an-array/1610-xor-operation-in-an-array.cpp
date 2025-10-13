class Solution {
public:
    int xorOperation(int n, int start) {
        int* arr = new int(n);
        int sumXor = 0;
        for (int i = 0; i < n; i++)
            {sumXor ^= start + (2 * i);}
        
        return sumXor;
    }
};