#include <stdio.h>
#include <string.h>

int longestPalindrome(char* s) {
    int freq[128] = {0}; // store character frequencies (ASCII)
    int len = strlen(s);

    // Count frequencies
    for (int i = 0; i < len; i++) {
        freq[(int)s[i]]++;
    }

    int length = 0;
    int oddFound = 0;

    for (int i = 0; i < 128; i++) {
        length += (freq[i] / 2) * 2; // add pairs
        if (freq[i] % 2 == 1) {
            oddFound = 1; // can put one odd char in the middle
        }
    }

    if (oddFound) {
        length += 1;
    }

    return length;
}
