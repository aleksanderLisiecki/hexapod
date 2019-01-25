#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

//kinematyka odw
vector<double>KinOdw(double,double,double);
//pomocnicze
double naStopnie(double);
int l1=39;
int l2=90;
int l3=180;
double PI=3.14159265;
double x,y,z;

int main()
{
    vector<double> v;
    v.push_back(0.0);
    v.push_back(0.0);
    v.push_back(0.0);
    while(1)
    {
    cout << "Podaj kolejno x, y, z" << endl;
    cin >> x;
    cin >> y;
    cin >> z;
    cout << "x = " << x << ", y = " << y << ", z = " << z << endl;
    v = KinOdw(x,y,z);
    }

    return 0;
}

//kinematyka odwrotna
vector<double> KinOdw(double px, double py, double pz)
{
    //te 4 linie to inicjalizacja wektora do przechwywania nastaw katów
	vector<double> T;
	T.push_back(0.0);
	T.push_back(0.0);
	T.push_back(0.0);

	//stale pomocnicze
	double pr = sqrt(px*px + py*py);
	double a = 1;
	double c = (pz - a)*(pz - a) + (pr - l1)*(pr - l1);
	c = sqrt(c);
	double k = ((l3*l3) - (l2*l2) - (c*c)) / (-2 * l2*c);
	double alfakin = acos(k);
	double m = (pz - a) / (pr - l1);
	double betakin = acos((pr - l1) / c);

	double d = z-a;
	double l = (pr*pr)+(d*d);
	l = sqrt(l);
	double beta = acos(((l*l)+(pr*pr)-(d*d))/(2*l*pr));
	double alfa = acos(((l2*l2)+(l*l)-(l3*l3))/(2*l2*l));
	double alfa2 = acos(((l2*l2)+(pr*pr)-(l3*l3))/(2*l2*pr));

	//Od teraz nas interesuje
	T[0] = atan2(py, px);//jeden kat
	if(z>a)T[1] = (PI/2)-alfa-beta;
	else if(z<a)T[1] = (PI/2)-alfa+beta;
	else if(z=a)T[1]=(PI/2)-alfa2;
	T[2] = ((c*c) - (l2*l2) - (l3*l3)) / (2 * (l2*l3));
	T[2] = acos(T[2]);//trzeci

	//kinematyka wprost

        double q2[2];//punkty na zalamaniach;
        double q3[2];
        q2[0] = sin(T[1])*l2;
        q2[1] = cos(T[1])*l2+a;
        q3[0] = q2[0]+cos(T[2]-(PI/2)+T[1]);
        q3[1] = q2[1]-sin(T[2]-(PI/2)+T[1]);
        double prr,zp,xp,yp;
        zp = q3[1];
        prr = q3[0];
        xp = prr*cos(T[0]);
        yp = prr*sin(T[0]);
        xp = naStopnie(xp);
        yp = naStopnie(yp);
        zp = naStopnie(zp);


    //zamiana na stopnie
	T[0] = naStopnie(T[0]);
	T[1] = naStopnie(T[1]);
	T[2] = naStopnie(T[2]);
	if(T[0]<0 || T[0]>180 || T[1]<0 || T[1]>180 || T[2]<0 || T[3]>180)cout << "Poza zasiegiem nogi" << endl;
	else
    {
        cout << "teta1 = " << T[0] << ", teta2 = " << T[1] << ", teta3 = " << T[2] << endl;
        cout << "Wyliczone: x = " << xp << ", y = " << yp << ", z = " << zp << endl;
    }

	return T;
}

double naStopnie(double a)
{
	a = a * 180.0 / PI;
	return a;
}
