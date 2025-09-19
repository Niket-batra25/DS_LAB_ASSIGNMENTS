#include <bits/stdc++.h>
using namespace std;

bool canSplit(string s) {
    int n = s.length();

    for (int i = 1; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            string a = s.substr(0, i);
            string b = s.substr(i, j - i);
            string c = s.substr(j);

            if ((a.find(b) != -1 && c.find(b) != -1) ||
                (b.find(a) != -1 && c.find(a) != -1) ||
                (a.find(c) != -1 && b.find(c) != -1)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    string s;
    cin >> s;
    if (canSplit(s))
        cout << "Possible\n";
    else
        cout << "Not Possible\n";
    return 0;
}