class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        int n = chunks.size();
        
        string s = "";
        for(int i =0; i < n; i++){
            s+=chunks[i];
        }


        unordered_map<string, int> mp;

        string temp = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                temp+=s[i];
            } else if(s[i] == '-'){
                if(i-1 >= 0 && (s[i-1] >= 'a' && s[i-1] <= 'z') 
                && i+1 < s.size() && (s[i+1] >= 'a' && s[i+1] <= 'z')){
                    temp +=s[i];
                } else{
                    if(temp != ""){
                        mp[temp]++;
                    }
                    temp = "";
                }
            } else{
                if(temp != "") mp[temp]++;
                temp = "";
            }
        }
        if(temp != "") mp[temp]++;

        vector<int> ans;
        for(int i =0; i < queries.size(); i++){
            ans.push_back(mp[queries[i]]);
        }

        return ans;
    }
};