class Solution {
public:
    int maxNumberOfBalloons(string text) {
        

        string s = "balloon";

        unordered_map<char, int> mpp;
        for(char &c : text){
            mpp[c]++;
        }

        int count = 0;
        while(1){
            
            bool found = true;
            for(int i = 0; i < 7; i++){
                if(mpp.find(s[i]) == mpp.end()){
                    found = false;
                    break;
                }
                mpp[s[i]]--;
                if(mpp[s[i]] == 0) mpp.erase(s[i]);
            }

            if(found) count++;
            else break;
        }
        return count;
    }
};