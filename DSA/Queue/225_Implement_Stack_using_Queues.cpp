#include <iostream>
#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q;

public:
    MyStack() {}

    void push(int x) {
        q.push(x);
        int size = q.size();
        for (int i = 0; i < size - 1; ++i) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    vector<string> operations = {"MyStack", "push", "push", "top", "pop", "empty"};
    vector<vector<int>> values = {{}, {1}, {2}, {}, {}, {}};

    MyStack* obj = nullptr;
    for (int i = 0; i < operations.size(); ++i) {
        if (operations[i] == "MyStack") {
            obj = new MyStack();
            cout << "null" << endl;
        } else if (operations[i] == "push") {
            obj->push(values[i][0]);
            cout << "null" << endl;
        } else if (operations[i] == "pop") {
            cout << obj->pop() << endl;
        } else if (operations[i] == "top") {
            cout << obj->top() << endl;
        } else if (operations[i] == "empty") {
            cout << boolalpha << obj->empty() << endl;
        }
    }

    delete obj;
    return 0;
}
