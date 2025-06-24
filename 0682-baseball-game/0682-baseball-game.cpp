class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> out;
        int indx = -1;
        for (string& val : operations)
        {
            if (val == "+")
            {
             
                out.emplace_back(out[indx] + out[indx - 1]);
                indx++;
            }
            else if (val == "D")
            {
                
                out.emplace_back(out[indx] *2);
                indx++;
            }
            else if (val == "C")
            {
                indx--;
                out.pop_back();
            }
            else
            {
                
                out.emplace_back(stoi(val));
                indx++;
            }
        }
        return accumulate(out.begin(), out.end(), 0);
    }
};