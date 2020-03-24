using namespace std;
class PILA{
public:
	PILA();
	int size();//numero de elementos apilados
	void push(string dato);//apilar
	void pop();//lee y retira el elemento superior
	string top();//leer elemento superior
	bool empty();//devuelve cierto si la pila esta vacia
	void vaciar();
private:
	string matriz[4];
	int u,c;
};
PILA::PILA(){
	u = 3;
	c = 0;
	for(int i = 0; i < u+1; i++){
		matriz[i] = "";
	}
}
int PILA::size(){
	return c;
}
void PILA::push(string dato){
	for(int i = 0; i < u; i++){
		matriz[i] = matriz[i + 1];
	}
	matriz[c] = dato;
	if(c < u+1){c++;}
}
void PILA::pop(){
	if(c != 0){
		c--;
	}
}
string PILA::top(){
	return matriz[c];
}
bool PILA::empty(){
	if(c != 0){
		return false;
	}else{
		if(matriz[c] == ""){
			return true;
		}
	}
}
void PILA::vaciar(){
	c = 0;
	for(int i = 0; i < u+1; i++){
		matriz[i] = "";
	}
}
