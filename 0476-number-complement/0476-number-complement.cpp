class Solution {
public:
    int findComplement(int num) {
        int x=0;
        int power = 0;
        while (num != 0)
        {
            
            if (num % 2 ==0)
            {
             //   x += pow(2, power); 
             //Or 
                x += 1<< power;
            }
            num = num / 2;
            power++;
        }
        return x;
    }
};