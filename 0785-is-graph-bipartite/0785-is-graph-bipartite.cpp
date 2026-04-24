class Solution {
public:
    bool bfs(int start, vector<int> &color, vector<vector<int>>& graph){
        queue<pair<int, int>> q;
        q.push({start, 0});
        color[start] = 0;

         while(!q.empty()){
            int node = q.front().first;
            int col = q.front().second;
            q.pop();

            for(auto &it: graph[node]){
                if(color[it] == -1){
                    color[it] = !col;
                    q.push({it, !col});
                } else if(color[it] == color[node]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> color(n, -1);

        for(int i =0; i < n; i++){
            if(color[i] == -1){
                if(bfs(i, color, graph) == false) return false;
            }
        }
        return true;
    }
};