#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[1000];
    for (int i = 0; i < n; i++) cin >> a[i];

    // Bubble sort to sort the array
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }

    int x;
    cin >> x;

    int l = 0, h = n - 1, f = -1;
    while (l <= h && x >= a[l] && x <= a[h]) {
        int pos = l + ((double)(h - l) / (a[h] - a[l])) * (x - a[l]);
        if (a[pos] == x) {
            f = pos;
            break;
        }
        if (a[pos] < x) {
            l = pos + 1;
        } else {
            h = pos - 1;
        }
    }

    if (f != -1) cout << "Found at " << f;
    else cout << "Not Found";
}
