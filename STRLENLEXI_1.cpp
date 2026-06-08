#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isSmaller(const string& l, const string& r) {
    if (l.length() != r.length()) {
        return l.length() < r.length();
    }
    return l < r; 
}

void merge(vector<string>& v, int l, int mid, int r) {
    vector<string> left(v.begin() + l, v.begin() + mid + 1);
    vector<string> right(v.begin() + mid + 1, v.begin() + r + 1);
    
    int i = 0, j = 0, k = l;
    while (i < left.size() && j < right.size()) {
        if (isSmaller(left[i], right[j]))
            v[k++] = left[i++];
        else
            v[k++] = right[j++];
    }
    while (i < left.size()) v[k++] = left[i++];
    while (j < right.size()) v[k++] = right[j++];
}

void mergeSort(vector<string>& v, int l, int r) {
    if (l >= r) return;
    int mid = (l + r) / 2;
    mergeSort(v, l, mid);
    mergeSort(v, mid + 1, r);
    merge(v, l, mid, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    if (!(cin >> n)) return 0;
    vector<string> v(n);
    for (auto& s : v) cin >> s;
    
    mergeSort(v, 0, n - 1);
    
    cout << n << "\n";
    for (auto& s : v) cout << s << "\n";
    
    return 0;
}
