int getSize(char* word)
{
    int cnt = 0;
    while ((word[cnt] !='\0'))
    {
        cnt++;
    }
    return cnt;
}


bool detectCapitalUse(char* word) {
    int wordSize = getSize(word);
    
    int cap = 0;
    for (int i = 0; i < wordSize; i++)
    {
        
        if (word[i] >= 'A' && word[i] <= 'Z')
        {
            cap++;
        }
        

    }
    if (wordSize == cap || ( (word[0] >= 'A' && word[0] <= 'Z' )&& cap ==1) || cap==0)
        return true;
    return false;
}