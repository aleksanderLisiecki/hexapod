#include <iostream>
#include <vector>
#include <cmath>

#define PI 3.14159265

#define sprawdzanie_zera(zero) (zero==0 ? (zero = 1e-10):(zero))

 #define debug(str) do { std::cout << "debug: " << str << std::endl; } while( false );
//to print debug message use: "debug('message')"

using namespace std;

//dlugosci nog

int l1 = 39;
int l2 = 90;
int l3 = 180;
int l=10;




vector<double> inv_kin(double x, double y, double z);

double naRadiany(double);
double naStopnie(double);

double theta1(double r, double z, double theta2);
double theta2(double r, double z);
double theta3(double x, double y);




int main(){
    vector<double> v;
	vector<double> katy;
    double x, y, z;

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
    }else if(270 < odleglosc_wspolrzednych){
        cout << "!!!UWAGA!!! dlugosc ramienia jest wieksza niz 270" << endl;
    }

	katy = inv_kin(x, y, z);


//kinematyka prosta w celu sprawdzenia kinematyki odwrotnej ________________________________________________________________________________
    double theta1 = naRadiany(katy[0]);
    double theta2 = naRadiany(katy[1]);
    double theta3 = naRadiany(katy[2]);















//kinematyka prosta w celu sprawdzenia kinematyki odwrotnej ________________________________________________________________________________



    }while(1);


    return 0;
}

vector<double> inv_kin(double x, double y, double z){
    double t1=0;
    double t2;
    double t3 = theta3(x, y);
debug("theta3: " << t3)
    double r = sqrt(pow(x,2.0) + pow(y,2.0));
    t2 = theta2(r, z);
 //   t1 = theta1(r, z, t2);

    vector<double> vct_inv_kin;
    vct_inv_kin.push_back(t1);
    vct_inv_kin.push_back(t2);
	vct_inv_kin.push_back(t3);

    cout << "theta1: " << t1 << endl << "theta2: " << t2 << endl << "theta3: " << t3 << endl;

    if(t1 > 180 || t2 > 180 || t3 > 180){
        cout << "UWAGA!!! - kat wiekszy niz 180" << endl;
    }


    return vct_inv_kin;
}



/*
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
*/


double theta2(double r, double z){
    r -= l1;
    z -= l;
    double theta2_acos_licznik = pow(r, 2.0) + pow(z, 2.0) - pow(l2, 2.0) - pow(l3, 2.0);
    double theta2_acos_mianownik = 2 * l2 * l3;


    double spr_t2 = 180 - naStopnie(acos(theta2_acos_licznik / theta2_acos_mianownik));
debug("theta2: " << spr_t2)



debug("c_pitagorasem: " << sqrt( pow(z,2.0) + pow(r, 2.0) ))
debug("c_cosinusami: " << sqrt( pow(l2,2.0) + pow(l3, 2.0) - 2 * l2 * l3 * cos(naRadiany(spr_t2))  ) )




    return 180 - naStopnie(acos(theta2_acos_licznik / theta2_acos_mianownik));
}

double theta3(double x, double y){
    if(y==0){
        if(x>0){
            return 180;
        }else if(x<0){
            return 0;
        }
    }

    if(x==0){
        return 90;
    }else{
        return 90 + naStopnie(atan(y/x));
    }
}











double naRadiany(double stopnie){
    return stopnie * PI / 180.0;
};
double naStopnie(double radiany){
    return radiany * 180.0 / PI;
};
