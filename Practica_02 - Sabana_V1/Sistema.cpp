#include"COLA.cpp"
#include"COLA_S.cpp"
using namespace std;
class Sistema{
public:
	Sistema();
	void numero_random();
	int set_numero_random();
	void limpiar_memoria_num();
	
	void string_random();
	string set_sentido();
	void limpiar_memoria_sen();
private:
	COLA MN;
	COLA_S MS;
	int Mn,Ms;
	string s[4];
};
Sistema::Sistema(){
	Mn = 16;
	Ms = 8;
	s[0] = "izquierda";
	s[1] = "derecha";
	s[2] = "arriba";
	s[3] = "abajo";
}
void Sistema::numero_random(){
	srand(time(NULL));
	int numero;
	for(int i = 0; i < Mn; i++){
		numero = rand()%49;
		if(MN.empty()){
			MN.push(numero);
		}else{
			while(numero == MN.top()){
				numero = rand()%49;
			}
			MN.push(numero);
		}
	}
}
int Sistema::set_numero_random(){
	return MN.pop();
}
void Sistema::limpiar_memoria_num(){
	MN.vaciar();
}
void Sistema::string_random(){
	srand(time(NULL));
	int numero;
	for(int i = 0; i < Ms; i++){
		numero = rand()%3;
		if(MS.empty()){
			MS.push(s[numero]);
		}else{
			while(s[numero] == MS.top()){
				numero = rand()%3;
			}
			MS.push(s[numero]);
		}
	}
}
string Sistema::set_sentido(){
	return MS.pop();
}
void Sistema::limpiar_memoria_sen(){
	MS.vaciar();
}
