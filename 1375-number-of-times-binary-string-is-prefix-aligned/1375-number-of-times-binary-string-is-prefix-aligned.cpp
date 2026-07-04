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
    int numTimesAllBlue(vector<int>& flips) {
        int n = flips.size();

        ordered_set<int> st;
        for(int x: flips){
            st.insert(x-1);
        }

        int cnt = 0;
        for(int i = 0; i < n; i++){
            int num = flips[i]-1;

            int check = st.order_of_key(i+1);
            st.erase(num);
            if(check==1 && num<=i) cnt++;
            
        }
        return cnt;
    }
};