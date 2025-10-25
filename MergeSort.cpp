#include<iostream>
using namespace std;

void merge(int arr[], int l, int m, int r) {
	int n1 = m - l + 1;
	int n2 = r - m;
	int* L = new int[n1];
	int* R = new int[n2];

	for (int i = 0; i < n1; i++) {
		L[i] = arr[l + i];
	}
	for (int j = 0; j < n2; j++) {
		R[j] = arr[m + 1 + j];
	}

	int i = 0, j = 0, k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
	delete[] L;
	delete[] R;

}

void MergeSort(int arr[], int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;

		MergeSort(arr, l, m);
		MergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}


/*
void PrintList(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}

int main() {
	int arr[] = { 2,5,4,1,6,7 };
	
	int n = sizeof(arr) / sizeof(arr[0]);
	MergeSort(arr, 0, n - 1);
	PrintList(arr, 6);
	return 0;
}
*/