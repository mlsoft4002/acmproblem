#include<iostream>
#include<string>
using namespace std;

string ConvertDecimalSystemToOtherSystem(int number, int system){
	if (number == 0) return "0";
	string result = "";
	string lib[16]={"0","1","2","3","4","5","6","7","8","9","A","B","C", "D","E","F"};
	while (number){
		result = lib[number%system] + result;
		number /= system;
	}
	return result;
}

int main(){
	int number, system;
	while (cin >> number >> system){
		if (number<0){
			cout << "-";
			number = -number;
		}
		cout << ConvertDecimalSystemToOtherSystem(number, system) << endl;
	}
	return 0;
}
