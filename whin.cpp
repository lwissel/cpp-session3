#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// calculates the mean of given int vector
double mean(vector<double> vec);

// calculates the standard deviation of given int vector
double sdev(vector<double> vec);

int main() {
	vector<double> data;
	double in;
	cout << "Reading integers divided by enter. Enter a non-number line to finish input." << endl;
	while (cin >> in) {
		data.push_back(in);
	}
	cout << endl;
	
	cout << "You entered " << data.size() << " numbers." << endl;
	cout << "The mean is " << mean(data) << endl;
	cout << "The standard deviation is " << sdev(data) << endl;
	return 0;
}

double mean(vector<double> vec) {
	int sum = 0;
	for(int i = 0; i < vec.size(); i++) {
		sum += vec[i];
	}
	return sum/vec.size();
}

double sdev(vector<double> vec) {
	double sqsum = 0;
	for(int i = 0; i < vec.size(); i++) {
		sqsum += pow(vec[i],2);
	}
	return sqrt((sqsum/vec.size()) - mean(vec)*mean(vec));
}