class Solution {
public:
    void dfs(int start, vector<vector<int>>& graph, vector<vector<int>>& result, vector<int> temp){
        int V = graph.size();

        temp.push_back(start);

        if(start == V-1){
            result.push_back(temp);
        }

        for(auto it: graph[start]){
            dfs(it, graph, result, temp);
        }

        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int V = graph.size();

        vector<vector<int>> result;
        vector<int> temp;
        
        dfs(0, graph, result, temp);
        return result;
    }
};