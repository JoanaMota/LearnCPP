#include <iostream>
struct Node
{
    Node *kids[26];
    bool isWord = false;

    bool containsKey(char ch)
    {
        return (kids[ch - 'a'] != NULL);
    }

    void put(char ch, Node *node)
    {
        kids[ch - 'a'] = node;
    }

    void setEnd()
    {
        isWord = true;
    }

    bool isEnd()
    {
        return isWord;
    }

    Node *get(char ch)
    {
        return kids[ch - 'a'];
    }
};

class Trie
{
private:
    Node *m_root;

public:
    Trie()
    {
        m_root = new Node();
    }

    void insert(std::string word)
    {
        Node *node = m_root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }

        node->setEnd();
    }

    bool search(std::string word)
    {
        Node *node = m_root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        if (node->isEnd())
        {
            return true;
        }
        return false;
    }

    bool startsWith(std::string prefix)
    {
        Node *node = m_root;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (!node->containsKey(prefix[i]))
            {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};

int main()
{
    Trie *trie = new Trie();
    trie->insert("apple");
    std::cout << std::boolalpha << trie->search("apple") << std::endl;   // return True
    std::cout << std::boolalpha << trie->search("app") << std::endl;     // return False
    std::cout << std::boolalpha << trie->startsWith("app") << std::endl; // return True
    trie->insert("app");
    std::cout << std::boolalpha << trie->search("app") << std::endl; // return True
    return 0;
}