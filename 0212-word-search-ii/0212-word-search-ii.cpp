class Solution {
public:
    vector<string> result;
    int m, n;

    struct trieNode{
        bool endOfWord;
        string word;
        trieNode* children[26];
    };

    trieNode* getNode(){
        trieNode* newNode = new trieNode();

        newNode->endOfWord = false;
        newNode->word = "";

        for(int i  =0; i < 26; i++){
            newNode->children[i] = NULL;
        }
        return newNode;
    }

    void insert(trieNode* root, string word){
        trieNode* node = root;

        for(int i = 0; i < word.size(); i++){
            char ch  =word[i];
            if(node->children[ch-'a'] == NULL){
                node->children[ch-'a'] = getNode();
            }

            node = node->children[ch-'a'];
        } 
        node->endOfWord = true;
        node->word = word;
    }

    void dfs(vector<vector<char>>& board, int i, int j, trieNode* root){

         int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};


        if(i < 0 || j < 0 || i>= m || j >= n) return;

        if(board[i][j] == '$' || root->children[board[i][j]-'a'] == NULL) return;

        root = root->children[board[i][j]-'a'];

        if(root->endOfWord == true){
            result.push_back(root->word);
            root->endOfWord = false;
        }

        char temp = board[i][j];
        board[i][j] = '$';


        for(int  dir =0; dir < 4; dir++){
            int nrow = i + delrow[dir];
            int ncol = j + delcol[dir];

                
                dfs(board, nrow, ncol, root);
        }

        board[i][j] = temp;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();

        trieNode* root = getNode();

        for(string &word: words){
            insert(root, word);
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                char ch = board[i][j];

                if(root->children[ch-'a'] != NULL){
                    dfs(board, i, j, root);
                }
            }
        }
        return result;
    }
};