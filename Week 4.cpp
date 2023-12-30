#include <iostream>
#include <cmath>
using namespace std;

double calculateArea(double side_length) {
    return 1.5 * 1.732 * side_length;
}

double calculatePerimeter(double side_length) {
    return 6 * side_length;
}

double calculateSumOfAngles() {
    return 6 * 120;
}

void displayHexagonDetails(double side_length) {
    cout << "\t\t\t\t --------------------" << endl;
    cout << "\t\t\t\t|  Hexagon Details:  |" << endl;
    cout << "\t\t\t\t --------------------" << endl;
    cout << "\n\t\t\t\tArea: " << calculateArea(side_length) << endl;
    cout << "\t\t\t\tPerimeter: " << calculatePerimeter(side_length) << endl;
    cout << "\t\t\t\tSum of Angles: " << calculateSumOfAngles() << endl;
}

double SquareArea(double side_length) {
    return pow(side_length, 2);
}

double SquarePerimeter(double side_length) {
    return 4 * side_length;
}

void displaySquareDetails(double side_length) {
    cout << "\n\t\t\t\t --------------------" << endl;
    cout << "\t\t\t\t|  Square Details:   |" << endl;
    cout << "\t\t\t\t --------------------" << endl;
    cout << "\n\t\t\t\tArea: " << SquareArea(side_length) << endl;
    cout << "\t\t\t\tPerimeter: " << SquarePerimeter(side_length) << endl;
}

int main() {
    // Use the last digit of your CNIC as the side length
    string cnic = "XY210351532";  // Replace with your CNIC
    double hexagonSideLength = cnic.back() - '0';
    double squareSideLength = hexagonSideLength + 1;

    displayHexagonDetails(hexagonSideLength);
    displaySquareDetails(squareSideLength);

    return 0;
}