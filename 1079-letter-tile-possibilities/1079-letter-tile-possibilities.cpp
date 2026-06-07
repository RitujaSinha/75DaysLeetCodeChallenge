class Solution {
public:
    int count;
    void solve(vector<int> &vec){
        count++;

        for(int i = 0; i < 26; i++){

            if(vec[i]==0) continue;

            vec[i]--;
            solve(vec);
            vec[i]++;
        }
    }
    int numTilePossibilities(string tiles) {
        
        vector<int> vec(26, 0);

        for(char &c: tiles){
            vec[c-'A']++;
        }

        solve(vec);
        return count-1;
    }
};

// n tiles 
// AAB = 3
// avoid repeated solution

// AAB

// A, AB, B, BA, AA, AAB, BBA, ABA;
