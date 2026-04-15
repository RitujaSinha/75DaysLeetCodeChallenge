class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;

        vector<vector<int>> adj(V);
        //adjList

        for(auto &it: prerequisites){
            int a = it[0];
            int b = it[1];

            adj[b].push_back(a);
        }

        vector<int> indegree(V);

        for(int i=0; i < V; i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }

        queue<int> q;
        for(int i=0; i < V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> res;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            res.push_back(node);

            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        if(res.size() != V) return {};
        return res;
    }
};