//methode  1  O(N^2)    
//class Solution {
//public:
//    int minLength(string s) {
//        bool foundAB = false, foundCD = false;
//         unsigned int indx;
//        while (true)
//        {
//            if ( s.find ( "AB") != string ::npos ) 
//            {
//                indx = s.find("AB");
//                foundAB = true;
//                s.erase(s.begin() + indx);
//                s.erase(s.begin() + indx);
//            }
//            if (s.find("CD") != string::npos)
//            {
//                indx = s.find("CD");
//                foundCD = true;
//                s.erase(s.begin() + indx);
//                s.erase(s.begin() + indx );
//            }
//            if (!(foundAB || foundCD)) 
//                break;
//            foundAB = false;
//            foundCD = false;
//        }       
//        return s.size();
//    }
//};


//methode 1 [optimized]  O(N)   
class Solution {
public:
    int minLength(string s) {
        string stack = "";
            stack+=s[0];
        for (int i=1 ; i<s.size();i++)
        {
            if (s[i] == 'B')
            {
                if (!stack.empty())
                {
                    if (stack[stack.size() - 1] != 'A')
                    {
                        stack += s[i];
                    }
                    else
                        stack.pop_back();       
                }else //to add B if it is last char in string which has no (opining A) before  
                stack += s[i];
            }
            else if (s[i] == 'D')
                {
                    if (!stack.empty() )
                    {
                        if (stack[stack.size() - 1] != 'C')
                        {
                            stack += s[i];
                        }
                        else
                            stack.pop_back();       
                    }else //to add D if it is last char in string which has no (opining C) before  
                        stack += s[i];
                }
            else
            {
                stack += s[i];
            }    
        }
        return stack.size();
    }
};
