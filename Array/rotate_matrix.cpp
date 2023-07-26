class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //first find the transpose of the matrix
        for(int i=0; i<matrix.size(); i++){
            for(int j=i; j<matrix.size(); j++){
                if(i != j){
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }
        //reverse each row
        for(int i=0; i<matrix.size(); i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }

        return;
    }
};