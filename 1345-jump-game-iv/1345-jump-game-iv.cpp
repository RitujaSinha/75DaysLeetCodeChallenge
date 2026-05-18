class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        queue<pair<int, int>> q;
        q.push({0, 0}); //{idx, steps}

        vector<int> vis(n, 0);
        vis[0] = 1;

        unordered_multimap<int, int> mpp;
        for(int i = 0; i < n; i++){
            if(!vis[i]) mpp.insert({arr[i], i});
        }

        while(!q.empty()){
            int index = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(index== n-1) return steps;

            if(index+1 < n && !vis[index+1]){
                q.push({index+1, steps+1});
                vis[index+1] = 1;
            }

            if(index-1 >= 0 && !vis[index-1]){
                q.push({index-1, steps+1});
                vis[index+1] = 1;
            }

            // for(int j = 0; j < n; j++){
            //     if(index != j && arr[index] == arr[j] && !vis[j]){
            //         q.push({j, steps+1});
            //         vis[j] = 1;
            //     }
            // }

            auto range = mpp.equal_range(arr[index]);

            for(auto it = range.first; it!= range.second; it++){
                int j = it->second;
                if(index != j && !vis[j]){
                    q.push({j, steps+1});
                    vis[j] = 1;
                }
            }

            mpp.erase(arr[index]);
            
        }
        return -1;
    }
};