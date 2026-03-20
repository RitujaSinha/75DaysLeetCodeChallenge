class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int n1 = target.size();

        vector<string> result;

        int j=0;
        for(int i =1; i <=n && j < n1; i++){
            result.push_back("Push");
            
            if(i != target[j]){
                result.push_back("Pop");
            } else{
                j++;
            }
        }
        return result;
    }
};