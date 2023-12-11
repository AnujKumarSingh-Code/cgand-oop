#include<bits/stdc++.h>
using namespace std;
class convert
{
protected:
    double val1, val2;

public:
    double getInit() const
    {
        return val1;
    }

    double getConv() const
    {
        return val2;
    }
    virtual void compute() = 0;
    convert(double initval) : val1(initval), val2(0){};
};


class tempconvertor : public convert 
{
    public:
    tempconvertor(double initval) : convert(initval) {};

    void compute() override 
    {
        val2 = (val1 * 9/5) + 32;
    }
};

int main() 
{
    double initval;
    cout<<"Enter the initial value:-- ";
    cin >> initval;
    distanceconvertor distance(initval);
    tempconvertor temp(initval);
    distance.compute();
    temp.compute();
    cout<<"Initial Value: " << distance.getInit() << "meters" << endl;
    cout<<"Converted Value: " << distance.getConv() << "feet" << endl;
    cout<<"Initial Value: " << temp.getInit() << "F" << endl;
    cout<<"Converted Value: "<< temp.getConv() << "C" << endl;
    return 0;
}