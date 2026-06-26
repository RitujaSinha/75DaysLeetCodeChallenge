#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef long long ll;

typedef tree<
    pair<int, int>,
    null_type,
    less<pair<int, int>>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_set;

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> pref(n+1, 0);
        for(int i = 0; i < n; i++){
            if(nums[i] == target){
                pref[i+1] = pref[i] + 1;
            } else{
                pref[i+1] = pref[i] -1; 
            }
        }

        ll ans = 0;
        ordered_set st;
        st.insert({pref[0], 0});

        for(int i = 1; i <= n; i++){

            ans += st.order_of_key({pref[i], -1});

            st.insert({pref[i], i});
        }
        return ans;
    }
};