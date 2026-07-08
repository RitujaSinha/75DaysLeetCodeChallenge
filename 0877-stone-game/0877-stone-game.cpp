class Solution {
public:
    int solve(int i, int j, vector<int>& piles, vector<vector<int>> &t){
        if(i > j){
            return 0;
        }

        if(i == j) return piles[i];

        if(t[i][j] !=-1) return t[i][j];

        int take_i = piles[i] + min(solve(i+2, j, piles, t), solve(i+1, j-1, piles, t));
        int take_j = piles[j] + min(solve(i+1, j-1, piles, t), solve(i, j-2, piles, t));

        return t[i][j] =  max(take_i, take_j);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        vector<vector<int>> t(n, vector<int> (n, -1));

        int totalStone = accumulate(piles.begin(), piles.end(), 0);

        int alice = solve(0, n-1, piles, t);
        int bob = totalStone - alice;

        return alice > bob;
    }
};