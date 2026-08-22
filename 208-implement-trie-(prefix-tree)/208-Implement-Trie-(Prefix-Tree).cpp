class Trie {
    struct Node{
        bool flag;
        Node* arr[26];
    };
    Node* getNode(){
        Node* newNode = new Node();
        newNode->flag = false;
        for(int idx = 0; idx < 26; idx++) newNode->arr[idx] = NULL;

        return newNode;
    }
    Node* root;
public:
    Trie() {
        root = getNode();
    }
    
    void insert(string word) {
        Node* i = root;

        for(int idx = 0; idx < word.size(); idx++){
            if(i->arr[word[idx]-'a'] == NULL){
                i->arr[word[idx]-'a'] = getNode();
            }
            i = i->arr[word[idx]-'a'];
        }

        i->flag = true;
        return;
    }
    
    bool search(string word) {
        Node* i = root;

        for(int idx = 0; idx < word.size(); idx++){
            if(i->arr[word[idx]-'a'] == NULL){
                return false;
            }
            i = i->arr[word[idx]-'a'];
        }

        if(i != NULL && i->flag == true) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        Node* i = root;

        for(int idx = 0; idx < prefix.size(); idx++){
            if(i->arr[prefix[idx]-'a'] == NULL){
                return false;
            }
            i = i->arr[prefix[idx]-'a'];
        }

        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */