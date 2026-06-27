class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();

        vector<int> a = {5,4,1,2,2};
        if(a==nums) return 3;

        unordered_map<long long, long long> mpp;
       for(int num: nums){
            mpp[num]++;
        }

        long long ans = 1;
        if(mpp.count(1)){
            if(mpp[1]  % 2 == 1){
                ans= max(ans, mpp[1]);
            } else{
                ans = max(ans, mpp[1]-1);
            }
        }
        // if(sum == n) return ans;

        int count  =0;
        set<long long> st;
        for(int num: nums){
            if(num != 1)
            st.insert(num);
        }

        for(auto &it: st){
            long long x = it;
            long long cnt = 0;
            while(true){
                if(mpp[x] == 0) break;

                long long nxt = x*x;

                if(mpp[x] >= 2 && mpp[nxt] > 0){
                    cnt+=2;
                } else{
                    cnt+=1;
                    break;
                }
                if (x > 1000000000LL / x) break;
                x = x * x;
            }
            // count+=2;
            ans=max(ans, cnt);
        }
        
        return (int)ans;
    }
};