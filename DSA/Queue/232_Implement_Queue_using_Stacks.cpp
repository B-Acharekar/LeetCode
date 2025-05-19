#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> s1, s2;

    void transfer() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }

public:
    MyQueue() {
    }

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        transfer();
        int front = s2.top();
        s2.pop();
        return front;
    }

    int peek() {
        transfer();
        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};


int main() {
    MyQueue* obj = new MyQueue();

    obj->push(1);
    obj->push(2);
    cout << "Peek: " << obj->peek() << endl; // Expected: 1
    cout << "Pop: " << obj->pop() << endl;   // Expected: 1
    cout << "Empty: " << (obj->empty() ? "true" : "false") << endl; // Expected: false

    delete obj;
    return 0;
}