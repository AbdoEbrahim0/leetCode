
//time : O(N) space O(1)
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int index = 1;
        short searched = 0;
        short wordSize = searchWord.size();
        short senSize = sentence.size();
        for (int i = 0; i < senSize; i++)
        {
            while (sentence[i] == searchWord[searched])
            {
                searched++;
                i++;
                if (searched == wordSize)
                    return index;
            }
            
            if (sentence[i] != searchWord[searched])
                while (i < senSize && sentence[i] != ' ')
                {
                    i++;
                }
                searched = 0;
                if (sentence[i] == ' ')
                index++;
        }
        return -1;
    }
};