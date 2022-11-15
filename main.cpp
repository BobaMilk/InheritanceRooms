#include <iostream>
#include <vector>

using namespace std;
//You are to design a home with rooms shaped of both triangles and rectangles.  
//Implement a base class Shape and a derived classes Rectangle and Triangle.  
//Supply virtual functions double area().
//Fill a vector of Shape* pointers with a mixture of the shapes with each shape representing one room within a house.  
//Compute the total area of the home by summing all the areas of the shapes within the vector.  
//Display the total.

 
//You cannot use any protected members.Also your derived classes may not have any of the same private members as the base class.

//triangle 1/2 base * height
//rectangle base * height

class Shape {
public:
	virtual double area() { //returns the area
		return 0;
	}
private:
};

class Triangle : public Shape {
public:
	Triangle(double b, double h) {
		this->base = b;
		this->height = h;
		this->area1 = (0.5) * base * height;
	}
	double area() {
		return area1;
	}
private:
	double base;
	double height;
	double area1;
};

class Rectangle : public Shape {
public:
	Rectangle(double b, double h) {
		this->base = b;
		this->height = h;
		this->area1 = base * height;
	}
	double area() {
		return area1;
	}
private:
	double base;
	double height;
	double area1;
};


int main()
{
	vector<Shape*> shapes;
	double total = 0;

	//Declaring some pointers to new objects to work with
	Triangle* t = new Triangle(2.9,4.7);
	Rectangle* r = new Rectangle(7.0,2.6);
	//Pushing it back to the vector
	shapes.push_back(t);
	shapes.push_back(r);

	for (int i = 0; i < shapes.size(); i++) { //Adds each area to the total vairable
		total += shapes.at(i)->area();
		cout << "Area of shape" << i+1 << ": " << shapes.at(i)->area() << endl;
	}

	cout << "\nTotal: " << total << endl;
}
