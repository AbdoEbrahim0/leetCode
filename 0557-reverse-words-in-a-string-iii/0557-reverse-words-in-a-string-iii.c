//gpt

void reverseRange(char *s, int left, int right) {
    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

char* reverseWords(char* s) {
    int n = strlen(s);
    int start = 0;
    
    for (int i = 0; i <= n; i++) {
        if (s[i] == ' ' || s[i] == '\0') {
            reverseRange(s, start, i - 1);
            start = i + 1;
        }
    }
    
    return s;
}