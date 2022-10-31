struct Node
{
    Node *links[26];
    int count1 = 0, count2 = 0;
};

class Trie {
public:
    Node *root;
    
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *node = root;
        
        for(char c : word)
        {
            if(!node->links[c - 'a'])
                node->links[c - 'a'] = new Node();
            
            node->links[c - 'a']->count2++;
            node = node->links[c - 'a'];
        }
        
        node->count1++;
    }
    
    int countWordsEqualTo(string word) {
        Node *node = root;
        
        for(char c : word)
        {
            if(!node->links[c - 'a'])
                return 0;
            
            node = node->links[c - 'a'];
        }
        
        return node->count1;
    }
    
    int countWordsStartingWith(string prefix) {
        Node *node = root;
        
        for(char c : prefix)
        {
            if(!node->links[c - 'a'] or !node->links[c - 'a'])
                return 0;
            
            node = node->links[c - 'a'];
        }
        
        return node->count2;
    }
    
    void erase(string word) {
        Node *node = root;
        
        for(char c : word)
        {
            node->links[c - 'a']->count2--;
            node = node->links[c - 'a'];
        }
        
        node->count1--;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */