#include <bits/stdc++.h>
using namespace std;

void duplicateTwos(int arr[], int n) {
    int countTwos = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 2) countTwos++;
    }
    int i = n - 1;
    int j = n + countTwos - 1;
    while (i >= 0 && j >= 0) {
        if (arr[i] == 2) {
            if (j < n) arr[j] = 2;  
            j--;
            if (j < n) arr[j] = 2;
            j--;
        } else {
            if (j < n) arr[j] = arr[i];
            j--;
        }
        i--;
    }
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    duplicateTwos(arr, n);
    cout << "Modified array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}