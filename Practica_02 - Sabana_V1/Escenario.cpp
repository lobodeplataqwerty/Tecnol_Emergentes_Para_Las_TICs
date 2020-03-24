using namespace std;
class Escenario{
public:
	Escenario();
	string get_escenario(int x,int y);
	void set_escenario(int x,int y,string s);
	void imprimir_escenario();
	void retornar_valor(int x, int y);
	string get_simbolo();
	int get_x();
	int get_y();
private:
	string matriz [50][50], simbolo;
	int x,y;
};
Escenario::Escenario(){
	x = 50;
	y = 50;
	simbolo = ".";
	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			matriz[i][j] = simbolo;
		}
	}
}
string Escenario::get_escenario(int x,int y){return matriz[x][y];}
void Escenario::set_escenario(int x,int y,string s){matriz[x][y] = s;}
void Escenario::imprimir_escenario(){
	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			cout<<" "<<matriz[i][j];
		}
		cout<<endl;
	}
}
void Escenario::retornar_valor(int x, int y){set_escenario(x,y,simbolo);}
string Escenario::get_simbolo(){return simbolo;}
int Escenario::get_x(){return x;}
int Escenario::get_y(){return y;}
