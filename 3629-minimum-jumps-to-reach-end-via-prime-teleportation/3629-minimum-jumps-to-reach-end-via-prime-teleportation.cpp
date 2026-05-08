class Solution {
public:
    vector<bool> isPrime;
    void buildSieve(int maxEl){

        isPrime.resize(maxEl+1, true);

        isPrime[0] = false;
        isPrime[1] = false;

        for(int num = 2; num*num <= maxEl; num++){
            if(isPrime[num]){

                for(int multiple = num*num; multiple <= maxEl; multiple += num){
                    isPrime[multiple] = false;
                }
            }
        }
    }


    int minJumps(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, vector<int>> mp; //element -> indices
        int maxEl = 0;
        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
            maxEl = max(maxEl, nums[i]);
        }

        buildSieve(maxEl); //Building sieve of erathosthene

        queue<int> q;
        vector<int> vis(n, 0);

        q.push(0);
        vis[0] = 1;

        unordered_set<int> seen; //already seen element

        int steps = 0;

        while(!q.empty()){
            int size = q.size();

            while(size--){//levelwise process kar rhe hai
                int i = q.front();
                q.pop();

                if(i == n-1) return steps;

                if(i-1 >= 0 && !vis[i-1]){
                    q.push(i-1);
                    vis[i-1] = 1;
                }

                if(i+1 <= n-1 && !vis[i+1]){
                    q.push(i+1);
                    vis[i+1] = 1;
                }

                if(!isPrime[nums[i]] || seen.count(nums[i])){
                    continue;
                }

                for(int multiple = nums[i]; multiple <= maxEl; multiple += nums[i]){//multiple me check kr rhe hai
                    if(!mp.contains(multiple)){
                        continue;
                    }

                    for(int &j: mp[multiple]){
                        if(!vis[j]){
                            q.push(j);
                            vis[j] = 1;
                        }
                    }
                }

                seen.insert(nums[i]);
            }

            steps++;
        }
        return steps;
    }
};