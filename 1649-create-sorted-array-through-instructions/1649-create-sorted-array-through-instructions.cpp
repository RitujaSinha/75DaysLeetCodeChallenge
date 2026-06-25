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


int mod = 1e9+7;

class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        int n = instructions.size();

        vector<int> nums;
        ordered_set<pair<int, int>> st;

        unordered_map<int, int> mp;

        int totalCost = 0;
        for(int i = 0; i < n; i++){

            int lesser = st.order_of_key({instructions[i], -1});

            int equal = mp[instructions[i]];
            int greater = max(0, (int)nums.size()-lesser-equal);//handle equal elements beacuse we want only greater
            int cost =  min(lesser, greater);

            totalCost = (totalCost + cost) % mod;
            nums.push_back(instructions[i]);
            mp[instructions[i]]++;

            st.insert({instructions[i], i});
        }
        return totalCost;
    }
};