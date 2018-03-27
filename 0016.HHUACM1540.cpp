#include<iostream>
using std::cin;
using std::cout;
using std::endl;
#include<string>
using std::string;
#include<sstream>
using std::istringstream;
#include<cstdlib>

#define BIT_MAX_NUMBER 26

int prime[BIT_MAX_NUMBER];

void makePrimesBasedNumber(int primes[], const unsigned int number){
	unsigned int current = 2u;
	primes[0] = 2; primes[1] = 3;
	for (int i = 5; current < number; i += 2){
		bool flag = true;
		for (int j = 1; primes[j] * primes[j] <= i; ++j){
			if (i%primes[j] == 0){ flag = false; break; }
		}
		if (flag){ primes[current++] = i; }
	}
}

void printMarsNumber(const int* n){
	size_t pos = 0;
	while (n[pos] == 0){
		++pos;
	}
	cout << n[pos];
	++pos;
	while (pos != BIT_MAX_NUMBER){
		cout << ',' << n[pos];
		++pos;
	}
	cout << endl;
}

void split(int* array, const string& str){
	istringstream sin(str);
	char comma;
	memset(array, 0, BIT_MAX_NUMBER * sizeof(int));
	sin >> array[BIT_MAX_NUMBER - 1];
	while (sin >> comma){
		for (size_t ix = 0; ix != BIT_MAX_NUMBER - 1; ++ix){
			array[ix] = array[ix + 1];
		}
		sin >> array[BIT_MAX_NUMBER - 1];
	}

}

void add(const int* a, const int* b, int* c){
	int carry = 0;
	for (size_t ix = BIT_MAX_NUMBER - 1; ix != 0; --ix){
		int ans = a[ix] + b[ix] + carry;
		c[ix] = ans%prime[BIT_MAX_NUMBER - 1 - ix];
		carry = ans / prime[BIT_MAX_NUMBER - 1 - ix];
	}
	c[0] = carry;
}

int main(void){
	makePrimesBasedNumber(prime, BIT_MAX_NUMBER);
	string a, b;
	int marsA[BIT_MAX_NUMBER];
	int marsB[BIT_MAX_NUMBER];
	int sum[BIT_MAX_NUMBER];
	while(cin>>a>>b,a.length()!=1||b.length()!=1||a[0]!='0'||b[0]!='0')
{
		split(marsA, a);
		split(marsB, b);
		add(marsA, marsB, sum);
		printMarsNumber(sum);
	}
	return 0;
}
