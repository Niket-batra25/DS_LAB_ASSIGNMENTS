#include <bits/stdc++.h>
using namespace std;

bool anagrams(string str1, string str2) {
    if (str1.length() != str2.length()) return false;
    int count[26] = {0};
    for (int i = 0; i < str1.length(); i++) {
        count[str1[i] - 'a']++;
        count[str2[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) return false;
    }
    return true;
}

int main() {
    string str1, str2;
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;
    if (anagrams(str1, str2))
        cout << "Anagrams\n";
    else
        cout << "Not Anagrams\n";
    return 0;
}