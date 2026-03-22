class Solution {
public:
    void rotate(vector<vector<int>>& mat){
        vector<vector<int>> temp=mat;
        int n=mat.size();
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat.size();j++){
                temp[i][j]=mat[j][n-i-1];
            }
        }
        mat=temp;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();

        for(int i =0; i < 4; i++){
            if(mat == target) return true;
            rotate(mat);
        }
        return false;
    }
};