using namespace std;
class Escaner{
public:
	void reestablecer_vista();
	bool obj_encontrado();
	bool seg_objetivo();
	//metodos get y set
	void get_vista(string dato, int x, int y);
	void get_obj(string objetivo);
	void get_sen(string sentido);
private:
	string vista[3][3],obj,sen;
	/*vista - es la matriz donde se buscara el objetivo
	obj - objetivo: lo que se buscara dentro de la vista*/
};
void Escaner::reestablecer_vista(){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			vista[i][j] = " ";
		}
	}
}
bool Escaner::obj_encontrado(){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(vista[i][j] == obj){return true;}
		}
	}
	return false;
}
bool Escaner::seg_objetivo(){
	if(sen == "arriba"){
		if(vista[2][1] == obj){
			return true;
		}
	}else{
		if(sen == "derecha"){
			if(vista[1][0] == obj){
				return true;
			}
		}else{
			if(sen == "abajo"){
				if(vista[0][1] == obj){
					return true;
				}
			}else{
				if(sen == "izquierda"){
					if(vista[1][2] == obj){
						return true;
					}
				}
			}
		}
	}
	return false;
}
void Escaner::get_vista(string dato, int x, int y){this->vista[x][y] = dato;}
void Escaner::get_obj(string objetivo){this->obj = objetivo;}
void Escaner::get_sen(string sentido){this->sen = sentido;}
