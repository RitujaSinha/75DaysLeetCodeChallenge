class Solution {
public: 
    void bfs(int row, int col, vector<vector<int>> &matrix, vector<vector<int>> &vis){
    int m = matrix.size();
    int n = matrix[0].size();

    queue<pair<int, int>> q;
    q.push({row, col});

    vis[row][col] = 1;

    while(!q.empty()){
    int r = q.front().first;
    int c = q.front().second;
    q.pop();

    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};

    for(int i = 0; i < 4; i++){

    int nrow = r + delrow[i];
    int ncol = c + delcol[i];


    if(nrow >= 0 && nrow < m && ncol >=0 && ncol < n && matrix[nrow][ncol] == 1 && !vis[nrow][ncol]){
        q.push({nrow, ncol});
        vis[nrow][ncol] = 1;
    }
    }
    }
    }

    int numEnclaves(vector<vector<int>>& matrix) {
    int m = matrix.size();
int n = matrix[0].size();

vector<vector<int>> vis(m, vector<int> (n, 0));

//upper 
for(int i = 0; i < n; i++){
if(matrix[0][i] == 1 && !vis[0][i]){
bfs(0, i, matrix, vis);
}
}

// right 
for(int j = 1; j < m; j++){
if(matrix[j][n-1] == 1 && !vis[j][n-1]){
bfs(j, n-1, matrix, vis);
}
}

//down
for(int i = n-2; i >=0; i--){
if(matrix[m-1][i] == 1 && !vis[m-1][i]){
bfs(m-1, i, matrix, vis);
}
}

//left
for(int i = m-2; i>= 1; i--){
if(matrix[i][0] ==1 && !vis[i][0]){
bfs(i, 0, matrix, vis);
}
}

int island = 0;
for(int i = 0; i < m; i++){
for(int j= 0; j < n; j++){
if(matrix[i][j] == 1 && vis[i][j] == 0){
island++;
}
}
}
return island;
    }
};