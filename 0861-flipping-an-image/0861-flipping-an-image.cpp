class Solution {
    vector<vector<int>> Flipped(vector<vector<int>>& image)
    {
        for (vector<int> &var : image)
        {
            reverse(var.begin(), var.end());
        }
        return image;
    }
    vector<vector<int>> Invert(vector<vector<int>>& image)
    {
        Flipped(image);
        for (int i = 0; i < image.size(); i++)
        {
            for (int j = 0; j < image[i].size(); j++)
            {
                image[i][j] = !image[i][j];
            }
        }
        return image;
    }

public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        return Invert(image);
    }
};
/*
//in
[1,1,0]
[1,0,1]
[0,0,0]

//flip
[0,1,1]
[1,0,1]
[0,0,0]
//invert 
[1,0,0]
[0,1,0]
[1,1,1]
*/