class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int m = s1.size();
        int n = s2.size(); 

        if(m > n) // if the s1 is greater than s2, it cannot be a permutation
            return false; 

        vector<int> freq1(26); // hash table for s1
        vector<int> freq2(26); // hash table for s2

        // find the frequencies for s1 and first window of s2

        for(int i=0;i<m;i++)
        {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }

        // start checking for permutations 
        for(int i=m;i<n;i++)
        {
            if(freq1 == freq2) // if the frequencies are equal
                return true; 

            // else, remove the first character (at index i - m) from the current window
            freq2[s2[i-m] - 'a']--;
            // add the current character to the window (at index i)
            freq2[s2[i] - 'a']++;

        }

        return (freq1 == freq2);
    }
};
