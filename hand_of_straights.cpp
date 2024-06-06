class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        int hlen = hand.size();

        if(hlen % groupSize != 0)
            return false;

        if(groupSize == 1)
            return true;

        map<int,int> freq;

        for(int i=0;i<hand.size();i++)
            freq[hand[i]]++;

        while(!freq.empty())
        {
            int currentStart = freq.begin()->first;

            for(int i=0;i<groupSize;i++)
            {
                int currConsecutive = currentStart + i;
                //next consecutive character is not found
                if(freq[currConsecutive] == 0)
                    return false;

                //decrement the count
                freq[currConsecutive]--;

                if(freq[currConsecutive] == 0)
                    freq.erase(currConsecutive); 
            }
        }

        return true;
        
    }
};
