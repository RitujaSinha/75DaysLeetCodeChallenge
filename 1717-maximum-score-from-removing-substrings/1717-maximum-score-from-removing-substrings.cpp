class Solution {
public:
    int maxPointThroughX(string &s, int x, int y){
        int n = s.size();
        int points = 0;

        stack<char> st;
        for(int i =0; i < n; i++){

            if(!st.empty() && (st.top() == 'a' && s[i] == 'b')){
                points += x;
                st.pop();
                continue;
            }

            st.push(s[i]);
        }


        string left= "";

        while(!st.empty()){
            left += st.top();
            st.pop();
        }

        reverse(left.begin(), left.end());

       while (!st.empty()) {
            st.pop();
        }

        for(int i = 0; i < left.size(); i++){

            if(!st.empty() && (st.top() == 'b' && left[i] == 'a')){
                points += y;
                st.pop();
                continue;
            }
            st.push(left[i]);
        }

        return points;
    }

     int maxPointThroughY(string &s, int x, int y){
        int n = s.size();
        int points = 0;

        stack<char> st;
        for(int i =0; i < n; i++){

            if(!st.empty() && (st.top() == 'b' && s[i] == 'a')){
                points += y;
                st.pop();
                continue;
            }

            st.push(s[i]);
        }


        string left= "";

        while(!st.empty()){
            left += st.top();
            st.pop();
        }

        reverse(left.begin(), left.end());

        while (!st.empty()) {
            st.pop();
        }

        for(int i = 0; i < left.size(); i++){

            if(!st.empty() && (st.top() == 'a' && left[i] == 'b')){
                points += x;
                st.pop();
                continue;
            }
            st.push(left[i]);
        }

        return points;
    }
    int maximumGain(string s, int x, int y) {
        int n = s.size();

        int score  = 0;
        if(x >= y){
            score += maxPointThroughX(s, x, y);
        } else{
            score += maxPointThroughY(s, x, y);
        }
        return score;
    }
};