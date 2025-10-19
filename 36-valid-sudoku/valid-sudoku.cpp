class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9;i++){
            vector<bool>st(9, false);
            for(int j=0; j<9;j++){
                if(board[i][j]!='.'){
                    int t=board[i][j]-'1';
                    if(st[t])return false;
                    st[t]=true;
                }
            }
        }
        for(int i=0; i<9;i++){
            vector<bool>st(9, false);
            for(int j=0; j<9;j++){
                if(board[j][i]!='.'){
                    int t=board[j][i]-'1';
                    if(st[t])return false;
                    st[t]=true;
                }
            }
        }
        for(int i=0;i<9;i+=3){
            for(int j=0; j<9;j+=3){
                vector<bool>st(9, false);
                for(int x=0; x<3;x++){
                    for(int y=0; y<3;y++){
                        char c=board[i+x][j+y];
                        if(c!='.'){
                            int t=c-'1';
                            if(st[t])return false;
                            st[t]=true;
                        }
                    }
                }
            }
        }
        return true;
    }
};