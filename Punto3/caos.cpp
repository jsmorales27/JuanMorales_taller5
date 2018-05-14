#include <iostream>
#include <typeinfo>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;
#define ep 1/1000
#define a 1/(2*sqrt(2))

float funcionP1_punto(float q1, float q2);
float runge_kutta1(float q1,float q2, float h);
float funcionP2_punto(float q1, float q2);
float runge_kutta2(float q1, float q2, float h);

int main (){
	float q1=a;
	float p1=0;
	float q2=-a;
	float p2=0;
	float dt=0.006;
	float t=0;
	while (t<=100){
		cout<<q1<<","<<p1<<","<<t<<"\n";
		cout<<q2<<","<<p2<<","<<t<<"\n";
		p1=p1+(dt*runge_kutta1(q1,q2,dt));  /// lo que hago es derivar q1(punto) para asi obtener una ecuacion
		q1=q1+(dt*p1);                      /// de segundo grado, y reemplazar la funcion de p1(punto)
		p2=p2+(dt*runge_kutta2(q1,q2,dt));  /// y usar  la separacion de ecuaciones diferenciales
		q2=q2+(dt*p2);                      /// para hallar q1, y luego en el mismo instante de tiempo,
		t=t+dt;                             /// reemplazar en la ecuacion de q2 y asi resolver para q2. 
		}
	return 0;
}

float funcionP1_punto(float q1, float q2){
	return -2*q1/(pow((4*q1*q1)+(ep*ep),3/2));
}

float funcionP2_punto(float q1, float q2){
	float termino1=(q1-q2)/(pow(pow(q1-q2,2)+(ep*ep/4),3/2));
	float termino2=(q1+q2)/(pow(pow(q1+q2,2)+(ep*ep/4),3/2));
	return termino1-termino2;
}

float runge_kutta1(float q1, float q2, float h){
	float k1=funcionP1_punto(q1,q2);
	float k2=funcionP1_punto(q1+h/2,q2);
	float k3=funcionP1_punto(q1+h/2,q2);
	float k4=funcionP1_punto(q1+h,q2);
	return (k1+2*k2+2*k3+k4)/6;             /// Runge Kutta de cuarto orden (Wikipedia)
} 

float runge_kutta2(float q1,float q2, float h){
	float k1=funcionP2_punto(q1,q2);
	float k2=funcionP2_punto(q1,q2+h/2);
	float k3=funcionP2_punto(q1,q2+h/2);
	float k4=funcionP2_punto(q1,q2+h);
	return (k1+2*k2+2*k3+k4)/6;
}


