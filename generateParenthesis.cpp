#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

void backtrack(int open, int close, int n,string sol,vector<string>& result)
{
    if(open == n && close == n)
    {
        //reached the end of the solution
        result.push_back(sol);
        return;
    }

    if (open < n)
        //can add more open brackets
        backtrack(open+ 1,close,n, sol + "(",result);

    if(close < open) ///for adding more closing brackets
        backtrack(open,close + 1,n,sol + ")",result);

}
vector<string> generateParenthesis(int n) {
       
    vector<string> result;
    string sol = "";
    backtrack(0,0,n,"", result);
    return result;
}

int main()
{
    int n = 3;
    vector<string> solution = generateParenthesis(n);
    
    for(auto &sol : solution)
        cout<<sol<<endl;

    return 0;
}