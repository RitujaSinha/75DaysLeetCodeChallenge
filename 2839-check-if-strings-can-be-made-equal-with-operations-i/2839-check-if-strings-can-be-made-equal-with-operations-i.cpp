class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int n1 = s1.size();
        int n2= s2.size();

        for(int i =0; i < n1; i++){
            for(int j =0; j < n1; j++){
                if(j-i == 2 && s1[i] != s2[i]){
                    swap(s1[i], s1[j]);
                }
            }
        }
        return s1==s2;
    }
};