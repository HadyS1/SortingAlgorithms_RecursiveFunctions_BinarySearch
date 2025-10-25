#include<iostream>

using namespace std;

void InsertionSort(int A[], int n) {
	int i, key;
	for (int j = 1; j < n; j++) {
		key = A[j];
		i = j - 1;
		while (i >= 0 && A[i] > key) { //We sort to the left, so the only value lost in the table will be the key
			A[i + 1] = A[i];
			i -= 1;
		}
		A[i + 1] = key; //We put the key back
	}
}
void InsertionSort2(int A[], int n) {
	int i, key;
	for (int j = 1; j <n; j++) {
		key = A[j];
		for (i = j; i >= 0 && A[i - 1] > key;i--) {
			A[i] = A[i-1];
		}
		A[i] = key;
	}
}

/*
void PrintList(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}

int main(){
	int arr[] = { 2,5,4,1,6,7 };
	InsertionSort(arr, 6);
	PrintList(arr, 6);
	return 0;
}*/

/*
Complexite
Cas 1 - Le meilleur cas: si le tableau est deja trie dans le bon ordre, 
alors le temps d’execution est lineaire: T(n) = Theta(n)
En effet, La condition A[i] > key est toujours fausse donc on n'entre pas dans la boucle "while"
Seule la boucle "for" compte.

Cas 2 - Le pire des cas: si le tableau d’entree est trie a l’envers,
alors le temps d’execution est quadratique: T(n) = Theta(n2)
La condition A[i] > key est toujours vraie donc on parcours toute la boucle "while"
alors cette boucle avec la boucle "for" prend Theta(n2)

Conclusion: le temps d’execution sera T(n) = O(n2), mais pas
Theta(n2), car T(n) peut prendre Theta(n) ou Theta(n2).
*/