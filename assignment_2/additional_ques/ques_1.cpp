#include <bits/stdc++.h>
using namespace std;

int countPairs(int arr[], int n, int k) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (abs(arr[i] - arr[j]) == k) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter k: ";
    cin >> k;
    int ans = countPairs(arr, n, k);
    cout << "Count of pairs with difference " << k << " is: " << ans << endl;

    return 0;
}