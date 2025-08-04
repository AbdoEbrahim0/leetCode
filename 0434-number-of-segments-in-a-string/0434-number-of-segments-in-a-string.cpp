class Solution {
public:
    int countSegments(string s) {
        int c = 0;
        for (int i=0;i< s.size();i++)
        {
             if ( s[i] != ' ')
             {
                c++;
                    while(i< s.size() && s[i] != ' ')
                    {
                        i++;
                    }

             }
            // if (s[i] == ' ')
            //     if (i -1 >=0 && s[i-1] != ' ')
            //         c++;
            // else
        }
        //return (c) ? c+1:c;
        return (c);
    }
};