#include <bits/stdc++.h> 
using namespace std;

struct Node{
    Node* links[26];
    int countEndWith = 0;
    int countPrefix = 0;

    bool containsKey(char ch)
    {
        return (links[ch-'a'] != NULL);
    }

    void put(char ch, Node* node)
    {
        links[ch-'a'] = node;
    }

    Node* get(char ch)
    {
        return links[ch-'a'];
    }

    void increaseEnd()
    {
        countEndWith+=1;
    }

    void increasePrefix()
    {
        countPrefix+=1;
    }

    void deleteEndWith()
    {
        countEndWith-=1;
    }

    void reducePrefix(){
        countPrefix-=1;
    }

    int getEnd()
    {
        return countEndWith;
    }

    int getPrefix()
    {
        return countPrefix;
    }
};

class Trie{

    private: struct Node* root;

    public:

    Trie(){
        root = new Node();
    }

    void insert(string &word){
        struct Node* node = root;
        for(int i = 0 ; i < word.length(); i++)
        {
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }

            node = node->get(word[i]);
            node->increasePrefix();
        }

        node->increaseEnd();
    }

    int countWordsEqualTo(string &word){
        struct Node* node = root;

        for(int i = 0 ; i < word.length(); i++)
        {
            if(node->containsKey(word[i]))
            {
                node = node->get(word[i]);
            }
            else return 0;
        }

        return node->getEnd();
    }

    int countWordsStartingWith(string &word){
        struct Node* node = root;

        for(int i = 0 ; i < word.length(); i++)
        {
            if(!node->containsKey(word[i]))
            {
                return 0;
            }
            node = node->get(word[i]);
        }

        return node->getPrefix();
    }

    void erase(string &word){
        struct Node* node = root;

        for(int i = 0 ; i < word.length(); i++)
        {
            if(node->containsKey(word[i]))
            {
                node = node->get(word[i]);
                node->reducePrefix();
            }
            else return;
        }

        node->deleteEndWith();
    }
};

int main()
{
    Trie* obj = new Trie();
    string word = "apple";
    obj->insert(word);
    cout<<obj->countWordsEqualTo(word)<<endl;
    cout<<obj->countWordsStartingWith("app")<<endl;
    obj->erase(word);
    cout<<obj->countWordsEqualTo(word)<<endl;
    cout<<obj->countWordsStartingWith("app")<<endl;
}