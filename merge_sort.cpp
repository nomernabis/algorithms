#include<iostream>

void merge(int* arr, int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1] = {};
    int R[n2] = {};
    for(int i = l, j = 0; i <= m; ++i, ++j){
        L[j] = arr[i];
    }
    for(int i = m+1, j=0; i <= r; ++i, ++j){
        R[j] = arr[i];
    }
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(L[i] < R[j]){
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }
    while(i < n1){
        arr[k] = L[i];
        ++i;
        ++k;
    }
    while(j < n2){
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

void merge_sort(int* arr, int l, int r){
    if (l < r){
        int m = (l + r) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main(){
    int N = 12;
    int arr[N] = {-2, 4, 8, 21, 29, 0, -100, 50, 44, 22, 6, 1};
    merge_sort(arr, 0, N - 1);
    for(int i=0; i < N; ++i){
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    return 0;
}
