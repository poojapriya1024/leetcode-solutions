class MyQueue {
private:
    stack<int> input;
    stack<int> output;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        //push element to input stack
        input.push(x);
    }
    
    int pop() {

        //return from the output stack
        if(output.empty())
        {
            //move all elements from input stack to output stack
            while(!input.empty()) 
            {
                int temp = input.top();
                output.push(temp);
                input.pop();
            }
        }

        int temp = output.top();
        output.pop();
        return temp;
        

    }
    
    int peek() {
        
        
        //return from the output stack
        if(output.empty())
        {
            //move all elements from input stack to output stack
            while(!input.empty()) 
            {
                int temp = input.top();
                output.push(temp);
                input.pop();
            }
        }

        int temp = output.top();
        return temp;

    }
    
    bool empty() {
        
        return (input.empty() && output.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
