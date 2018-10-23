#include<iostream>
using namespace std;

#define pi 3.14
class Shape {
	public:
		virtual double GetArea()=0;
		virtual double GetPerim()=0;
};
class Rectangle {
	private:
		double len;
		double weight;
	public:
		double GetArea() {return len*weight;}
		double GetPerim() {return 2*(len+weight);}
};
class Circle {
	private:
		double r;
	public:
		double GetArea(){return pi*r*r;}
		double GetPerim(){return 2*pi*r;}
};
int main() {

}
