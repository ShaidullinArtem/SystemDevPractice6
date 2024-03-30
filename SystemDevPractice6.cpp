#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;


const vector<char> symbols = { ',', '!', '.', ':', ';', '?', '&', '%', '@', '#', '$', '*', '(', ')', '_', '+', '-', '=', '{', '}', '[', ']', '|', '/', '<', '>', '~', '`', '^' };

bool isWord(const string s) {
	return s.find_first_not_of("0123456789,!.:;?&%@#$*()_+-={}[]|/<>~`^'") == 0;
}

bool isSymbol(char symbol) {
	return find(symbols.begin(), symbols.end(), symbol) != symbols.end();
}

int main() {

	string text, stream;

	cout << "Enter text:" << endl;
	//getline(cin, text);
	
	text = "Hello my, name is1414 Artem! I`am 17n yours! My job is programming!";
		
	stringstream ss(text);

	unsigned short count = 1;

	while (getline(ss, stream, ' ')) {
		char lastSymble;

		if (count % 2 == 0) {
			lastSymble = stream.back();
			stream.pop_back();

			if (isWord(stream)) {
				if (isSymbol(lastSymble)) {
					reverse(stream.begin(), stream.end());
					stream += lastSymble;
				} else stream += lastSymble;
			}

		}

		cout << stream << endl;

		++count;
	}

	return 0;
}
