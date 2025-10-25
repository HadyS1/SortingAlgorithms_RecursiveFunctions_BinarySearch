#include <iostream>

using namespace std;

unsigned int factorial(int n) {
	if (n <= 1) {
		return 1;
	}
	else {
		return (n * factorial(n - 1));
	}
}
/*
La fonction factoriel recursive peut etre exprimee comme suit:
 T(0)=1 => 1 comparison
 T(n)=T(n-1)+3 => 1 comparison, 1 multiplication, 1 soustraction
 T(n)=T(n-1)+3=(T(n-2)+3)+3=(T(n-3)+3 )+3+3=...=T(n-n)+3n=3n => Theta(n)
*/

int power(int x, int n) {
	if (n == 0) {
		return 1;
	}
	else if (n == 1) {
		return x;
	}
	else if (n % 2 == 0) {
		return power(x*x, n / 2);
	}
	else {
		return power(x * x, n / 2) * x;
	}
}
/*
A chaque iteration, on divise n par 2 et non incrementation par -1
A la derniere iteration k, on aura n/2^k =1 donc k=log(n) = theta(n)
*/

unsigned int fibonacci(unsigned int n){
	if (n == 1 || n == 2)
		return 1;
	else
		return(fibonacci(n - 1) + fibonacci(n - 2));
}
/*
Au niveau 0, on appelle 1 fois, au niveau 1, 2 fois, au niveau 2, 2^2=4 fois, au niveau 2^3=8 fois...
A chaque niveau, on a un nombre constant d’instructions ce qui fait que la complexité devient exponentielle approx O(2n) 
*/

void Hanoi(int n, char src, char dest, char interm) {
	if (n == 1) {
		cout << "Moved disk 1 from " << src << " to " << dest << endl;
	}
	else{
		Hanoi(n - 1, src, interm, dest);
		cout << "Move the disk " << n << " from "<< src << " to " << dest << endl;
		Hanoi(n - 1, interm, dest, src);
	}
}

int RecursiveSum(int arr[], int n, int sum=0) {
	if (n == 0) {
		return sum;
	}
	sum = sum + arr[n-1];
	RecursiveSum(arr, n - 1, sum);
}

string Dec_to_Bin(int n, string s = "") {
	if(n==0){
		reverse(s.begin(), s.end()); //Non optimized
		return s;
	}
	if (n % 2 == 0) {
		s.append("0");
	}
	else {
		s.append("1");
	}
	return Dec_to_Bin(n / 2, s);
}

void Dec_to_Bin2(int n) {
	if (n == 0) {
		return;
	}
	Dec_to_Bin2(n / 2); 
	cout << n % 2;
}

void RecursiveDisplay(int arr[], int n, int indice=0) {
	if (indice == n) {
		cout << endl;
		return;
	}
	else {
		cout << arr[indice] << " ";
		return RecursiveDisplay(arr, n, indice+1);
	}
}
void RecursiveDisplayUpsideDown(int arr[], int n) {
	if (n == 0) {
		cout << endl;
		return;
	}
	else {
		cout << arr[n-1] << " "; //on print l'indice qui est size-1
		return RecursiveDisplayUpsideDown(arr, n - 1);
	}
}
void RecursiveDisplayUpsideDown2(int arr[], int n, int index = 0) {
	if (index == n) return;          
	RecursiveDisplayUpsideDown2(arr, n, index + 1);
	cout << arr[index] << " ";
}

int MaxRecursive(int b[], int n) {
	if (n == 1) {
		return b[0];           // base case: only one element
	}
	int maxRest = MaxRecursive(b, n - 1);  // maximum of first n-1 elements
	return (b[n - 1] > maxRest) ? b[n - 1] : maxRest; // compare last element with max of rest
}

int main() {
	int n;
	cout << "Entrez le nombre : ";
	cin >> n;
	cout << n << "! = " << factorial(n) << endl;

	Hanoi(3, 'A', 'B', 'C');

	int arr[] = { 1,2,3,4,5,6 };
	cout << "La somme de la liste est: " << RecursiveSum(arr, 6) << endl;

	string binary = Dec_to_Bin(30);
	cout << binary << endl;
	Dec_to_Bin2(30);
	cout << endl;

	RecursiveDisplay(arr, 6);
	RecursiveDisplayUpsideDown(arr, 6);
	RecursiveDisplayUpsideDown2(arr, 6);
	cout << endl;
	cout << MaxRecursive(arr, 6);
}

