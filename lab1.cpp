#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	ifstream input;
	ofstream output;
	input.open(argv[1]);
	output.open("output.txt");
	if (input.fail()) {
		cout << "Hey! pass a file in!" << endl;
		return 1; 
	}
	int val;
	int sum=0;
	
	while (input >> val) {
		sum = val+sum;
		output << val << "\t" << val * val << "\t" << sum << endl;
	}
	input.close();
	return 0; 
}