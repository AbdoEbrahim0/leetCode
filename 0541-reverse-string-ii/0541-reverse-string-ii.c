// char* reverseStr(char* s, int k) {
	
// 	int copyOfK = k;
// 	char* reversed = (char*)malloc(k * sizeof(char));
// 	if (!reversed) return s; // Safety check
// 	short idx = 0;
// 	for ( k = k - 1; k >= 0; k--)
// 	{
// 		*(reversed+idx) = s[k];
// 		idx++;
// 	}
// 	for (short x = 0; x < copyOfK; x++)
// 		s[x] = reversed [x];
// 	free(reversed); 
// 	return s;
// }
//worng understanding 
// char* reverseStr(char* s, int k) {
//     int copyOfK = k;
//     char* reversed = (char*)malloc(k * sizeof(char));
//     if (!reversed) return s; // Safety check

//     short idx = 0;
//     for (int i = k - 1; i >= 0; i--) {
//         reversed[idx++] = s[i];
//     }

//     for (int x = 0; x < copyOfK; x++) {
//         s[x] = reversed[x];
//     }

//     free(reversed); 
//     return s;
// }

void reverse(char* s, int start, int end) {
    while (start < end) {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}

char* reverseStr(char* s, int k) {
    int len = strlen(s);
    for (int i = 0; i < len; i += 2 * k) {
        int end = (i + k - 1 < len) ? i + k - 1 : len - 1;
        reverse(s, i, end);
    }
    return s;
}
