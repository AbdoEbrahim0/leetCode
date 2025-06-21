//my naive sol  row scanning then column scanning for 1's
// class Solution {
// public:
//     int islandPerimeter(vector<vector<int>>& grid) {
//         int r = grid.size();
//         int c= grid[0].size();
//         int totalStrides ;
//         //totalStrides = r * c + r * (c - 1) + c * (r - 1);
//         totalStrides = 0;

//         for (int i = 0; i < r; i++)
//         {   
//             for (int j = 0; j < c; j++)
//             {
//                 if (grid[i][j] == 1)
//                 {
//                     totalStrides += 4;
//                     if (j + 1 < c && grid[i][j + 1] == 1)
//                         totalStrides-=2;       
//                 }
//             }
//         }

        
//         for (int j = 0; j < c; j++)
//         {
//             for (int i = 0; r > 1 && i < r; i++)
//             {
//                 while(i + 1 < r && grid[i][j] ==0)
//                 i++;
//                 while (i + 1 < r && grid[i][j] == 1)
//                 {
//                     //totalStrides += 4;
//                     if (i + 1 < r && grid[i+1][j] == 1)
//                         totalStrides-=2;
//                 i++;
//                 }

//             }
//         }
//         return totalStrides;
//     }
// };


//my naive sol row scanning then column scanning for 1's [optimized]
// class Solution {
// public:
//     int islandPerimeter(vector<vector<int>>& grid) {
//         int r = grid.size();
//         int c= grid[0].size();
//         int totalStrides ;
//         totalStrides = 0;

//         for (int i = 0; i < r; i++)
//         {   
//             for (int j = 0; j < c; j++)
//             {
//                 if (grid[i][j] == 1)
//                 {
//                     totalStrides += 4;
//                     if (j + 1 < c && grid[i][j + 1] == 1)
//                         totalStrides-=2;       
//                 }
//             }
//         }
//         for (int j = 0; j < c; j++)
//         {
//             for (int i = 0; r > 1 && i < r; i++)
//             {
//                 while(i + 1 < r && grid[i][j] ==0)
//                 i++;
//                 while (i + 1 < r && grid[i][j] == 1)
//                 {
//                     //totalStrides += 4;
//                     if (i + 1 < r && grid[i+1][j] == 1)
//                         totalStrides-=2;
//                 i++;
//                 }

//             }
//         }
//         return totalStrides;
//     }
// };


//my naive sol row scanning then column scanning for 1's [optimized^2]
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int r = grid.size();
        int c= grid[0].size();
        int totalStrides ;
        totalStrides = 0;
        // row scanning for 1's
        for (int i = 0; i < r; i++)
        {   
            for (int j = 0; j < c; j++)
            {
                while(j + 1 < c && grid[i][j] ==0)
                j++;
                if (grid[i][j] == 1)
                {
                    totalStrides += 4;
                    if (j + 1 < c && grid[i][j + 1] == 1)
                        totalStrides-=2;       
                }
            }
        }
        // column scanning for 1's
        for (int j = 0; j < c; j++)
        {
            for (int i = 0; r > 1 && i < r; i++)
            {
                while(i + 1 < r && grid[i][j] ==0)
                i++;
                while (i + 1 < r && grid[i][j] == 1)
                {
                    //totalStrides += 4;
                    if (i + 1 < r && grid[i+1][j] == 1)
                        totalStrides-=2;
                i++;
                }

            }
        }
        return totalStrides;
    }
};

//gpt sol
// class Solution {
// public:
//     int islandPerimeter(vector<vector<int>>& grid) {
//         int r = grid.size();
//         int c = grid[0].size();
//         int totalStrides = 0;

//         for (int i = 0; i < r; i++) {
//             for (int j = 0; j < c; j++) {
//                 if (grid[i][j] == 1) {
//                     totalStrides += 4;

//                     // Check right neighbor
//                     if (j + 1 < c && grid[i][j + 1] == 1)
//                         totalStrides -= 2;

//                     // Check bottom neighbor
//                     if (i + 1 < r && grid[i + 1][j] == 1)
//                         totalStrides -= 2;
//                 }
//             }
//         }

//         return totalStrides;
//     }
// };
