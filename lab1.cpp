#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	ifstream input;
	input.open(argv[1]);
	if (input.fail()) {
		cout << "Hey! pass a file in!" << endl;
		return 1; 
	}
	int val;
	int sum=0;
	
	while (input >> val) {
		sum = val+sum;
		cout << val << "\t" << val * val << "\t" << sum << endl;
	}
	input.close();
	return 0; 
}