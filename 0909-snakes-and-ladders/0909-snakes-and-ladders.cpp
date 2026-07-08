class Solution {
public:
    int n;
    pair<int, int> getOrd(int num){
        int RT = (num-1)/n;

        int RB= (n-1)-RT;

        int col = (num-1) % n;

        if((n % 2 ==0 && RB % 2==0) || (n%2 == 1 && RB %2==1)){
            col =  (n-1)-col;
        }
        return make_pair(RB, col);
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();

        queue<int> q;
        vector<vector<int>> vis(n, vector<int> (n, 0));

        q.push(1);
        vis[n-1][0] = 1;

        int steps =0;
        while(!q.empty()){

            int size = q.size();

            while(size--){
                int x = q.front();
                q.pop();

                if(x == n*n){
                    return steps;
                }

                for(int k =1; k<=6; k++){
                    
                    if(x+k > n*n) break;

                    int value = x+k;

                    pair<int, int> coard = getOrd(x+k);

                    int r = coard.first;
                    int c = coard.second;

                    if(vis[r][c] == true) continue;

                    vis[r][c] = 1;

                    if(board[r][c] == -1){
                        q.push(x+k);
                    } else{
                        q.push(board[r][c]);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};