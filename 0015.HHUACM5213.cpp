#include<iostream>
using std::cin;
using std::cout;
using std::endl;
#include<string>
using std::string;
#include<cstdlib>

string binToOct(const string& bin){
	string oct;
	string::size_type ix;
	string::size_type len =bin.length();
	switch (len % 3 != 0){
	case 1:
		oct.append(1, bin[0]);
		ix = 1;
		break;
	case 2:
		oct.append(1, (bin[0] - '0') * 2 + bin[1]);
		ix = 2;
		break;
	default:
		ix = 0;
	}
	while(ix != len){
		oct.append(1,(bin[ix]-'0')*4+(bin[ix+1]-'0')*2+bin[ix+2]);
		ix += 3;
	}
	while (oct[0] == '0' && oct.length() > 1){
		oct.erase(0, 1);
	}
	return oct;
}

string hexToBin(const string& hex){
	string bin;
	string::size_type len = hex.length();
	for (string::size_type ix = 0; ix != len; ++ix){
		switch (hex[ix]){
		case '0':
			bin.append("0000");
			break;
		case '1':
			bin.append("0001");
			break;
		case '2':
			bin.append("0010");
			break;
		case '3':
			bin.append("0011");
			break;
		case '4':
			bin.append("0100");
			break;
		case '5':
			bin.append("0101");
			break;
		case '6':
			bin.append("0110");
			break;
		case '7':
			bin.append("0111");
			break;
		case '8':
			bin.append("1000");
			break;
		case '9':
			bin.append("1001");
			break;
		case 'A':
			bin.append("1010");
			break;
		case 'B':
			bin.append("1011");
			break;
		case 'C':
			bin.append("1100");
			break;
		case 'D':
			bin.append("1101");
			break;
		case 'E':
			bin.append("1110");
			break;
		case 'F':
			bin.append("1111");
			break;
		}
	}
	return bin;
}

int main(void){
	unsigned int times;
	string hexNumber;
	cin >> times;
	while (times--){
		cin >> hexNumber;
		cout << binToOct(hexToBin(hexNumber)) << endl;
	}
	return 0;
}
