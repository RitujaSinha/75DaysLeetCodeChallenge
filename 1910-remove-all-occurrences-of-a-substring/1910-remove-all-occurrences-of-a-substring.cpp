class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = s.size();

        while(s.find(part) != -1){
            int idx = s.find(part);
            s.erase(idx, part.length());
        }
        return s;
    }
};