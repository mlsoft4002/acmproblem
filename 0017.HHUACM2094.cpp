#include<iostream>
using std::cin;
using std::cout;
using std::endl;
#include<string>
using std::string;
#include<cstdlib>

#define MAX_SIZE 10

int** a;
size_t aSizeX, aSizeY;
int** b;
size_t bSizeX, bSizeY;
int** c;
size_t cSizeX, cSizeY;

void allocateMemory(void){
	a = new int*[MAX_SIZE];
	b = new int*[MAX_SIZE];
	c = new int*[MAX_SIZE];
	for (size_t i = 0; i != MAX_SIZE; ++i){
		a[i] = new int[MAX_SIZE];
		b[i] = new int[MAX_SIZE];
		c[i] = new int[MAX_SIZE];
	}
}

void write(int** r, const size_t sizeX, const size_t sizeY) {
	for (size_t i = 0; i != sizeX; ++i) {
		for (size_t j = 0; j != sizeY; ++j) {
			cin >> r[i][j];
		}
	}
}

void add(void){
	cSizeX = aSizeX;
	cSizeY = aSizeY;
	for (size_t i = 0; i != aSizeX; ++i) {
		for (size_t j = 0; j != aSizeY; ++j) {
			c[i][j] = a[i][j] + b[i][j];
		}
	}
}

void sub(void){
	cSizeX = aSizeX;
	cSizeY = aSizeY;
	for (size_t i = 0; i != aSizeX; ++i) {
		for (size_t j = 0; j != aSizeY; ++j) {
			c[i][j] = a[i][j] - b[i][j];
		}
	}
}

void mul(void){
	cSizeX = aSizeX;
	cSizeY = bSizeY;
	for (size_t i = 0; i != aSizeX; ++i) {
		for (size_t j = 0; j != bSizeY; ++j) {
			c[i][j] = 0;
			for (size_t k = 0; k != aSizeY; ++k) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}

void copy(void){
	aSizeX = bSizeX;
	aSizeY = bSizeY;
	for (size_t i = 0; i != aSizeX; ++i) {
		for (size_t j = 0; j != aSizeY; ++j) {
			a[i][j] = b[i][j];
		}
	}
}

void print(void){
	for (size_t i = 0; i != cSizeX; ++i) {
		for (size_t j = 0; j != cSizeY - 1; ++j) {
			cout << c[i][j] << " ";
		}
		cout << c[i][cSizeY - 1] << endl;
	}
}

int main(void){
	allocateMemory();
	unsigned int testTimes;
	string op;
	cin >> testTimes;
	while (testTimes--){
		cin >> aSizeX >> aSizeY;
		write(a, aSizeX, aSizeY);
		cin >> bSizeX >> bSizeY;
		write(b, bSizeY, bSizeY);
		while (cin >> op, op.length() != 3){
			switch (op[0])
			{
			case '+':
				add();
				print();
				cout << endl;
				break;
			case '-':
				sub();
				print();
				cout << endl;
				break;
			case '*':
				mul();
				print();
				cout << endl;
				break;
			case '=':
				copy();
				break;
			}
		}
	}
	return 0;
}
