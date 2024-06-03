class Solution {
public:
    int appendCharacters(string s, string t) {
        
        int slen = s.length();
        int tlen = t.length();

        int x = 0, y = 0;

        while(x < slen && y < tlen)
        {
            if(s[x] == t[y])
            {
                x++;
                y++;
            }  
            else 
                x++;
        }
        
        // if(y == tlen)
        //     return 0;

        string toBeAppended = t.substr(y, tlen-y);
        return toBeAppended.length();

    }
};
