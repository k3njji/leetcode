class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(!checked(matrix, i+1, j+1, matrix[i][j])){
                    return false;
                }
            }
        }

        return true;
    }

private:
    bool checked(vector<vector<int>>& matrix, int i, int j, int ref){
        
        int boundVert = matrix.size();
        int boundHors = matrix[0].size();

        while(i < boundVert && j < boundHors){
            if(matrix[i][j] != ref){
                return false;
            }

            i++;
            j++;
        }


        return true;
    }
};