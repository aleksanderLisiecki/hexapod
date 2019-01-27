#include <iostream>
#include <vector>
#include <math.h>

#define PI 3.14159265

using namespace std;

//dlugosci nog

int a = 90;
int b = 180;


vector<double> inv_kin(double, double);

int main(){
    vector<double> v;
    double x, y;

    while(1)
    {
    cout << "Podaj x, y" << endl;
    cin >> x;
    cin >> y;
    inv_kin(x,y);
    }
    return 0;
}

double k(double zmienna_kwadrat){
    return zmienna_kwadrat * zmienna_kwadrat;
    }

vector<double> inv_kin(double y, double x){

    double theta2 = (acos(((x*x)+(y*y)-(a*a)-(b*b))/(2*a*b)))* (180.0) / PI;

    cout << theta2;

    double alfa = atan(x/y);



}
