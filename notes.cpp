#include <iostream>
using namespace std;

void age_a_yaer(int & age) 
{
	age++;
}

int main()
{
	int jack = 50;
	age_a_yaer(jack);
	cout << jack << endl;
}