#include <iostream>
using namespace std;

int recursive_binary_search(int arr[], int value, int l, int h) {
	int middle = (l + h) / 2;

	if (arr[middle] < value) {
		recursive_binary_search(arr, value, middle + 1, h);
	}
	else if (arr[middle] > value) {
		recursive_binary_search(arr, value, l, middle - 1);
	}
	else {
		return middle;
	}
}
//T(n)=T(n/2)=1 => T(n/2)=T(n/4)+1 => donc T(n) = T(0) + 1*1*1*1....*1 = 1 + n = n

int binary_search(int arr[], int value, int n) {
	int low = 0; 
	int middle; 
	int high = n - 1;
	while (low <= high) {
		middle = (high-low) / 2; 
		if (arr[middle] == value) {
			return middle;
		}

		else if (arr[middle] < value) {
			low = middle + 1;
		}
		else if (arr[middle] > value) {
			high = middle - 1;
		}
	}
	return (-1);
}
// A la premiere iteration, high-low = n-1
// A chaque iteration, la condition (high-low = n > -1) est divisee par 2.
// Donc apres k iterations qu'on suppose la derniere: -n/2^k = -1 => n < 2^k => k=log(n)

int interpolationSearch(int tab[], int e, int n) {
	int low = 0;
	int high = n - 1;

	while (low <= high && e >= tab[low] && e <= tab[high]) {
		if (low == high) {
			if (tab[low] == e) return low;
			return -1;
		}
		// Estimate the position k
		int k = low + ((double)(e - tab[low]) * (high - low)) / (tab[high] - tab[low]);

		// Check if found
		if (tab[k] == e)
			return k;
		else if (tab[k] < e)
			low = k + 1; // Search right
		else
			high = k - 1; // Search left
	}

	return -1;
}


/*
int main() {
	int n;
	cout << "Enter the number of elements in the list: ";
	cin >> n;

	int* array = new int[n];
	for (int i = 0; i < n; i++) {
		cout << "Enter the element number " << i + 1 << ": ";
		cin >> array[i];
	}

	int value;
	cout << "Enter the value to search: ";
	cin >> value;

	int index, index2;
	index = recursive_binary_search(array, value, array[0],array[n-1]);
	index2 = binary_search(array, value, n);

	cout << "The element " << value << " is at index " << index << endl;
	cout << "Double check: " << index2 << endl;

	delete[]array;
	array = nullptr;
	return 0;
}
*/