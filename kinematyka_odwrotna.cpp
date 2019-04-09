#include <iostream>
#include <vector>
#include <cmath>

#define PI 3.14159265

#define sprawdzanie_zera(zero) (zero==0 ? (zero = 1e-10):(zero))

 #define debug(str) do { std::cout << "debug: " << str << std::endl; } while( false );
//to print debug message use: "debug('message')"

using namespace std;


//spis funkji_________________________________________________________
vector<double> inv_kin(double x, double y, double z);
double theta1(double x, double y);
double theta2(double z, double r);
double theta3(double z, double r);

double naRadiany(double);
double naStopnie(double);
//spis funkji_________________________________________________________

int a = 39;
int b = 10; // na oko
int c = 90;
int d = 180;








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
    double t1 = theta1(x, y);
debug("theta1: " << t1)
    double t2;
    double t3;

    double r = sqrt(pow(x,2.0) + pow(y,2.0));

    t2 = theta2(z, r);
debug("theta2: " << t2)
    t3 = theta3(z, r);
debug("theta3: " << t3)

    vector<double> vct_inv_kin;
    vct_inv_kin.push_back(t1);
    vct_inv_kin.push_back(t2);
	vct_inv_kin.push_back(t3);

    if(t1 > 180 || t2 > 180 || t3 > 180){
        cout << "UWAGA!!! - kat wiekszy niz 180" << endl;
    }


    return vct_inv_kin;
}

double theta1(double x, double y){
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

double theta2(double z, double r){
    z+=b;
    r-=a;

    double e2 = pow((z), 2.0) + pow((r), 2.0);
    double e = sqrt(e2);

    double alfa = atan(r/z);
    double beta = acos((pow(c, 2.0) + e2 - pow(d, 2.0)) / (2 * c * e));

    return naStopnie(alfa + beta);
}

double theta3(double z, double r){
    z+=b;
    r-=a;

    double e2 = pow((z), 2.0) + pow((r), 2.0);
    return naStopnie(acos((pow(c, 2.0) + pow(d, 2.0)- e2 ) / (2 * c * d)));
}




double naRadiany(double stopnie){   return stopnie * PI / 180.0;    }
double naStopnie(double radiany){   return radiany * 180.0 / PI;    }
