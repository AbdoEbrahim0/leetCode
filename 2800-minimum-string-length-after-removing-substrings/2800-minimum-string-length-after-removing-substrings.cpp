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
                //cout << indx << " ";
                foundAB = true;
                s.erase(s.begin() + indx);
                s.erase(s.begin() + indx);
            }
            if (s.find("CD") != string::npos)
            {
                indx = s.find("CD");
             //   cout << indx << " ";
                foundCD = true;
                s.erase(s.begin() + indx);
                s.erase(s.begin() + indx );
            }

            if (!(foundAB || foundCD)) return s.size();
            foundAB = false;
            foundCD = false;
            

        }
        return 0;
    }
};