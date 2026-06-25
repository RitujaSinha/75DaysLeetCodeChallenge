#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update>;


class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();

        ordered_set<pair<int, int>> st;

        int count  = 0;
        for(int i = n-1; i>=0; i--){
            int target = ceil(nums[i]/2.0);

            count += st.order_of_key({target, -1});
            st.insert({nums[i], i});
        }
        return count;
    }
};