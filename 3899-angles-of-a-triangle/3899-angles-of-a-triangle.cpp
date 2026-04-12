class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        
        double a = sides[0];
        double b = sides[1];
        double c = sides[2];

        if(a+b <= c || b+c <= a || c+a <= b) return {};

        double A = acos((b*b+c*c-a*a) / (2*b*c)) * (180 / M_PI);
        double B = acos((a*a+c*c-b*b) / (2*a*c)) * (180 / M_PI);
        double C = acos((b*b+a*a-c*c) / (2*b*a)) * (180 / M_PI);

        vector<double> ans;
        ans.push_back(A);
        ans.push_back(B);
        ans.push_back(C);

        sort(ans.begin(), ans.end());

        return ans;
    }
};