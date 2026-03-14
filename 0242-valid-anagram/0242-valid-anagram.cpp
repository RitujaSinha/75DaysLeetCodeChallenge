class Solution {
public:
    bool isAnagram(string s, string t) {
        int n1= s.size();
        int n2= t.size();

        if(n1 < n2) return false;
        if(n1 > n2) return false;

        unordered_map<char, int> mpp;
        for(int i =0; i < n1; i++){
            mpp[s[i]]++;
        }

        for(int i =0; i < n1; i++){
            if(mpp.find(t[i]) != mpp.end()){
                mpp[t[i]]--;
                if(mpp[t[i]] <= 0) mpp.erase(t[i]);
            } else{
                return false;
            }
        }
        return true;
    }
};