class Solution {
public:
    vector<int> generateRows(int n){
        vector<int> temp(n, 1);

        int ans =1;
        for(int col = 1; col < n; col++){
            ans = ans * (n-col);
            ans = ans/ col;

            temp[col] = ans;
        }

        return temp;
    }

    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> result;

        for(int i =1; i <= numRows; i++){
            result.push_back(generateRows(i));
        }
        return result;
    }
};