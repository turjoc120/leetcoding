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

Almost as Direct - 40 ms

If you don't like the little repetitive code of the above "Most Direct" solution,
 we can instead do each four-cycle of elements by using three swaps of just two elements.

Flip Flip, all by myself - 48 ms

Similar again, but I first transpose and then flip left-right instead of upside-down,
and do it all by myself in loops. This one is 100% in-place again in the sense of just moving the elements.

Flip Flip - 40 ms

Basically the same as the first solution, but using reverse instead of [::-1] and transposing the matrix with loops instead of zip. It's 100% in-place,
just instead of only moving elements around, it also moves the rows around.
*/