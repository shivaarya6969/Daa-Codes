#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, key;
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> key;

    int step = sqrt(n);
    int prev = 0;
    int comp = 0;

    while(arr[min(step, n) - 1] < key) {
        comp++;
        prev = step;
        step += sqrt(n);

        if(prev >= n) {
            cout << "Not Present\n";
            cout << "Comparisons = " << comp;
            return 0;
        }
    }

    while(arr[prev] < key) {
        comp++;
        prev++;

        if(prev == min(step, n)) {
            cout << "Not Present\n";
            cout << "Comparisons = " << comp;
            return 0;
        }
    }

    comp++;

    if(arr[prev] == key)
        cout << "Present\n";
    else
        cout << "Not Present\n";

    cout << "Comparisons = " << comp;

    return 0;
}