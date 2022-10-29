//{ Driver Code Starts
// C++ implementation to convert a
// sentence into its equivalent
// mobile numeric keypad sequence
#include <bits/stdc++.h>
using namespace std;
string printSequence(string input);
// Driver function
int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s;
        getline(cin, s);
        cout << printSequence(s) << endl;
    }
    return 0;
}

// } Driver Code Ends

string printSequence(string S)
{
    string result = "";

    for (size_t i = 0; i < S.size(); i++)
    {
        if (S[i] == ' ')
            result += '0';
        else if ((int)S[i] >= 65 && (int)S[i] < 80)
        {
            for (size_t j = 65 + 3*(int)(((int)S[i] - 65) / 3); j <= (int)S[i]; j++)
            {
                if (j >= 65 && j < 68){
                    result += '2';
                } else if (j >= 68 && j < 71){
                    result += '3';
                } else if (j >= 71 && j < 74){
                    result += '4';
                } else if (j >= 74 && j < 77){
                    result += '5';
                } else{
                    result += '6';
                }
            }
        }
        else if ((int)S[i] >= 80 && (int)S[i] < 84)
        {
            for (size_t j = 80; j <= (int)S[i]; j++)
            {
                result += '7';
            }
        }
        else if ((int)S[i] >= 84 && (int)S[i] < 87)
        {
            for (size_t j = 84; j <= (int)S[i]; j++)
            {
                result += '8';
            }
        }
        else if ((int)S[i] >= 87 && (int)S[i] <= 90)
        {
            for (size_t j = 87; j <= (int)S[i]; j++)
            {
                result += '9';
            }
        }
    }
    return result;
}