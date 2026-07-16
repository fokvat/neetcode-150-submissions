class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int nRow = matrix.size() - 1; //number of Rows || end of Row
        int nCol = matrix[0].size() - 1; // Number of Columns || end of Col

        
        int i=0; //start of Rows
        int j=0; //Start of Col

        while(i<=nRow && j<=nCol){
            int midCol = (j+nCol)/2;
            int midRow = (i+nRow)/2;

            if(target == matrix[midRow][midCol]){
                return true;
            }

            if(target < matrix[midRow][midCol]){ //Reduce Column size if nCol < 0 then Reduce nRow and Cover Complete Column
                nCol = midCol - 1;
                if(nCol < 0 && midRow != 0){
                    nCol = matrix[0].size() - 1;;
                    nRow = midRow - 1;
                    j = 0;
                }
            }else{ //Increase Column size if j > matrix[0].size() - 1 then increase nRow and Cover Complete Column
                j = midCol + 1;
                if(j > matrix[0].size() - 1 && midRow != matrix.size() - 1){
                    nCol = matrix[0].size() - 1;;
                    i = midRow + 1;
                    j = 0;
                }
            }
        }

        return false;
        
    }
};
