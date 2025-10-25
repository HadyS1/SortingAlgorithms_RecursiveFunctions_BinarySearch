#include<iostream>

using namespace std;

bool sequential_search(string arr[], string e, int n) {
	bool found = false;
	int i = 0;
	while (i < n && !found) {
		if (arr[i] == e) {
			found = true;
		}
		else {
			i++;
		}
	}
	return found;
}

int nombre_occurences(string arr[], string e, int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i]==e){
			count++;
		}
	}
	return count;
}

bool sequential_search_sorted(string arr[], string e, int n) {
	int i = 0;
	bool found = false;
	bool possible = true;
	while (i < n && possible && !found) {
		if (arr[i] == e) {
			found = true;
		}
		else if (arr[i] > e) {
			possible = false;
		}
		else {
			i++;
		}
	}
	return found;
}

bool issorted(string arr[], int n) {
	bool sorted = true;
	for (int i = 0; i < n-1; i++) {
		if (arr[i] > arr[i + 1])
			sorted = false;
		break;
	}
	return sorted;
}

/*
int main() {
	string arr[] = { "Hi", "Hello", "Hola", "Marhaba", "Bonjour", "Hi"};
	if (sequential_search(arr, "Hi", 6)) {
		cout << "Found" << endl;
	}
	cout << "Le nombre d'occurences est: " << nombre_occurences(arr, "Hi", 6) << endl;

	if (issorted(arr, 6)) {
		sequential_search_sorted(arr, "Hi", 6);
	}

	return 0;
}
*/