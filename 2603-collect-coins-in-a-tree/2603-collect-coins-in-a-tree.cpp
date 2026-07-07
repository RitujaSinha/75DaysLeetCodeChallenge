class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();

        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);

            degree[it[0]]++;
            degree[it[1]]++;
        }

        int remainingEdges = edges.size();

        queue<int> q;
        for(int i =0; i < n; i++){
            if(degree[i] == 1 && coins[i]==0){
                q.push(i);
            }
        }

        //Round-1
        while(!q.empty()){
            int node = q.front();
            q.pop();

            degree[node] = 0;

            for(auto it: adj[node]){
                if(degree[it] > 0){
                degree[it]--;
                remainingEdges--;

                if(degree[it] == 1 && coins[it] == 0){
                    q.push(it);
                }
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(degree[i] == 1){
                q.push(i);
            }
        }

        for(int round = 0; round < 2; round++){
            int size = q.size();

            while(size--){
                int node = q.front();
                q.pop();

                degree[node] = 0;

                for(auto it: adj[node]){
                    if(degree[it] > 0){
                        degree[it]--;
                        remainingEdges--;

                        if(degree[it] == 1){
                            q.push(it);
                        }
                    }
                }
            }
        }

         return remainingEdges * 2;
    }
};