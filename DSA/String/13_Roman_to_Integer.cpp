#include <iostream>
#include <unordered_map>
using namespace std;

int romanToInt(string s) {
    unordered_map<char, int> roman = {
        {'I', 1}, {'V', 5}, {'X', 10},
        {'L', 50}, {'C', 100},
        {'D', 500}, {'M', 1000}
    };
    
    int result = 0;
    int n = s.size();

    for (int i = 0; i < n; i++) {
        int curr = roman[s[i]];
        int next = (i + 1 < n) ? roman[s[i + 1]] : 0;

        if (curr < next) {
            result -= curr;
        } else {
            result += curr;
        }
    }

    return result;
}

int main() {
    string s;
    cout << "Enter Roman numeral: ";
    cin >> s;

    int num = romanToInt(s);
    cout << "Integer value: " << num << endl;

    return 0;
}
