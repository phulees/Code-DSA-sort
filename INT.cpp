#include <iostream>
#include <vector>
#include <string>

using namespace std;

void merge(vector<const string*>& arr, int left, int mid, int right, vector<const string*>& temp) {
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (*arr[i] <= *arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (int p = left; p <= right; p++) {
        arr[p] = temp[p];
    }
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
    vector<const string*> ptrs(n);
    vector<const string*> temp(n);

    for (int i = 0; i < n; i++) {
        cin >> strings[i];
        ptrs[i] = &strings[i];
    }

    if (n > 1) {
        mergeSort(ptrs, 0, n - 1, temp);
    }

    cout << n << "\n";
    for (int i = 0; i < n; i++) {
        cout << *ptrs[i] << "\n";
    }

    return 0;
}
