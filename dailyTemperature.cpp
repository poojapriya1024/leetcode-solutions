/* brute force approach */


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
    
    vector<int> solution;
    int count = 0; 
    for(int i=0;i<n-1;i++)
    {
        if(temperatures[i] < temperatures[i+1])
        // if the temperatures gets warmer the very next day
            solution.push_back(1); 
        else
        {
            //find the next warmer temperature
            while(count != n-i)
            {
                if(temperatures[i] >= temperatures[i+count])
                    count++;
                else
                {  
                    solution.push_back(count);
                    break;
                }
            }

            if(count == n - i) //no warmer temperature is found
            { 
                count = 0;
                solution.push_back(count);
            }
            count = 0;
            
        }
        
    }
    
    solution.push_back(0);
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