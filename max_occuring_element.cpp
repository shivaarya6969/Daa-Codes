#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;

    char arr[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int freq[26] = {0};

    for(int i = 0; i < n; i++) {
        freq[arr[i] - 'a']++;
    }

    int maxFreq = 0;
    char ch;

    for(int i = 0; i < 26; i++) {

        if(freq[i] > maxFreq) {
            maxFreq = freq[i];
            ch = i + 'a';
        }
    }

    if(maxFreq == 1)
        cout << "No Duplicates Present";
    else
        cout << ch << " - " << maxFreq;

    return 0;
}