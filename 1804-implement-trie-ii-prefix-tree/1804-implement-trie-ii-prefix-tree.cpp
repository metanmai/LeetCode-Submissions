struct Node
{
    Node *links[26];
    int prefixCount = 0, wordCount = 0;
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
            
            node = node->links[c - 'a'];
            node->prefixCount++;
        }

        node->wordCount++;
    }
    
    int countWordsEqualTo(string word) {
        Node *node = root;

        for(char c : word)
        {
            if(!node->links[c - 'a'])
                return 0;
            
            node = node->links[c - 'a'];
        }

        return node->wordCount;
    }
    
    int countWordsStartingWith(string prefix) {
        Node *node = root;

        for(char c : prefix)
        {
            if(!node->links[c - 'a'])
                return 0;
            
            node = node->links[c - 'a'];
        }

        return node->prefixCount;
    }
    
    void erase(string word) {
        Node *node = root;

        for(char c : word)
        {
            node = node->links[c - 'a'];
            node->prefixCount--;
        }

        node->wordCount--;
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