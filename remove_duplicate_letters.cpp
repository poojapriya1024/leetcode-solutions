class Solution {
public:
    string removeDuplicateLetters(string s) {
        int slen = s.length();

        if(slen == 1)
            return s;

        //this is used to keep track of the last occurance of all letters in s
        vector<int> lastOccurance(26,-1);
        //used to chack if any letter is already in solution stack
        vector<bool> inStack(26,false);
        //stack to build the solution string
        stack<char> solStack;

        for(int i=0;i<slen;i++)
            lastOccurance[s[i] - 'a'] = i;

        for(int j=0;j<slen;j++) {
        char curr = s[j];

        //if this letter is already in the solution stack, ignore
        if(inStack[curr - 'a'])
            continue;

        while(!solStack.empty() && solStack.top() > curr && lastOccurance[solStack.top() - 'a'] > j) {
            inStack[solStack.top() - 'a'] = false;
            solStack.pop();
        }

        //add the current letter
        inStack[curr - 'a'] = true;
        solStack.push(curr);
            
    }
    
    string solution = "";
    //building the solution string
    while(!solStack.empty()) {
        solution = solStack.top() + solution;
        solStack.pop();
    }

    return solution;
}
};
