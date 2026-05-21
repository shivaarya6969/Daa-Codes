#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int comparisons = 0, shifts = 0;

    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            shifts++;
            j--;
        }

        if(j >= 0)
            comparisons++;

        arr[j + 1] = key;
    }

    cout << "Sorted Array:\n";

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\nComparisons = " << comparisons;
    cout << "\nShifts = " << shifts;

    return 0;
}