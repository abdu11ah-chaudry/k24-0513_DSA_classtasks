#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[1000];
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int g = n / 2; g > 0; g /= 2) {
        for (int i = g; i < n; i++) {
            int t = a[i], j = i;
            while (j >= g && a[j - g] > t) {
                a[j] = a[j - g];
                j -= g;
            }
            a[j] = t;
        }
    }

    for (int i = 0; i < n; i++) cout << a[i] << " ";
}
