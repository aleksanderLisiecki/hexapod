#include <iostream>
#include <vector>
#include <cmath>

#define PI 3.14159265

#define debug(str) do { std::cout << "debug: " << str << std::endl; } while( false )
//to print debug message use: "debug('message');"

using namespace std;

//dlugosci nog

int a = 90;
int b = 180;

vector<double> inv_kin(double, double);
double theta1(double x, double y, double theta2);
double theta2(double x, double y);




int main(){
    vector<double> v;
    double x, y;
/*
    for(int iy=0; iy<=270; iy+5){
        for(int ix=0; ix<=270; ix+5){
            inv_kin(ix, iy);
        }
        cout << endl;
    }
*/

    do{
    cout << "Podaj x, y" << endl <<"x: ";
    cin >> x;
    cout << "y: ";
    cin >> y;
    inv_kin(x,y);
    }while(1);


    return 0;
}

double k(double zmienna_kwadrat){
    return zmienna_kwadrat * zmienna_kwadrat;
    }

vector<double> inv_kin(double x, double y){
    double t1;
    double t2 = theta2(x,y);
    t1 = theta1(x, y, t2);

    vector<double> vct_inv_kin;
    vct_inv_kin.push_back(t1);
    vct_inv_kin.push_back(t2);

    cout << "theta1: " << t1 << endl << "theta2: " << t2 << endl;

    if(theta1 > 180 || theta2 > 180){
        cout << "UWAGA!!! - kat wiekszy niz 180" << endl;
    }

    //return vct_inv_kin;
}

double theta1(double x, double y, double theta2){

    double alfa = abs(atan(x/y) * (180.0) / PI);

    debug(alfa);

    double c = sqrt((x*x) + (y*y));
    double beta;
    double beta_asin_licznik = (sin(theta2 * PI / 180.0)) * b;
    beta = asin(beta_asin_licznik / c) * (180.0) / PI;

    debug(beta);

    if(y < 0){
        return alfa + 2*(90-alfa) + beta;
    }else{
        return alfa + beta;
    }
}

double theta2(double x, double y){
    double theta2_acos_licznik = (x*x)+(y*y)-(a*a)-(b*b);
    double theta2_acos_mianownik = 2 * a * b;
    return (acos(theta2_acos_licznik / theta2_acos_mianownik)) * (180.0) / PI;
}


