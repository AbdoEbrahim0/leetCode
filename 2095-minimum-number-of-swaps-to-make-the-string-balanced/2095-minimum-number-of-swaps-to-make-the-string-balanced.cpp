class Solution {
public:
    int minSwaps(string s) {
       
int open = 0, problem = 0;
for (int i = 0; i < s.size(); i++) {
    if (s[i] == '[')
        open++;
    else {
        if (open)
            open--;
        else problem++;
    }
}
return ceil((double)problem/2);
    }
};
