class Solution {
public:
    int result = INT_MAX;
    int n;
    
    void solve(int idx, vector<int> &children, vector<int>& cookies, int k){
        if(idx == cookies.size()){ //all cookies are finished
            int unfairness = *max_element(children.begin(), children.end());
            result = min(result, unfairness);

            return;
        }

        int cookie = cookies[idx];

        for(int i = 0; i < k; i++){ // kis children ko dena hai
            children[i] += cookie;
            solve(idx+1, children, cookies, k);
             children[i] -= cookie;
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        n = cookies.size();

        vector<int> children(k);

        solve(0, children, cookies, k);
        return result;
    }
};