#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

struct triangle {
	double x1, y1, x2, y2, x3, y3;
};

// calculate perimeter of triangle
double perimeter(triangle t);

// find maximum in vector
double maxP(vector<double> d);

int main() {
	ifstream file;
	file.open("data.txt");
	
	vector<triangle> t;
	
	double x1, y1, x2, y2, x3, y3;
	while(file >> x1 >> y1 >> x2 >> y2 >> x3 >> y3){
		t.push_back({x1,y1,x2,y2,x3,y3});
	}
	
	vector<double> p;
	for (int i=0; i < t.size(); i++){
		//cout << t[i].x1 << t[i].y1 << t[i].x2 << t[i].y2 << t[i].x3 << t[i].y3 << endl;
		cout << perimeter(t[i]) << endl;
		p.push_back(perimeter(t[i]));
	}
	
	// find the biggest perimeter
	cout << "Biggest perimeter is: " << maxP(p);
	
	return 0;
}

double perimeter(triangle t) {
	double ax, ay, bx, by, cx, cy;
	double a, b, c;
	
	ax = t.x1 - t.x2;
	ay	= t.y1 - t.y2;
	a = sqrt(ax*ax + ay*ay);
	
	bx = t.x2 - t.x3;
	by	= t.y2 - t.y3;
	b = sqrt(bx*bx + by*by);
	
	cx = t.x1 - t.x3;
	cy	= t.y1 - t.y3;
	c = sqrt(cx*cx + cy*cy);
	
	return a+b+c;
}

double maxP(vector<double> d) {
	int tmp = 0;
	for(int i = 1; i < d.size(); i++) {
		// return the first occurence if two perimeter are equal!
		if (d[i] > d[i-1]){
			tmp = i;
		}
	}
	return d[tmp];
}