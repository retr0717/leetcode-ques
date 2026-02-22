#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node* links[26];

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
};

int countDistinctSubstrings(string &s)
{
    Node* root = new Node();
    int count = 0;

    for(int i = 0 ; i < s.length(); i++)
    {
        Node* node = root;

        for(int j = i; j < s.length(); j++)
        {
            if(!node->containsKey(s[j]))
            {
                count++;
                node->put(s[j], new Node());
            }

            node = node->get(s[j]);
        }
    }

    return count+1;
}

int main()
{
    string s = "ababa";
    cout<<countDistinctSubstrings(s)<<endl;
}