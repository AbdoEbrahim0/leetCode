/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 

// char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {
//     char** result = (char**)malloc(scoreSize * sizeof(char*)); //aray of char* which mean array of strings
//     int indx_1st = 0, indx_2nd = 0, indx_3rd = 0;
//     //[5,4,3,2,1]
//     int _1st = 0, _2nd = 0, _3rd = 0;
//     //for (int i = 0; i < scoreSize; i++)
//     //{
//     //    if (score[i] > _1st)
//     //    {
//     //        _3rd = _2nd;
//     //        _2nd = _1st;
//     //        _1st = score[i];//5
//     //    }
//     //    if (score[i] < _1st && score[i] > _2nd)
//     //    {
//     //        _3rd = _2nd;
//     //        _2nd = score[i];
//     //    }
//     //    if (score[i] < _2nd && score[i]> _3rd)
//     //        _3rd = score[i];
//     //}

//     bool* arranges = (bool*)calloc(scoreSize, sizeof(bool));
//     for (int i = 0; i < scoreSize; i++)
//     {
//         cout<<score[i] <<" ";
//     }
//     cout << "\n";

//     for (int i = 0; i < scoreSize; i++)
//     {
//         arranges[score[i]] = true;

//     }

//     int rank = 1;
//     int* ranks = (int*)calloc(1000001, sizeof(int));
//     for (int i = scoreSize - 1; i >= 0; i--)
//     {//10,3,8,9,4
//         int currentScore = score[i];
//         if (arranges[score[i]] == 1)
//             ranks[score[i]] = rank++;

//     }
//     for (int i = scoreSize-1; i >= 0; i--)
//     {//10,3,8,9,4
//         int currentScore = score[i];
//         if (arranges[score[i]] == 1)
//         {
//             ranks[score[i]] = rank++;
//             cout << score[i] << "," << rank - 1 << " ";
//         }
//         cout << endl;
        
//     }
    
//     for (int i = scoreSize-1; i >= 0; i--)
//     {//10,3,8,9,4
//         int currentScore = score[i];
//         if (arranges[score[i]] == 1)
//             ranks[score[i]] = rank++;
        
//     }
//     for (int i = 0; i < scoreSize; i++)
//     {
//         result[i] = (char*)malloc(13 * sizeof(char)); 
//         if (ranks[score[i]] == 1)
//         {
//                 result[i][0] = 'G';
//                 result[i][1] = 'o';
//                 result[i][2] = 'l';
//                 result[i][3] = 'd';
//                 result[i][4] = ' ';
//                 result[i][5] = 'M';
//                 result[i][6] = 'e';
//                 result[i][7] = 'd';
//                 result[i][8] = 'a';
//                 result[i][9] = 'l';
//                 result[i][10] = '\0';
            
//         }
//         else if (ranks[score[i]] == 2)
//         {
//             result[i][0] = 'S';
//             result[i][1] = 'i';
//             result[i][2] = 'l';
//             result[i][3] = 'v';
//             result[i][4] = 'e';
//             result[i][5] = 'r';
//             result[i][6] = ' ';
//             result[i][7] = 'M';
//             result[i][8] = 'e';
//             result[i][9] = 'd';
//             result[i][10] = 'a';
//             result[i][11] = 'l';
//             result[i][12] = '\0';
//         }
//         else if (ranks[score[i]] == 3)
//         {
//             result[i][0] = 'B';
//             result[i][1] = 'r';
//             result[i][2] = 'o';
//             result[i][3] = 'n';
//             result[i][4] = 'z';
//             result[i][5] = 'e';
//             result[i][6] = ' ';
//             result[i][7] = 'M';
//             result[i][8] = 'e';
//             result[i][9] = 'd';
//             result[i][10] = 'a';
//             result[i][11] = 'l';
//             result[i][12] = '\0';
//         }
//         else
//         {
//             int num = ranks[score[i]] , len = 0, temp = ranks[score[i]] == 1;

//             // find number length
//             while (temp > 0) {
//                 len++;
//                 temp /= 10;
//             }

//             // fill string from end
//             result[i][len] = '\0';
//             for (int j = len - 1; j >= 0; j--) {
//                 result[i][j] = (num % 10) + '0';
//                 num /= 10;
//             }
//         }       
//     }
//     *returnSize = scoreSize;
//     return result;
// }
typedef struct {
    int score;
    int index;
} Athlete;

int compare(const void *a, const void *b) {
    return ((Athlete*)b)->score - ((Athlete*)a)->score; // descending order
}

char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {
    *returnSize = scoreSize;
    char **result = (char**)malloc(scoreSize * sizeof(char*));
    
    Athlete *arr = (Athlete*)malloc(scoreSize * sizeof(Athlete));
    for (int i = 0; i < scoreSize; i++) {
        arr[i].score = score[i];
        arr[i].index = i;
    }
    
    // Sort scores descending
    qsort(arr, scoreSize, sizeof(Athlete), compare);
    
    for (int i = 0; i < scoreSize; i++) {
        result[arr[i].index] = (char*)malloc(20 * sizeof(char)); // enough space for rank number
        
        if (i == 0) {
            strcpy(result[arr[i].index], "Gold Medal");
        } else if (i == 1) {
            strcpy(result[arr[i].index], "Silver Medal");
        } else if (i == 2) {
            strcpy(result[arr[i].index], "Bronze Medal");
        } else {
            sprintf(result[arr[i].index], "%d", i + 1);
        }
    }
    
    free(arr);
    return result;
}
