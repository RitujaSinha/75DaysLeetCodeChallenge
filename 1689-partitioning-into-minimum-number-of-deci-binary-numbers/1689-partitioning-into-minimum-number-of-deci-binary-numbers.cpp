class Solution {
public:
    int minPartitions(string n) {
        sort(n.rbegin(), n.rend());
        return n[0]-'0';
    }
};