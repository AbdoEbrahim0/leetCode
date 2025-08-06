short getSize(char* ransomNote)
{
    short c=0;
    while(ransomNote[c] !='\0')
    c++;

    return c; 
}
bool canConstruct(char* ransomNote, char* magazine) {
    short arr1[26] = {};
    short arr2[26] = {};
    short ranSize = getSize(ransomNote);
    short magSize = getSize(magazine);
    
    for (int x = 0; x < ranSize; x++)
    {
        arr1[ransomNote[x] - 'a'] ++;
    }
    for (int x = 0; x < magSize; x++)
    {
        arr2[magazine[x] - 'a'] ++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (arr1[i])
            if (arr2[i] < arr1[i])
                return false;
    }
    return true;
}