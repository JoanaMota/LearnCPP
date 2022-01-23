#include <iostream>
#include <unordered_set>
#include <vector>

class WordDictionarySet
{
private:
    std::unordered_set<std::string> words;

public:
    WordDictionarySet()
    {
    }

    void addWord(std::string word)
    {
        words.insert(word);
    }

    bool search(std::string word)
    {
        if (words.count(word))
        {
            return true;
        }
        if (words.empty())
        {
            return false;
        }
        bool ans{false};
        for (std::string w : words)
        {
            if (w.size() != word.size())
            {
                continue;
            }

            bool equalWord{true};
            for (int i = 0; i < word.size(); i++)
            {
                if (w[i] != word[i] && word[i] != '.')
                {
                    equalWord = false;
                    break;
                }
            }
            if (equalWord == true)
            {
                ans = true;
                break;
            }
        }
        return ans;
    }
};

struct TrieNode
{
    std::vector<TrieNode *> kids;
    bool isWord{false};

    TrieNode()
    {
        kids = std::vector<TrieNode *>(26, nullptr);
    }

    bool containsKey(char ch)
    {
        return (kids[ch - 'a'] != NULL);
    }
    void add(char ch, TrieNode *node)
    {
        kids[ch - 'a'] = node;
    }
    TrieNode *get(char ch)
    {
        return kids[ch - 'a'];
    }
    void setEnd()
    {
        isWord = true;
    }
    bool isEnd()
    {
        return isWord;
    }
    bool search(std::string &s, int curr)
    {
        if (curr == s.size())
        {
            return isWord;
        }
        if (s[curr] == '.')
        {
            for (int i = 0; i < 26; ++i)
            {
                if (kids[i] && kids[i]->search(s, curr + 1))
                {
                    return true;
                }
            }
        }

        return s[curr] != '.' && kids[s[curr] - 'a'] && kids[s[curr] - 'a']->search(s, curr + 1);
    }
};
class WordDictionary
{
private:
    TrieNode *m_root;

public:
    WordDictionary()
    {
        m_root = new TrieNode();
    }

    void addWord(std::string word)
    {
        TrieNode *node = m_root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->add(word[i], new TrieNode());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(std::string word)
    {
        return m_root->search(word, 0);
    }
};

int main()
{
    WordDictionary *wordDictionary = new WordDictionary();
    wordDictionary->addWord("bad");
    wordDictionary->addWord("dad");
    wordDictionary->addWord("mad");
    std::cout << std::boolalpha << wordDictionary->search("pad") << std::endl; // return False
    std::cout << std::boolalpha << wordDictionary->search("bad") << std::endl; // return True
    std::cout << std::boolalpha << wordDictionary->search(".ad") << std::endl; // return True
    std::cout << std::boolalpha << wordDictionary->search("b..") << std::endl; // return True
}