#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
//using ll = long long

ll steps(int l, int r)
{
    ll L = 1;
    ll totalSteps = 0;
    ll currSteps = 1;
    
    while(L <= r)
    {
        ll R = 4*L - 1; //we increment L by 4
        ll start = max((ll)l, L);
        ll end   = min((ll)r, R);
        
        if(start <= end)
            totalSteps += (end - start + 1) * currSteps;
            
        currSteps++;
        L*=4;
    }
    
    return (totalSteps+1)/2;
}
int main() {
    
    vector<vector<int>> queries = {{1,2},{5,10},{2,4}};
    int q = queries.size();
    ll stepsRequired = 0;
    
    for(int i=0;i<q;i++)
    {
        int l = queries[i][0], r = queries[i][1];
        stepsRequired += steps(l, r);
    }
    
    cout<<"Steps Required:"<<stepsRequired<<endl;
    return 0;
}
