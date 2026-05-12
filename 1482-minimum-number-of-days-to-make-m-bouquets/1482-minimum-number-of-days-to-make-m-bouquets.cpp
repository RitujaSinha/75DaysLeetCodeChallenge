class Solution {
public:
    bool isValid(vector<int>& bloomDay, int m, int k, int days){
        int n = bloomDay.size();

        int flowers = 0;
        int bouquet = 0;

        for(int i = 0; i < n; i++){
            if(bloomDay[i] <= days){
                flowers++;

                if(flowers==k){
                    bouquet++;
                    flowers = 0;
                }
            } else{
                flowers = 0;
            }
        }
        return bouquet >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        if(n < (long long)m*k) return -1;

        int st = *min_element(bloomDay.begin(), bloomDay.end());
        int end = *max_element(bloomDay.begin(), bloomDay.end());

        int ans  = 0;
        while(st <= end){
            int mid = st + (end-st)/2;

            if(isValid(bloomDay, m, k, mid)){
                ans = mid;
                end=mid-1;
            } else{
                st =mid+1;
            }
        }
        return ans;
    }
};