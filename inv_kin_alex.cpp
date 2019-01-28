#include <iostream>
#include <vector>
#include <cmath>

#define PI 3.14159265

#define debug(str) do { std::cout << "debug: " << str << std::endl; } while( false );
//to print debug message use: "debug('message')"

using namespace std;

//dlugosci nog

int a = 90;
int b = 180;

vector<double> inv_kin(double x, double y, double z);
double theta1(double r, double z, double theta2);
double theta2(double r, double z);
double theta3(double x, double y);




int main(){
    vector<double> v;
    double x, y, z;
/*
    for(int iy=0; iy<=270; iy+5){
        for(int ix=0; ix<=270; ix+5){
            inv_kin(ix, iy);
        }
        cout << endl;
    }
*/

    do{
    cout << "Podaj x, y, z " << endl <<"x: ";
    cin >> x;
    cout << "y: ";
    cin >> y;
    cout << "z: ";
    cin >> z;
    double odleglosc_wspolrzednych= sqrt((x*x)+(y*y)+(z*z));
    if(odleglosc_wspolrzednych < 90){
        cout << "!!!UWAGA!!! dlugosc ramienia jest mniejsza niz 90" << endl;
    }else if(270l < odleglosc_wspolrzednych){
        cout << "!!!UWAGA!!! dlugosc ramienia jest wieksza niz 270" << endl;
    }

    inv_kin(x, y, z);
    }while(1);


    return 0;
}

vector<double> inv_kin(double x, double y, double z){
    double t1;
    double t2 = theta2(y, z);
    double t3 = theta3(x, y);
    t1 = theta1(y, z, t2);

    vector<double> vct_inv_kin;
    vct_inv_kin.push_back(t1);
    vct_inv_kin.push_back(t2);

    cout << "theta1: " << t1 << endl << "theta2: " << t2 << endl << "theta3: " << t3 << endl;

    if(t1 > 180 || t2 > 180 || t3 > 180){
        cout << "UWAGA!!! - kat wiekszy niz 180" << endl;
    }

    //return vct_inv_kin;
}

double theta1(double r, double z, double theta2){

    double alfa = abs(atan(r/z) * (180.0) / PI);

    double c = sqrt((r*r) + (z*z));
    double beta;
    double beta_asin_licznik = (sin(theta2 * PI / 180.0)) * b;
    beta = asin(beta_asin_licznik / c) * (180.0) / PI;

    if(z < 0){
        return alfa + 2*(90-alfa) + beta;
    }else{
        return alfa + beta;
    }
}

double theta2(double r, double z){
    double theta2_acos_licznik = (r*r)+(z*z)-(a*a)-(b*b);
    double theta2_acos_mianownik = 2 * a * b;
    return (acos(theta2_acos_licznik / theta2_acos_mianownik)) * (180.0) / PI;
}
//na razie theta tylko dla polowki dodatniej polowki x (z katami 90-180)
double theta3(double x, double y){
    if(x<0){
            debug(abs(atan(y/x)))
        return abs(atan(y/x)) * (180.0) / PI;
    }else{
        return 90 + (atan(x/y) * (180.0) / PI);
    }
}

