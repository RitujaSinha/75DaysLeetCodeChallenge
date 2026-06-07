class Solution {
public:
    int n;
    void solve(unordered_set<string> &res, string &curr, string &tiles, vector<bool> &used){
        res.insert(curr);

        for(int i = 0; i < n; i++){

            if(used[i]) continue;

            used[i] = true;
            curr.push_back(tiles[i]);

            solve(res, curr, tiles, used);

            used[i]= false;
            curr.pop_back();
        }
    }
    int numTilePossibilities(string tiles) {
        n = tiles.size();

        unordered_set<string> res;
        vector<bool> used(n, false);
        string curr = "";

        solve(res, curr, tiles, used);
        return res.size()-1;
    }
};

// n tiles 
// AAB = 3
// avoid repeated solution

// AAB

// A, AB, B, BA, AA, AAB, BBA, ABA;
