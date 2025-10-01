class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        
        if(numBottles < numExchange)
            return numBottles;
        
        int full = numBottles, solution = 0;

        while(full >= numExchange)
        {
            int temp = full/numExchange;
            solution += temp*numExchange;

            full %= numExchange;
            full += temp;
        }

        solution += full;
        return solution;
    }
};
