#include<bits/stdc++.h>
using namespace std;
class Quadratic{
    double a, b, c;
    public:
    Quadratic() : a(0.0), b(0.0), c(0.0) {};
    Quadratic(double coefA, double coefB, double coefC) : a(coefA) , b(coefB) , c(coefC) {};

    Quadratic operator + (Quadratic &other)  
    {
        return Quadratic(a + other.a, b + other.b, c + other.c);
    }

    Quadratic operator - (Quadratic &other) 
    {
        return Quadratic(a - other.a, b - other.b, c - other.c);
    }

    friend ostream& operator<<(ostream &out, Quadratic &q)
    {
        out<< q.a << " x^2 ";
        if(q.b >= 0) out << " + " << q.b << "x";
        else out << " - " << -q.b << "x";
        if (q.c >= 0) out << " + " << q.c;
        else out << " - " << -q.c;
        return out;
    }

    friend istream &operator>>(istream &in, Quadratic &q) 
    {
        cout << "Enter coefficient of x^2 (a): ";
        in >> q.a;
        cout << "Enter coefficient of x (b): ";
        in >> q.b;
        cout << "Enter constant term (c): ";
        in >> q.c;
        return in;
    }

    double eval(double x) const 
    {
        return a * x * x + b * x + c;
    }

    void solveQuadratic() const 
    {
        double discriminant = b * b - 4 * a * c;
        if (discriminant > 0) 
        {
            double root1 = (-b + sqrt(discriminant)) / (2 * a);
            double root2 = (-b - sqrt(discriminant)) / (2 * a);
            cout << "Root 1: " << root1 << endl;
            cout << "Root 2: " << root2 << endl;
        } 
        
        else if (discriminant == 0) 
        {
            double root = -b / (2 * a);
            cout << "Repeated root: " << root << endl;
        } 
        
        else 
        {
            cout << "Complex roots" << endl;
        }
    }
};
int main()
{
    Quadratic q1, q2;
    cout << "Enter coefficients for the first quadratic equation:\n";
    cin >> q1;

    cout << "Enter coefficients for the second quadratic equation:\n";
    cin >> q2;

    Quadratic sum = q1 + q2;
    Quadratic difference = q1 - q2;
    cout << "First quadratic: " << q1 << endl;
    cout << "Second quadratic: " << q2 << endl;
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << difference << endl;
    cout << "Evaluating the first quadratic equation at x = 2: " << q1.eval(2) << endl;
    cout << "Evaluating the second quadratic equation at x = 3: " << q2.eval(3) << endl;
    cout << "Solving the first quadratic equation:\n";
    q1.solveQuadratic();

    return 0;
}