#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template< typename T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update>;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();

        ordered_set<pair<int,int>> st;

        vector<int> ans(n, 0);
        for(int i = n-1; i >=0; i--){
           int val= st.order_of_key({nums[i], -1});
           st.insert({nums[i], i});
           ans[i] = val;
        }
        return ans;
    }
};