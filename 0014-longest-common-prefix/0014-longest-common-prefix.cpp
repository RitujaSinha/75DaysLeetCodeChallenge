class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();

        int maxL =INT_MAX;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                
                string s1 = strs[i];
                string s2 = strs[j];

                int a = 0, b =0;
                int len  = 0;
                while(a < s1.size() && b < s2.size()){
                    if(s1[a] == s2[b]){
                        len++;
                        a++; b++;
                    } else{
                        break;
                    }
                }

                maxL =min(maxL, len);
            }
        }
        return strs[0].substr(0, maxL);
    }
};