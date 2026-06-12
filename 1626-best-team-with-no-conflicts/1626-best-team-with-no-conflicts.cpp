class Solution {
public:
    // int maxAns = 0;
    // void solve(int i,int &ans, vector<int> &st, vector<pair<int, int>> &vec){
    //     if(i == vec.size()){
    //         maxAns = max(maxAns, ans);
    //         return;
    //     }


    //     // int take = 0;

    //     bool small = false;
    //     for(auto &it: st){
    //         if(it < vec[i].second){
    //             small = true;
    //             break;
    //         }
    //     }

    //     // if(!small){
    //     //     take = vec[i].first + solve(i+1, st, vec);
    //     // }

    //     // int notTake = solve(i+1, st, vec);

    //     // return max(take, notTake);

    //     if(!small){
    //         ans += vec[i].first;
    //         st.push_back(vec[i].second);

    //         solve(i+1, ans, st, vec);

    //         ans -= vec[i].first;
    //         st.pop_back();
    //     }
    //     solve(i+1, ans, st, vec);
    // }
    int bestTeamScore(vector<int>& score, vector<int>& ages) {
        int n = score.size();

        vector<pair<int, int>> vec;

        for(int i = 0; i < n; i++){
            vec.push_back({score[i], ages[i]});
        }

        sort(vec.rbegin(), vec.rend());

        // // set<int> st;

        // // int ans =0;
        // // for(int i = 0; i < n; i++){
            
        // //     bool smaller = false;
        // //     for(auto &it: st){
        // //         if(vec[i].second > it){
        // //             smaller = true;
        // //             break;
        // //         }
        // //     }

        // //     if(smaller) continue;

        // //     ans += vec[i].first;
        // //     st.insert(vec[i].second); 
        // // }
        // vector<int> st;
    
        // int ans =0;
        // solve(0,ans, st, vec);
        // return maxAns;

        vector<int> result(n);
        for(int i = 0; i < vec.size(); i++){
            result[i] = vec[i].first;
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(vec[i].second <= vec[j].second){
                    result[i] = max(result[j] + vec[i].first, result[i]);
                }
            }
        }
        return *max_element(result.begin(), result.end());
    }
};