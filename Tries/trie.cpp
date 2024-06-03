#include <string>
using namespace std;

class Trie {
public:
    Trie* child[26];
    bool isEnd;
    
    Trie() {
        for(int i = 0; i < 26; i++)
            child[i] = NULL;
        isEnd = false;
    }
    
    void insert(string word) {
        Trie* node = this;
        for(char c : word) {
            if(node->child[c - 'a'] == NULL) {
                node->child[c - 'a'] = new Trie();
            }
            node = node->child[c - 'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for(char c : word) {
            if(node->child[c - 'a'] == NULL) {
                return false;
            }
            node = node->child[c - 'a'];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for(char c : prefix) {
            if(node->child[c - 'a'] == NULL) {
                return false;
            }
            node = node->child[c - 'a'];
        }
        return true;
    }
};

/**
 * The object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
