#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> solution;
int n;

bool isPalindrome(string word)
{
    string temp = word;
    reverse(temp.begin(), temp.end());
    
    return temp == word;
}
void solve(int start, string& word, vector<string>& curr)
{
    if(start == n)
    {
        solution.push_back(curr);
        return;
    }
    
    //i - 1 to  end - curr
    for(int i=start;i<n;i++)
    {
        string temp = word.substr(start,i - start + 1);
        if(isPalindrome(temp))
        {
            curr.push_back(temp);
            solve(i+1,word, curr);
            curr.pop_back();
        }
    }
}
int main()
{
   
    string word = "happy";
    n = word.size();
    
    vector<string> curr;
    solve(0, word,curr);
    
    //print all the partitions
    for(int i=0;i<solution.size();i++)
    {
        for(string s : solution[i])
            cout<<s<<" ";
        cout<<endl;
    }
    
    return 0;
}
