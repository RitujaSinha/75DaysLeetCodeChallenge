class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();

        string s1= s;

        while(n--){
            char ch = s1[0];

            s1.erase(s1.begin()+0);

            s1.push_back(ch);

            if(s1 == goal) return true;
        }
        return false;
    }
};