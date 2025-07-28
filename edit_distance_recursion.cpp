#include<bits/stdc++.h>
using namespace std;

int editDist(string s1, string s2, int i, int j)
{
    if(i < 0) //we have to insert all characters of string2 here
        return j + 1;
    if(j < 0) //we have to delete all characters from string1
        return i + 1;
    
    if(s1[i] == s2[j])
        return editDist(s1, s2, i-1, j-1);
        
    
    int del = editDist(s1, s2, i-1, j);
    int ins = editDist(s1, s2, i, j-1);
    int rep = editDist(s1, s2, i-1, j-1);
    
    return 1 + min({del, ins, rep});
    
}
int main()
{
    string s1 = "horse", s2 = "ros";
    int solution = editDist(s1, s2, s1.length(), s2.length());
    
    cout<<solution<<endl;

    return 0;
}
