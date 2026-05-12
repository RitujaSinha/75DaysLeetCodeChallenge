class Solution {
public:
    bool bfs(int start, vector<vector<int>>& graph, vector<int>& color){

        queue<pair<int, int>> q;
        q.push({start, 0});
        color[start] = 0;

        while(!q.empty()){
            int node = q.front().first;
            int c = q.front().second;

            q.pop();

            for(auto it: graph[node]){
                if(color[it] == -1){
                    q.push({it, !c});
                    color[it]  = !c;
                } else if(color[it] == c){
                    return false;
                }
            } 
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> color(n, -1);

        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                if(bfs(i, graph, color) == false) return false;
            }
        }
        return true;
    }
};