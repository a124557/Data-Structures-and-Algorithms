class TrieNode
{
public:
    TrieNode *children[26];
    bool isWord;

    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isWord = false;
    }
};

class Trie
{
public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *temp = root;
        int curr;

        for (int i = 0; i < word.size(); i++)
        {
            curr = word[i] - 'a';
            if (temp->children[curr] == NULL)
            {
                temp->children[curr] = new TrieNode();
            }
            temp = temp->children[curr];
        }

        temp->isWord = true;
    }

    bool search(string word)
    {
        TrieNode *temp = root;
        int curr;

        for (int i = 0; i < word.size(); i++)
        {
            curr = word[i] - 'a';
            if (temp->children[curr] == NULL)
            {
                return false;
            }
            temp = temp->children[curr];
        }
        return temp->isWord;
    }

    bool startsWith(string prefix)
    {
        TrieNode *temp = root;
        int curr;

        for (int i = 0; i < prefix.size(); i++)
        {
            curr = prefix[i] - 'a';
            if (temp->children[curr] == NULL)
            {
                return false;
            }
            temp = temp->children[curr];
        }

        return true;
    }

private:
    TrieNode *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */