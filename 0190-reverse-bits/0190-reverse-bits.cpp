class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        //00000010100101000001111010011100 43261596
        //00111001011110000010100101000000 964176192
        for (int i = 31; i >= 0; i--)
        {
            if (n  & 1) 
                result += (1<<i);
            n = (n >> 1) ;
        }
        return result;
    }
};
































        // for (int i = 0; i < 32; ++i) {
        //     result <<= 1;           // Make space for the next bit
        //     result |= (n & 1);      // Add the last bit of n to result
        //     n >>= 1;                // Move to the next bit
        // }
        
        // return result;