/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
    char** result = (char**)malloc(n * sizeof(char*));

    for (int i = 1; i <= n; i++) {
        result[i - 1] = (char*)malloc(9 * sizeof(char)); // enough for "FizzBuzz"

        if (i % 3 == 0 && i % 5 == 0) {
            result[i - 1][0] = 'F';
            result[i - 1][1] = 'i';
            result[i - 1][2] = 'z';
            result[i - 1][3] = 'z';
            result[i - 1][4] = 'B';
            result[i - 1][5] = 'u';
            result[i - 1][6] = 'z';
            result[i - 1][7] = 'z';
            result[i - 1][8] = '\0';
        }
        else if (i % 3 == 0) {
            result[i - 1][0] = 'F';
            result[i - 1][1] = 'i';
            result[i - 1][2] = 'z';
            result[i - 1][3] = 'z';
            result[i - 1][4] = '\0';
        }
        else if (i % 5 == 0) {
            result[i - 1][0] = 'B';
            result[i - 1][1] = 'u';
            result[i - 1][2] = 'z';
            result[i - 1][3] = 'z';
            result[i - 1][4] = '\0';
        }
        else {
            // Convert number to string without sprintf
            int num = i, j = 0;
            char temp[10];
            if (num == 0) {
                temp[j++] = '0';
            }
            else {
                while (num > 0) {
                    temp[j++] = (num % 10) + '0';
                    num /= 10;
                }
            }
            // Reverse the digits
            for (int k = 0; k < j; k++) {
                result[i - 1][k] = temp[j - k - 1];
            }
            result[i - 1][j] = '\0';

        }
        printf("%s   ", result[i - 1]);
    }

    *returnSize = n;
    return result;
}
