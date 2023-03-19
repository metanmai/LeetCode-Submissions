struct TrieNode
{
    TrieNode *links[26];
    bool flag = false;
};

class WordDictionary {
public:
    TrieNode *root;

    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *itr = root;

        for(char ch : word)
        {
            if(!itr->links[ch - 'a'])
                itr->links[ch - 'a'] = new TrieNode();
            
            itr = itr->links[ch - 'a'];
        }

        itr->flag = true;
    }
    
    bool search(string word) {
        return findWord(word, 0, root);
    }

    bool findWord(string word, int start, TrieNode *root)
    {
        TrieNode *itr = root;

        for(int i = start; i < word.length(); i++)
            if(word[i] == '.')
            {
                bool found = false;
                for(char ch = 'a'; ch <= 'z'; ch++)
                    if(itr->links[ch - 'a'])
                        found |= findWord(word, i + 1, itr->links[ch - 'a']);
                
                return found;
            }

            else
            {
                if(!itr->links[word[i] - 'a'])
                    return false;
                
                itr = itr->links[word[i] - 'a'];
            }

        return itr->flag;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */