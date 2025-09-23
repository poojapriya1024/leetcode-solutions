#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {3,5,8,9,9,9,10};
    int n = arr.size(), solution = 1;
    
    sort(arr.begin(), arr.end());
    
    int count = 1; //for first element
    int prev = arr[0];
    
    for(int i=1;i<n;i++)
    {
        if(arr[i] == arr[i-1])
            continue;
        
        if(arr[i] == prev + 1)
        {
            prev++;
            count++;
            solution = max(solution, count);
        }
        else
        {
            prev = arr[i]; //start from this element
            count = 1; //reset counter
        }
    }
    
    cout<<solution<<endl;

    return 0;
}
