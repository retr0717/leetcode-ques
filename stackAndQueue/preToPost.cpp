//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToPost(string s) {
        stack<string> st;
        
        int len = s.length() - 1;
        
        for(int i = len ; i >= 0 ; i--)
        {
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'Z'))
                st.push(string(1, s[i]));
            else
            {
                if(!st.empty())
                {
                    string t1 = st.top();
                    st.pop();
                    string t2 = st.top();
                    st.pop();
                    string tExp = t1 + t2 + s[i];
                    st.push(tExp);
                }
            }
        }
        
        return st.top();
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToPost(prefix) << endl;

        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToPost(string s) {
        stack<string> st;
        
        int len = s.length() - 1;
        
        for(int i = len ; i >= 0 ; i--)
        {
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'Z'))
                st.push(string(1, s[i]));
            else
            {
                if(!st.empty())
                {
                    string t1 = st.top();
                    st.pop();
                    string t2 = st.top();
                    st.pop();
                    string tExp = t1 + t2 + s[i];
                    st.push(tExp);
                }
            }
        }
        
        return st.top();
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToPost(prefix) << endl;

        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}