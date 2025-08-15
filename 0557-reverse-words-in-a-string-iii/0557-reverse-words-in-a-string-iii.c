// //gpt

// void reverseRange(char *s, int left, int right) {
//     while (left < right) {
//         char temp = s[left];
//         s[left] = s[right];
//         s[right] = temp;
//         left++;
//         right--;
//     }
// }

// char* reverseWords(char* s) {
//     int n = strlen(s);
//     int start = 0;
    
//     for (int i = 0; i <= n; i++) {
//         if (s[i] == ' ' || s[i] == '\0') {
//             reverseRange(s, start, i - 1);
//             start = i + 1;
//         }
//     }
    
//     return s;
// }

char* reverseWords(char* s) { 
	int idx = 0;
	int toSwap =0;
	char temp;
	int iterate = 0;
	char cur= *(s + idx);
	while (cur  != '\0')
	{
		
		while (*(s + idx) != ' ' && cur != '\0')
		{
			idx++;
			cur = *(s + idx);
		}
		toSwap = idx-1;
		while (  iterate< toSwap)
		{
			temp = s[iterate];
			s[iterate] = s[toSwap];
			s[toSwap] = temp;
			toSwap--;
			iterate++;
		}
		iterate = idx + 1;
		idx++;
	}
	return s;
}