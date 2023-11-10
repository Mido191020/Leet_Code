class MyQueue {
public:
 
  std::stack<int> s1, s2;

    MyQueue() {
        // Constructor
    }

    void push(int x) {
        // Push element x to the back of the queue
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop() {
        // Remove the element from the front of the queue and return it
        if (s1.empty())
            return -1;
        int x = s1.top();
        s1.pop();
        return x;
    }

    int peek() {
        // Get the front element
        if (s1.empty())
            return -1;  // Queue is empty
        return s1.top();
    }

    bool empty() {
        // Returns true if the queue is empty, false otherwise
        return s1.empty();
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