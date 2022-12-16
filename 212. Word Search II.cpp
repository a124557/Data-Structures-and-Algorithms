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

class Solution
{
public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        // Add the words to our Trie
        for (auto i : words)
        {
            addWord(i);
        }
        TrieNode *node = root;
        vector<string> result;
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                search(board, i, j, m, n, node, "", result);
            }
        }

        return result;
    }

private:
    TrieNode *root = new TrieNode();

    void addWord(string word)
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

    void search(vector<vector<char>> &board, int i, int j, int m, int n, TrieNode *node, string word, vector<string> &result)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '-')
        {
            return;
        }

        char c = board[i][j];

        node = node->children[c - 'a'];
        // If the char is not present in our Trie return
        if (node == NULL)
        {
            return;
        }

        // Word is present so we add to our word
        word += board[i][j];

        // Check if the current node in our Trie is a word. If so, add to our result
        if (node->isWord == true)
        {
            result.push_back(word);
            node->isWord = false;
        }

        // Setting visited letter in list equal to '-' indicating it has been visited
        board[i][j] = '-';

        // Recursive call in every direction

        // Check upper row
        search(board, i - 1, j, m, n, node, word, result);
        // Check lower row
        search(board, i + 1, j, m, n, node, word, result);
        // Check to the left of the letter
        search(board, i, j - 1, m, n, node, word, result);
        // Check to the right of the letter
        search(board, i, j + 1, m, n, node, word, result);

        // Adding the visited letters back onto the board after searching in every possible direction for a word beginning with the char we started with
        board[i][j] = c;
    }
};