#include<bits/stdc++.h>
using namespace std;

string removeDelimiters(string s)
{  
        //initialize a new string
        string myString = "";

        for(int i=0;i<s.length();i++)
        {
            if(isalnum(s[i]))
                // convert it into lower case before appending 
                myString += tolower(s[i]);
        }

        cout<<"New string is : "<<myString<<endl;
        return myString;
}


bool isPalindrome(string s) 
{
        string myString = removeDelimiters(s);
        int slen = myString.size();

        if (slen == 0 || slen == 1)
            return true; //as all empty strings and single characters are palindromes 


        int l = 0;
        int r = slen - 1;

        while(l <= r)
        {
            if(myString[l] == myString[r])
            {   
                //move the pointers
                l++;
                r--;

            }
            else 
                return false;

        }
        
        return true;

}


int main()
{
    
    string s1 = "race a car"; //not a palindrome
    string s2 = "._."; //palindrome
    string s3 = "A man, a plan, a canal: Panama"; //palindrome

    bool res1 = isPalindrome(s1);
    bool res2 = isPalindrome(s2);
    bool res3 = isPalindrome(s3);

    cout<<res1<<" "<<res2<<" "<<res3;
    return 0;
}