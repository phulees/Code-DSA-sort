bool customIsSmaller(const string& a, const string& b) {
    int i = 0;
    while (a[i] == b[i]) { 
        i++;
    }
    return a[i] < b[i];
}
