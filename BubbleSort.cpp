#include<iostream>
using namespace std;

void BubbleSort(int arr[], int n) {
	for (int j = 0; j < n; j++) {
		bool swap = false;
		for (int i = 0; i < n - j - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				swap = true;
			}
		}
		if (!swap) {
			break;
		}
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
	BubbleSort(arr, 6);
	PrintList(arr, 6);
	return 0;
}*/