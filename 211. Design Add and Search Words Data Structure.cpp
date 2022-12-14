class TrieNode
{
public:
    TrieNode *child[26];
    bool isWord;

    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            child[i] = NULL;
        }
        isWord = false;
    }
};

class WordDictionary
{
public:
    WordDictionary()
    {
        root = new TrieNode();
    }

    void addWord(string word)
    {
        TrieNode *temp = root;
        int curr;

        for (int i = 0; i < word.size(); i++)
        {
            curr = word[i] - 'a';
            if (temp->child[curr] == NULL)
            {
                temp->child[curr] = new TrieNode();
            }
            temp = temp->child[curr];
        }
        temp->isWord = true;
    }

    bool search(string word)
    {
        TrieNode *temp = root;
        return searchNodes(temp, 0, word);
    }

private:
    TrieNode *root;

    bool searchNodes(TrieNode *node, int i, string &word)
    {
        if (node == NULL)
        {
            return false;
        }
        if (i == word.size())
        {
            return node->isWord;
        }
        if (word[i] != '.')
        {
            return searchNodes(node->child[word[i] - 'a'], i + 1, word);
        }
        for (int j = 0; j < 26; j++)
        {
            if (searchNodes(node->child[j], i + 1, word))
            {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */