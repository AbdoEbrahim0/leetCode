int getSize(char* ransomNote)
{
    int c=0;
    while(ransomNote[c] !='\0')
    c++;

    return c; 
}
bool canConstruct(char* ransomNote, char* magazine) {
    int arr1[26] = {};
    int arr2[26] = {};
    int ranSize = getSize(ransomNote);
    int magSize = getSize(magazine);
    
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