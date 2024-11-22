//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int priority(char c)
    {
        switch(c)
        {
            case '^': return 3;
            case '/': return 2;
            case '*': return 2;
            case '+': return 1;
            case '-': return 1;
            case '(': return -1;
        }
        
        return -1;
    }
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        string postFix = "";
        stack<char> opStack;
        
        for(auto it : s)
        {
            if((it >= 'a' && it <= 'z') || (it >= '0' && it <= '9') || (it >= 'A' && it <= 'Z'))
                postFix += it;
            else if(it == '(') opStack.push(it);
            else if(it == ')')
            {
                while(opStack.top() != '(')
                {
                    postFix += opStack.top();
                    opStack.pop();
                }
                opStack.pop();
            }
            else
            {
                while(!opStack.empty() && (priority(opStack.top()) >= priority(it)))
                {
                    postFix += opStack.top();
                    opStack.pop();
                }
                opStack.push(it);
            }
        }
        
        while(!opStack.empty())
        {
            postFix += opStack.top();
            opStack.pop();
        }
        
        return postFix;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends