class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int row = matrix.size(), col = matrix[0].size();

        for (int i = 0; i < row; i++)
        {
            for (int j = i + 1; j < col; j++)
                swap(matrix[j][i], matrix[i][j]);
        }

        for (int i = 0; i < row; i++)
            reverse(matrix[i].begin(), matrix[i].end());
    }
};

/*
Flip Flip, all by myself - 48 ms

Similar again, but I first transpose and then flip left-right instead of upside-down,
and do it all by myself in loops. This one is 100% in-place again in the sense of just moving the elements.
*/