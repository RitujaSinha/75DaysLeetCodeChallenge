class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        
        unordered_set<string> st;

        for(int x: arr1){
            string s = to_string(x);
            string temp ="";
            for(char c: s){
                temp += c;
                st.insert(temp);
            }
        }

        int maxL = 0;

        for(int x: arr2){
            string s = to_string(x);
            string temp ="";
            for(char c: s){
                temp +=c;

                if(st.count(temp)){
                    maxL = max((int)temp.size(), maxL);
                } else{
                    break;
                }
            }
        }
        return maxL;
    }
};