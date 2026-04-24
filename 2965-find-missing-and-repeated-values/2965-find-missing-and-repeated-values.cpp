class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();

        unordered_set<int> s;
        vector<int> ans;

        int actualSum = 0;
        int a = 0;
        for(int i =0; i < n; i++){
            for(int j =0; j < n; j++){
                actualSum += grid[i][j];

                if(s.find(grid[i][j]) != s.end()){
                    a = grid[i][j];
                    ans.push_back(grid[i][j]);
                }
                s.insert(grid[i][j]);//a value
            }
        }
        int expSum = (n*n) * (n*n+1)/2;
        int b = expSum + a - actualSum;

        ans.push_back(b);

        return ans;
    }
};