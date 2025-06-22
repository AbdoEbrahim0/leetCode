// 
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int cnt = numBottles;
        
        
            while (numBottles >= numExchange)
            {
                int newBottles=(numBottles / numExchange);
                cnt += newBottles;  //15+3=18  18+(6/4)
                //empty = exchangedbottles + remain empty bottles
                numBottles = newBottles + (numBottles % numExchange);//3+3=6   6/4+6%4 1+2=3    1+3
            }
        return cnt;
    }
};