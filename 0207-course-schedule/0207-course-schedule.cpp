class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;

        vector<vector<int>> adj(V);
        //adj list
        for(auto &p : prerequisites){
            int a = p[0];
            int b = p[1];
            adj[b].push_back(a); //b->a
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

        int count =0;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;

            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        return V==count;
    }
};