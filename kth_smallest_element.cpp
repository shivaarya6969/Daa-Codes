#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int n, k;
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> k;

    sort(arr, arr + n);

    if(k <= n)
        cout << k << "th smallest element = " << arr[k - 1];
    else
        cout << "Not Present";

    return 0;
}