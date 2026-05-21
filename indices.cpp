#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    bool found = false;

    for(int k = 0; k < n; k++) {
        int i = 0, j = n - 1;

        while(i < j) {

            if(i == k) i++;
            if(j == k) j--;

            if(i < j && arr[i] + arr[j] == arr[k]) {
                cout << i << ", " << j << ", " << k;
                found = true;
                break;
            }
            else if(i < j && arr[i] + arr[j] < arr[k])
                i++;
            else
                j--;
        }

        if(found) break;
    }

    if(!found)
        cout << "No sequence found";

    return 0;
}