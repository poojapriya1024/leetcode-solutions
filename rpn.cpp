#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;


int eval(int a, int b, string op)
    {   
        
        if(op == "+")
            return b+a;
        else if (op == "-")
            return b-a;
        else if (op == "*")
            return b*a;
        else
            return b/a;
    }

    int evalRPN(vector<string>& tokens) {

        if(tokens.size() == 1)
            return stoi(tokens[0]);
        
        stack<int> stck;

        for(int i=0;i<tokens.size();i++)
        {
            if ( (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/" ) && (!stck.empty()) )
            {
                int a = stck.top(); stck.pop();
                int b = stck.top(); stck.pop();
                
                stck.push(eval(a,b,tokens[i]));
                cout<<"top is "<<stck.top()<<endl;

            }

            else // a digit
            {
                stck.push(stoi(tokens[i]));
                cout<<"top is "<<stck.top()<<endl;

            }

        }

        return stck.top();
    }

int main()
{
    vector<string> tokens = {"3","11","5","+","-"}; //answer = -13
    int res = evalRPN(tokens);
    cout<<res;
    return 0;
}