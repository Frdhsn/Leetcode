class Solution {
public:
    bool isRowWiseValid(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            map<char,int>cnt;
            for(int j=0;j<9;j++){
                cnt[board[i][j]]++;
                if(cnt[board[i][j]]>1 && board[i][j]!='.')return 0;
            }
        }
        return 1;
    }
    bool isColWiseValid(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            map<char,int>cnt;
            for(int j=0;j<9;j++){
                cnt[board[j][i]]++;
                if(cnt[board[j][i]]>1 && board[j][i]!='.')return 0;
            }
        }
        return 1;
    }
    bool is3x3Valid(vector<vector<char>>& board){
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                map<char,int>cnt;
                for(int k=i;k<i+3;k++){
                    for(int l=j;l<j+3;l++){
                        cnt[board[k][l]]++;
                        //cout<<board[k][l];
                        if(cnt[board[k][l]]>1 && board[k][l]!='.')return 0;
                        //if(cnt[board[i][j]]==9 && board[i][j]=='.')return 0;
                        
                    }
                }
                //cout<<endl;
            }
        }
        return 1;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        return isColWiseValid(board) && isRowWiseValid(board) && is3x3Valid(board);
    }
};