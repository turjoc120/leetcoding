class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size(), col= matrix[0].size(), col0=1;

        //skip the first col coz we have seprate conditon for it, otherwise it will colide check bellow in 3rd row first item is 0 it will mark m[0][0]'th item which means we are marking the row thats wrong 
        /*
        [1,2,3,4],
        [5,0,7,8],
        [0,1,1,1],
        [1,1,1,0]*/
        for(int i=0; i<row; i++){
            if(matrix[i][0] == 0) col0=0;
            for(int j=1; j < col; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }


//doing it backward so it wont affect the down items, skip the first col coz we are using it as a flag for marking rows and have a seprate variable for first col
/*
[x,-1,6,-7,0],
[x,6,-8,-6,0],
[1,2,-9,-6,-10]

two 0's marks the rows and cols but when coming backward if we dont skip the first col at [2][0]'th item it will see the [i][0]'th flag is marked but meanwhile its acutally marked for rows col0 is handling the first col seprately so skip the first col j>0 ! j>=0
*/
        for(int i=row-1; i>=0; i--){
            for(int j=col-1; j>0; j--){
                if(matrix[0][j] ==0|| matrix[i][0]==0) matrix[i][j]=0;
            }
            if(col0 == 0) matrix[i][0]=0;
        }
    }
};