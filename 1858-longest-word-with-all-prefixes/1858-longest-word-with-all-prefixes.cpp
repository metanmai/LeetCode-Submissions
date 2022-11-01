struct Node
{
    Node *links[26];
    bool flag = false;
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
        }
        
        node->flag = true;
    }
    
    bool hasAllPrefixes(string prefix) {
        Node *node = root;
        
        for(char c : prefix)
        {
            if(!node->links[c - 'a'] or !node->links[c - 'a']->flag)
                return false;
            
            node = node->links[c - 'a'];
        }
        
        return true;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie tr;
        string longest = "";
        
        for(string word : words)
            tr.insert(word);
        
        for(string word : words)
            if(tr.hasAllPrefixes(word) and 
               (word.length() > longest.length() or
                word.length() == longest.length() and word < longest))
                longest = word;
            
        return longest;
    }
};