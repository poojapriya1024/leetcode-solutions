class Solution {
private:
    string stringify(stack<char>& temp) {

        if(temp.empty())
            return "";
        
        string curr = "";

        while(!temp.empty()) {

            curr = temp.top() + curr;
            temp.pop();
        }

        return curr;
    }

    string backspaceCompareHelper(string curr) {

        int len = curr.size();

        if(len == 1) {
            if(curr[0] == '#')
                return "";
            return curr;
        }

        stack<char> temp;

        for(int i=0;i<len;i++) {
            
            // if current character is #, then pop the previous character
            if(curr[i] == '#') {

                if(!temp.empty()) {
                    temp.pop();
                }
                continue;
            }

            temp.push(curr[i]);
        }

        string word = stringify(temp);
        return word;
        
    }
public:
    bool backspaceCompare(string s, string t) {

        if(s == t)
            return true;
        
        string s1 = backspaceCompareHelper(s);
        string s2 = backspaceCompareHelper(t);

        return (s1 == s2);
    }
};
