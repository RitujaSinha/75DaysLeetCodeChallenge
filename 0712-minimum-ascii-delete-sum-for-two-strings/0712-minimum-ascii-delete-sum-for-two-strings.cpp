class Solution {
public:
    // int solve(string &s1, string &s2, int m, int n){
    //     if(m==0 || n==0) return 0;

    //     if(s1[m-1] == s2[n-1]){
    //         return 1 + solve(s1, s2, m-1, n-1);
    //     }

    //     return max(solve(s1, s2, m-1, n), solve(s1, s2, m, n-1));
    // }
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        
        // return solve(s1, s2, m, n);
        vector<vector<int>> t(m+1, vector<int> (n+1));

        for(int i =0; i < m+1; i++){
            for(int j =0; j < n+1; j++){
                if(i == 0 || j==0){
                    t[i][j] = 0;
                } else if(s1[i-1]==s2[j-1]){
                    t[i][j] = s1[i-1]+ t[i-1][j-1];//WHy not 1 (s1[i-1] why???)
                } else{
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }

        int i = m, j =n;
        string LCS ="";

        while(i > 0 && j > 0){
            if(s1[i-1] == s2[j-1]){
                LCS.push_back(s1[i-1]);
                i--; j--;
            } else{
                if(t[i-1][j] > t[i][j-1]){
                    i--;
                } else{
                    j--;
                }
            } 
        }
        reverse(LCS.begin(), LCS.end());
        
        unordered_map<char, int> mp;

        for(int x: LCS){
            mp[x]++;
        }

        int sum =0;
        for(int k =0; k < m; k++){
            if(mp.find(s1[k]) != mp.end()){
                mp[s1[k]]--;

                if(mp[s1[k]] == 0) mp.erase(s1[k]);
            } else{
                sum += (int)s1[k];
            }
        }

        mp.clear();
        for(int x: LCS){
        mp[x]++;
        }


        for(int k =0; k < n; k++){
            if(mp.find(s2[k]) != mp.end()){
                mp[s2[k]]--;

                if(mp[s2[k]] == 0) mp.erase(s2[k]);
            } else{
                sum += (int)s2[k];
            }
        }

        return sum;
    }
};