// ABSTRACTION - "Implementation Hiding"

/* ENCAPSULATION VS ABSTRACTION 

Encapsulation is the concept of bundling data (variables) and methods (functions) that operate on that data into a single unit, typically a class. It also involves restricting direct access to some components of an object to enforce data integrity and prevent unintended interference.

Key Features:

Data Hiding:
Keeps data safe from unauthorized access by marking certain attributes or methods as private or protected.
Example: Using access modifiers like private, protected, or public in languages like Java or C++.

Control Access: 
Provides getter and setter methods to control how attributes are accessed and modified.

Improves Modularity:
Code is more modular and easier to maintain since each object manages its own state.





Abstraction is the process of hiding implementation details and showing only the essential features of an object. It focuses on what an object does rather than how it does it.

Key Features:

Simplifies Complexity: 
Hides the internal workings and exposes only what is necessary for the user.

Focuses on Design:
Helps in designing systems at a high level by concentrating on essential properties.

Achieved Through:
Abstract classes and interfaces in Java, C++, Python, etc.
Overriding methods in derived classes.

*/





#include <iostream>
#include <cmath>
using namespace std;

// Abstract class
class Shape {
public:
    // Pure virtual functions
    virtual double area() const = 0;
    virtual double perimeter() const = 0;

    // Virtual destructor for proper cleanup of derived class objects
    virtual ~Shape() {}
};

// Derived class for Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    // Override the area method
    double area() const override {
        return M_PI * radius * radius;
    }

    // Override the perimeter method
    double perimeter() const override {
        return 2 * M_PI * radius;
    }
};

// Derived class for Rectangle
class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    // Override the area method
    double area() const override {
        return length * width;
    }

    // Override the perimeter method
    double perimeter() const override {
        return 2 * (length + width);
    }
};

// Main function
int main() {
    // Using pointers to base class for abstraction
    Shape* shape1 = new Circle(5.0); // Circle with radius 5
    Shape* shape2 = new Rectangle(4.0, 6.0); // Rectangle with length 4 and width 6

    cout << "Circle Area: " << shape1->area() << endl;
    cout << "Circle Perimeter: " << shape1->perimeter() << endl;

    cout << "Rectangle Area: " << shape2->area() << endl;
    cout << "Rectangle Perimeter: " << shape2->perimeter() << endl;

    // Clean up
    delete shape1;
    delete shape2;

    return 0;
}
