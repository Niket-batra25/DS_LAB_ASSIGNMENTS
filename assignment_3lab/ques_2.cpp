#include <iostream>
#include <stack>
#include <string>
using namespace std;

string rev_Str(string str) {
    stack<char>s;

    for (char c : str) {
        s.push(c);
    }
    string rev;
    while (!s.empty()) {
        rev+=s.top();
        s.pop();
    }
    return rev;
}

int main() {
    string input = "datastructure";
    string output = rev_Str(input);

    cout<<"reversed string: "<<output<<endl;
    return 0;
}
