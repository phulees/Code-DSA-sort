#include <iostream>
#include <vector>
#include <string>

using namespace std;

void merge(vector<const string*>& arr, int left, int mid, int right, vector<const string*>& temp) {
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right) {
        if (*arr[i] <= *arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (int p = left; p <= right; p++) arr[p] = temp[p];
}

void mergeSort(vector<const string*>& arr, int left, int right, vector<const string*>& temp) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, temp);
        mergeSort(arr, mid + 1, right, temp);
        merge(arr, left, mid, right, temp);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<string> strings(n);
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        cin >> strings[i];
        if (strings[i].length() > maxLen) {
            maxLen = strings[i].length();
        }
    }

    vector<vector<const string*>> lengthBuckets(maxLen + 1);

    for (int i = 0; i < n; i++) {
        lengthBuckets[strings[i].length()].push_back(&strings[i]);
    }

    cout << n << "\n";
    
    for (int len = 0; len <= maxLen; len++) {
        int b_size = lengthBuckets[len].size();
        if (b_size > 0) {
            vector<const string*> temp(b_size);
            
            if (b_size > 1) {
                mergeSort(lengthBuckets[len], 0, b_size - 1, temp);
            }
            
            for (int i = 0; i < b_size; i++) {
                cout << *lengthBuckets[len][i] << "\n";
            }
        }
    }

    return 0;
}
