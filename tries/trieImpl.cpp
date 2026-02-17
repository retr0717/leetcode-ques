#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch){
        return (links[ch-'a'] != NULL);
    }

    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};

class Trie{
 private:   Node* root;

 public:
    Trie() {
        root = new Node();
    }

    //insert the word.
    void insert(string word){
        struct Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if(!node->containsKey(word[i])){
                //then we should add it to the links, with the new reference node.
                node->put(word[i], new Node());
            }
            //move to the next reference if the link exists.
            node = node->get(word[i]);
        }

        //set the end reference to true as the word is inserted.
        node->setEnd();
    }

    bool search(string word)
    {
        struct Node* node = root;

        for(int i = 0 ; i < word.size() ; i++){

            //return if no link to the char node.
            if(!node->containsKey(word[i])){
                return false;
            }

            node = node->get(word[i]);
        }

        //return true if the end node flag is true, else return false.
        return node->isEnd();
    }

    bool startsWith(string word)
    {
        struct Node* node = root;

        for(int i = 0 ; i < word.length(); i++)
        {
            //if there is no link for the current character, then return false.
            if(!node->containsKey(word[i])){
                return false;
            }

            node = node->get(word[i]);
        }

        //if this reaches here means prefix exists.
        return true;
    }
};

int main() {
    Trie* obj = new Trie();
    obj->insert("hello");
    cout << obj->search("hello") << endl; // Output: 1 (true)
    cout << obj->search("hell") << endl;  // Output: 0 (false)
    cout << obj->startsWith("hell") << endl; // Output: 1 (true)
    cout << obj->startsWith("world") << endl; // Output: 0 (false)
    return 0;
}