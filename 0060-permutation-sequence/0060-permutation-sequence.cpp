class Solution {
public:
    // int cnt = 0;
    // void solve(string &result, int n, int k, string &temp){
    //     if(i == result.size()){
    //         if(temp.size() == n){
    //             if(cnt == k){
    //                 return 
    //             }
    //         }
    //     }
    // }
    string getPermutation(int n, int k) {
        
        string result = "";
        for(int i= 1; i <= n; i++){
            result += to_string(i);
        }

        cout << result << endl;
        // string temp = "";
        // string ans = solve(result, n, k, temp);
        k--;
        while(k--){
            next_permutation(result.begin(), result.end());
        }
        return result;
    }
};