class Solution {
public:
    vector<int> generateRows(int row){
        vector<int> temp;

        long long ans = 1;
        temp.push_back(1);

        for(int col =1; col < row; col++){
            ans = ans * (row-col);
            ans = ans / col;

            temp.push_back(ans);
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