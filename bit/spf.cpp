//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void sieve() {}

    vector<int> findPrimeFactors(int N) {

        vector<int> spf(N+1);
        vector<int> factors;
        
        //intital index value.
        for(int i = 0 ; i <= N ; i++)  spf[i] = i;
        
        //filling it with the first factor.
        for(int i = 2 ; i*i <= N ; i++)
        {
            if(spf[i] == i)
            {
                for(int j = i*i ; j <= N ; j+=i)
                {
                    if(spf[j] == j)
                        spf[j] = i;
                }
            }
        }
        
        while(N != 1)
        {
            factors.push_back(spf[N]);
            N /= spf[N];
        }
        
        return factors;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n;
        cin >> n;

        Solution obj;
        obj.sieve();
        vector<int> vec = obj.findPrimeFactors(n);
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << endl;

        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends