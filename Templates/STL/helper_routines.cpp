void readArray(vector<ll>& arr, int n) {
    arr.resize(n);
    for (auto &a: arr) {
        cin >> a;
    }
}

void readParallelArrays(vector<ll>& arr1, vector<ll>& arr2, int n) {
    arr1.resize(n);
    arr2.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr1[i];
        cin >> arr2[i];
    }
}

void sortArray(vector<ll>& arr) {
    sort(arr.begin(), arr.end());
}