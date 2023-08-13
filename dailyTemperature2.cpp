/* use a monotonic decreasing stack  */


#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

vector<int> dailyTemperatures(vector<int> temperatures)
{   
    int n = temperatures.size();
    if(n == 1)
        return {0};


    vector<int> solution(n);
    stack<pair<int,int>> stck;

    for(int i = 0; i < n; i++)
    {
        while(!stck.empty() && stck.top().first < temperatures[i])
        {
            int temp = stck.top().second; 
            stck.pop();
            solution[temp] = i - temp;
        }
        stck.push(make_pair(temperatures[i], i));
    }


    return solution;
    
}
int main()
{
    vector<int> temp = {73,74,75,71,69,72,76,73};
    vector<int> solution = dailyTemperatures(temp);

    for(auto &el : solution)
        cout<<el<<" ";

    return 0; 
}