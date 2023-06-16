#include<bits/stdc++.h>
using namespace std;

int findSqrtX(int x)
{
    int start = 1,end = x;

    while(start<=end)
    {
        int mid = start + (end - start)/2;
        if(mid == x/mid) 
            return mid;
        else if (mid > x / mid)
            end = mid+1;
        else 
            start = mid-1;

    }

    if(end*end == x) return end;
    else return start;
}
int main()
{
    int x;
    cin>>x;
    cout<<findSqrtX(x);
}