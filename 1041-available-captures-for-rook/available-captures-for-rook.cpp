class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int count = 0;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board.size(); j++){
                if(board[i][j] == 'R'){
                    traverse(board, i, j, count);
                    break;
                }
            }
        }

        return count;
    }

private:
    void traverse(vector<vector<char>>& board, int i, int j, int& count){
        int startI = i;

        for(startI; startI < board.size(); startI++){
            if(board[startI][j] == 'p'){
                count++;
                break;
            }
            else if(board[startI][j] == 'B'){
                break;
            }
        }

        startI = i;

        for(startI; startI >= 0; startI--){
            if(board[startI][j] == 'p'){
                count++;
                break;
            }
            else if(board[startI][j] == 'B'){
                break;
            }
        }

        int startJ = j;

        for(startJ; startJ >= 0; startJ--){
            if(board[i][startJ] == 'p'){
                count++;
                break;
            }
            else if(board[i][startJ] == 'B'){
                break;
            }
        }

        startJ = j;

        for(startJ; startJ < board.size(); startJ++){
            if(board[i][startJ] == 'p'){
                count++;
                break;
            }
            else if(board[i][startJ] == 'B'){
                break;
            }
        }

        return;
    }
};