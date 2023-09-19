class Solution {
private:
    unordered_map<char,string> myMap = {
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"}
    };

    void backtrack(vector<string>& solution, string& curr, string digits,int start) {

        if(start == digits.length())
        {
            solution.push_back(curr);
            return;
        }

        string letters = myMap[digits[start]];

        for(int i=0;i<letters.length();i++) {

            curr.push_back(letters[i]);
            backtrack(solution,curr,digits,start+1);
            curr.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> solution;

        if(digits.length() == 0)
            return solution;

        string curr = "";
        backtrack(solution,curr,digits,0);
        return solution;
    }

};
