#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
class Escenario{
public:
	Escenario();
	string get_escenario(int cx,int cy);
	void set_escenario(int cx,int cy,string dato);
	void imprimir_escenario();
	int get_ex();
	int get_ey();
	int get_sx();
	int get_sy();
	int get_x();
	int get_y();
	void generar_entrada();
	void generar_salida();
private:
	string matriz [12][12];
	int ex,ey,sx,sy,x,y;
};
Escenario::Escenario(){
	x = 12;
	y = 12;
	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			if(i == 0 || i == x-1){
				matriz[i][j]="#";
			}else{
				if(j == 0 || j == x-1){
					matriz[i][j]="#";
				}else{
					matriz[i][j]=" ";
				}
			}
		}
	}
	ex = ey = sx = sy=0;
	
}
string Escenario::get_escenario(int cx,int cy){return matriz[cx][cy];}
void Escenario::set_escenario(int cx,int cy,string dato){matriz[cx][cy] = dato;}
void Escenario::imprimir_escenario(){
	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			cout<<matriz[i][j];
		}
		cout<<""<<endl;
	}
}
int Escenario::get_ex(){return ex;}
int Escenario::get_ey(){return ey;}
int Escenario::get_sx(){return sx;}
int Escenario::get_sy(){return sy;}
int Escenario::get_x(){return x;}
int Escenario::get_y(){return y;}
void Escenario::generar_entrada(){
	int a = x - 1;
	int b; 
	srand(time(NULL));
	b = rand()%a;
	while(b == 0||b == a){
		b = rand()%a;
	}
	matriz[b][0]=" ";
	ey = b;
}
void Escenario::generar_salida(){
	int a = x - 1;
	int b; 
	srand(time(NULL));
	b = rand()%a;
	while(b == ey || b == 0 || b == a){
		b = rand()%a;
	}
	matriz[b][a]=" ";
	sx = b;
	sy = a;
}
