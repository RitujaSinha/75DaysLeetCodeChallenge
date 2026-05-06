class Solution {
public:
    vector<char> slide(vector<char> &a){
        int n = a.size();

        int  i = 0, j = i+1;
        
        while(j < n){

            while(j < n){
                if(a[j] == '.' && a[i] == '#'){
                    swap(a[i], a[j]);
                    i++;
                } else if(a[i] == '*'){
                    i = j;//why?
                } else if(a[i] == '.' && a[j] == '.'){
                    i++;
                } else if(a[i] == '.' && a[j] == '#'){
                    i++;
                }

                if(j < n && a[j] == '*') break;
                j++;
            }

            while(j < n && a[j] == '*') j++;

            i = j;
            j = j+1;

        }
        return a;
    }

    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();

        for(int i = 0; i < m; i++){
            boxGrid[i] = slide(boxGrid[i]);
        }

        vector<vector<char>> result(n, vector<char> (m));

        int num = m-1;
        for(int i = 0; i < m; i++){
            for(int j =0; j < n; j++){
                result[j][num] = boxGrid[i][j];  
            }
            num--;
        }
        return result;
    }
};