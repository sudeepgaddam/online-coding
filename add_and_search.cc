class TrieNode
{
public:
    TrieNode *next[26];
    bool is_word;

    // Initialize your data structure here.
    TrieNode(bool b = false)
    {
        memset(next, 0, sizeof(next));
        is_word = b;
    }
};

class Trie
{
    TrieNode *root;
public:
    Trie()
    {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s)
    {
        TrieNode *p = root;
        for(int i = 0; i < s.size(); ++ i)
        {
            if(p -> next[s[i] - 'a'] == NULL)
                p -> next[s[i] - 'a'] = new TrieNode();
            p = p -> next[s[i] - 'a'];
        }
        p -> is_word = true;
    }

    bool search_with_dot(string key)
    {
        return find_with_dot(key,root);
    }

private:
    
     bool find_with_dot(string key,TrieNode *p)
    {
        //If there is a dot, call recursively with string succeding . 
        //in a for loop, for all the children nodes of the current node 
        
        for(int i = 0; key[i]; i++) {
            
            if (p && key[i] == '.') {
				TrieNode* tmp = p;
                for(int j=0;j<26;j++) {
					p = tmp->next[j];

                    if(tmp->next[j]) {
						//Try all child nodes
						//If anyone returns true, return true;
                       if(find_with_dot(key.substr(i+1),p)) {return true;}
                    }
				}
            } else if(p && key[i] != '.') {
                p = p -> next[key[i] - 'a'];
            } else {
				break;
			}
        }
            
        return p && p->is_word;
    }
};


class WordDictionary {
    
    private:
        Trie *a;
public:
    WordDictionary()
    {
        a = new Trie();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        a->insert(word);
        
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return a->search_with_dot(word);
    }
};
