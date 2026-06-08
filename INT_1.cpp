#include <iostream>
#include <vector>
using namespace std;

void mergeArray(vector<int> &a, int left, int mid, int right){
    vector<int> L(a.begin() + left, a.begin() + mid + 1);
    vector<int> R(a.begin() + mid + 1, a.begin() + right + 1);
    int i = 0, j = 0, k = left;

    while(i < L.size() && j < R.size()){
        if (L[i] <= R[j]) a[k++] = L[i++];
        else a[k++] = R[j++];
    }

    while(i < L.size()) a[k++] = L[i++];
    while(j < R.size()) a[k++] = R[j++];
}

void mergeSort(vector<int> &a, int left, int right){
    if(left >= right) return;

    int mid = (left + right) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);
    mergeArray(a, left, mid, right);
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
	int n; 
	if (!(cin >> n)) return 0;
	vector <int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	cout << n << "\n";
	mergeSort(a, 0, n -1);
	for (int i = 0; i < n; i++) cout << a[i] << "\n";
	return 0;
}
