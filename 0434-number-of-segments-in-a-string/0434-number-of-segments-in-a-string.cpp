class Solution {
public:
    int countSegments(string s) {
        short c = 0;
        for (short  i=0;i< s.size();i++)
        {
             if ( s[i] != ' ')
             {
                c++;
                    while(i< s.size() && s[i] != ' ')
                        i++;      
             }
        }
        return (c);
    }
};