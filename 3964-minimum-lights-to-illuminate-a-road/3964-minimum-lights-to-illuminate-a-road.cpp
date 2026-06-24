class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();

        int i =0;
        vector<int> vec(n, 0);

        while(i < n){
            if(lights[i] != 0){
                int v = lights[i];
                int next = v+1;
                while(i < n && next > 0 && next > lights[i]){
                    vec[i] = -1;
                    next--;
                    i++;
                }
            }
            else i++;
        }

        i = n-1;
        while(i >=0){
            if(lights[i] != 0){
                int v = lights[i];
                int prev = v+1;
                while(i >= 0 && prev > 0 && prev > lights[i]){
                    vec[i] = -1;
                    prev--;
                    i--;
                }
            }
            else i--;
        }

        int ans = 0, maxTrue = 0;
        for(int j = 0; j < n; j++){
            if(vec[j]==0){
                ans++;
            } else{
                maxTrue += ceil(ans/3.0);
                ans=0;
            }
        }

        maxTrue += ceil(ans/3.0);
        return maxTrue;
    }
};