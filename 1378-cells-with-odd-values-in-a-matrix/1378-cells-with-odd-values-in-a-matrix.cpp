class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        int oddSum = 0;
        vector<vector<int>> matrix;
        for (int i = 0; i < m; i++)
        {
            vector<int>v(n);
            matrix.push_back (v);
        }

        for (vector<int> rowCol : indices)
        {
            for (int j = 0; j < n; j++)
                matrix [rowCol[0]] [j]++; //increment row 
            for (int i = 0; i < m; i++)
                matrix[i] [rowCol[1]]++; //increment col
        }
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                if (matrix[i][j]  &1) oddSum++;
        }
        return oddSum;
    }
};