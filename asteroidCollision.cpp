#include<bits/stdc++.h>
using namespace std;
   

vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> solution;
    stack<int> stck;

    for (int asteroid : asteroids) 
    {
        if(asteroid > 0)
            stck.push(asteroid);
        
        else
        {
            if(stck.empty() || stck.top() < 0)
                stck.push(asteroid);

            else
            {
                while(!stck.empty() && stck.top() > 0 && stck.top() < abs(asteroid) )
                    stck.pop();

                if(stck.empty() || stck.top() < 0)
                    stck.push(asteroid);

                else if(stck.top() == abs(asteroid) )
                    stck.pop(); //as both the asteroids gets destroyed 

                else if ( stck.top() > abs(asteroid))
                    continue;
            }
        }
    }

    while (!stck.empty()) {
        solution.insert(solution.begin(), stck.top());
        stck.pop();
    }

    return solution;
}



int main() {
    vector<int> asteroids = {10, 2, -5, 10};
    vector<int> remainingAsteroids = asteroidCollision(asteroids);
    
    cout << "Remaining asteroids: ";
    for (int asteroid : remainingAsteroids) {
        cout << asteroid << " ";
    }
    
    return 0;
}