//methode 1    
class Solution {
public:
    int minLength(string s) {
        bool foundAB = false, foundCD = false;
         unsigned int indx;
        while (true)
        {

            if ( s.find ( "AB") != string ::npos ) 
            {
                indx = s.find("AB");
                foundAB = true;
                s.erase(s.begin() + indx);
                s.erase(s.begin() + indx);
            }
            if (s.find("CD") != string::npos)
            {
                indx = s.find("CD");
                foundCD = true;
                s.erase(s.begin() + indx);
                s.erase(s.begin() + indx );
            }
            if (!(foundAB || foundCD)) 
                break;
            foundAB = false;
            foundCD = false;
        }
        return s.size();
    }
};