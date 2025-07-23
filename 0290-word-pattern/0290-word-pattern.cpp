class Solution {
public:
    bool wordPattern(string pattern, string s) {
       
        unordered_map<char, string> charStringMap;
        unordered_map<string,char> stringCharMap;
        
        vector<string>vS;
        string val="";
        int sSize = s.size();
        int i;
        for (i= 0; i < sSize; i++)
        {
            if ( s[i] == ' ' || (i== sSize -1))
            {
                if (i == sSize - 1)
                    val += s[i];
                vS.emplace_back(val);
                val = "";
            }else
                val += s[i];   
        }
        
         if (vS.size() != pattern.size() )
            return false;
        for (int i = 0; i < vS.size(); i++)
        {
            if (stringCharMap.count(vS[i]))
            {
                if (stringCharMap[vS[i]] != pattern[i])
                    return false;
            }
            else
                stringCharMap[vS[i]] = pattern[i];
            ///-----------
            if (charStringMap.count(pattern[i]))
            {
                if (charStringMap[pattern[i]] != vS[i])
                    return false;
            }
            else
            charStringMap[pattern[i]] = vS[i];

        }

        //if (charStringMap.size() != stringCharMap.size())
        //    return false;
        //for (int z=0;z<pattern.size();z++)
        //{
        //    if (stringCharMap[vS[i]] != pattern[i] || charStringMap[pattern[i]] !=vS[i])
        //        return false;
        //    
        //}
        return true;
    }
};