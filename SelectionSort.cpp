#include<iostream>
using namespace std;

void SelectionSort(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		int indice = 0;
		for (int j = 1; j < n - i; j++) {
			if (arr[j] > arr[indice]) {
				indice = j;
			}
		}
		int temp = arr[n-i-1];
		arr[n - i - 1] = arr[indice];
		arr[indice] = temp;
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
	SelectionSort(arr, 6);
	PrintList(arr, 6);
	return 0;
}*/