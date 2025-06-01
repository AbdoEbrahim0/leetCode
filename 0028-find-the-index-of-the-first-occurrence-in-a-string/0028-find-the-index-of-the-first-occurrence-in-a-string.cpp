class Solution {
public:
    int strStr(string haystack, string needle) {
        /*int nd = -1;
        int ndSize = needle.size();
        for (char& c: haystack)
        {
            if (c == needle[++nd]) { ndSize--; }
            if (ndSize != 0)
                nd = -1;

        }*/
       int x= haystack.find(needle);
       
       return (x == string::npos) ? -1 : x;
           
    }
};