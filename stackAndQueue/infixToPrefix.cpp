#include <bits/stdc++.h>
using namespace std;

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
  
    string infixToPrefix(string s) {
        stack<char> st;
        string exp = "", result = "";
        
        int len = s.length();
        // Reversal of original expression.
        for(int i = len-1; i >= 0; i--) {
            exp += s[i];
        }

        for(auto it : exp)
        {
            if((it >= 'a' && it <= 'z') || (it >= '0' && it <= '9') || (it >= 'A' && it <= 'Z'))
                result += it;  // If the character is operand, add it to result
            else if(it == ')') {
                st.push(it);  // Push ')' to stack
            }
            else if(it == '(') {
                while(!st.empty() && st.top() != ')') {
                    result += st.top();
                    st.pop();
                }
                if(!st.empty() && st.top() == ')') {
                    st.pop();  // Pop ')'
                }
            }
            else {
                // Handle operators
                if(it == '^') {
                    while(!st.empty() && priority(st.top()) > priority(it)) {
                        result += st.top();
                        st.pop();
                    }
                } else {
                    while(!st.empty() && priority(st.top()) >= priority(it)) {
                        result += st.top();
                        st.pop();
                    }
                }
                st.push(it);
            }
        }

        // Pop all the remaining operators from the stack
        while(!st.empty()) {
            result += st.top();
            st.pop();
        }
        
        // Reverse the result string to get the correct prefix expression
        len = result.length();
        string rev = "";
        for(int i = len - 1; i >= 0; i--)
            rev += result[i];
        
        return rev;
    }
};

// Driver Code
int main() {
    string infix = "F+D-C*(B+A)"; // Example input

    Solution obj;
    cout << obj.infixToPrefix(infix) << endl;

    return 0;
}
