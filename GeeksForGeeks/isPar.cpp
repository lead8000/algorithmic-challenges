//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> pil;

        for (size_t i = 0; i < x.size(); i++)
        {
            if (pil.size() > 0 && (x[i] == ')' && pil.top() == '(' ||
                x[i] == ']' && pil.top() == '[' ||
                x[i] == '}' && pil.top() == '{') )
                pil.pop();
            else 
                pil.push(x[i]);
        }
        
        return pil.size() == 0;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends