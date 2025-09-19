#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void bsort(int a[], int n) {
    int c = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            c++;
            if (a[j] > a[j + 1]) {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\nComparisons: " << c << "\n";
}

void isort(int a[], int n) {
    int c = 0;
    for (int i = 1; i < n; i++) {
        int k = a[i], j = i - 1;
        while (j >= 0 && a[j] > k) {
            c++;
            a[j + 1] = a[j];
            j--;
        }
        c++;
        a[j + 1] = k;
    }
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\nComparisons: " << c << "\n";
}

void ssort(int a[], int n) {
    int c = 0;
    for (int i = 0; i < n - 1; i++) {
        int m = i;
        for (int j = i + 1; j < n; j++) {
            c++;
            if (a[j] < a[m]) m = j;
        }
        int t = a[i];
        a[i] = a[m];
        a[m] = t;
    }
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\nComparisons: " << c << "\n";
}

void shsort(int a[], int n) {
    int c = 0;
    for (int g = n / 2; g > 0; g /= 2) {
        for (int i = g; i < n; i++) {
            int t = a[i], j = i;
            while (j >= g && a[j - g] > t) {
                c++;
                a[j] = a[j - g];
                j -= g;
            }
            c++;
            a[j] = t;
        }
    }
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\nComparisons: " << c << "\n";
}

int main() {
    srand(time(0));

    int a[20], b[20], c[20], d[20];
    for (int i = 0; i < 20; i++) {
        int r = 1 + rand() % 100;
        a[i] = b[i] = c[i] = d[i] = r;
    }

    cout << "Bubble:\n";    bsort(a, 20);
    cout << "Insertion:\n"; isort(b, 20);
    cout << "Selection:\n"; ssort(c, 20);
    cout << "Shell:\n";     shsort(d, 20);

    int p[100], q[100], r1[100], s[100];
    for (int i = 0; i < 100; i++) {
        int z = 1 + rand() % 100;
        p[i] = q[i] = r1[i] = s[i] = z;
    }

    cout << "\nFor 100 elements:\n";
    cout << "Bubble:\n";    bsort(p, 100);
    cout << "Insertion:\n"; isort(q, 100);
    cout << "Selection:\n"; ssort(r1, 100);
    cout << "Shell:\n";     shsort(s, 100);
}
