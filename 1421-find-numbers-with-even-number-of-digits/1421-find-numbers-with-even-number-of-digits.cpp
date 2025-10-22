class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int EvenNumbersOfDigits=0;
        for(int &val :nums)
        {
            int x=log10(val);
            if((x+1) %2==0)
            EvenNumbersOfDigits++;
            //cout<< log10(val)+1<< "|" <<val << "#\n";
        }
        return EvenNumbersOfDigits;
    }
};

// 5
// 101      101
// 001 &    001 |
// 001      101
