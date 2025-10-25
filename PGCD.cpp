#include<iostream>
using namespace std;

int pgcd(int n1, int n2) {
	int pgcd = -1;
	if (n1 < n2) {
		for (int i = 2; i < n1-1; i++) {
			if (n1 % i == 0 && n2 % i == 0) {
				pgcd = i;
			}
		}
	}
	else {
		for (int i = 2; i < n2; i++) {
			if (n1 % i == 0 && n2 % i == 0) {
				pgcd = i;
			}
		}
	}
	return pgcd;
}

//Euclid's theorem:  gcd(50,15)=gcd(15,5)=5
unsigned int pgcd_Euclide(unsigned int m, unsigned int n) {
	unsigned int rem;
	while (n > 0) {
		rem = m % n;
		m = n;
		n = rem;
	}
	return(m);
}
/*
Avec le modulo le remainder devient < la moitie: m% n <= m / 2.
	donc m < m / 2 et n < n / 2; ainsi de suite, pour obtenir
	au plus 2log n = O(log n), sachant que n <= m
*/

/*
int main() {
	int n1, n2;
	cout << "Entrez le premier nombre:  ";
	cin >> n1;
	
	cout << "Entrez le second nombre:  ";
	cin >> n2;

	cout << pgcd(n1, n2);

	return 0;
}
*/