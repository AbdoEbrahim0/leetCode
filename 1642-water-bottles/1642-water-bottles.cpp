class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int cnt = numBottles;
        int empty = numBottles;
        
            while (empty >= numExchange)
            {
                
                         //15/4=3    6/4=1
                cnt += (empty / numExchange);  //15+3=18  18+(6/4)
                empty = empty / numExchange + (empty % numExchange);//3+3=6   6/4+6%4 1+2=3    1+3
                
                //numBottles= exchange;
                 // 3%4=3
            }
        return cnt;
    }
};