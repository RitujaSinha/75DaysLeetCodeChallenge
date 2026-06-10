class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int n= position.size();

        int odd = 0, even =0;
        for(int &n: position){
            if(n % 2 ==0) even++;
            else odd++;
        }

        if(even > odd) return odd;
        return even;
    }
};