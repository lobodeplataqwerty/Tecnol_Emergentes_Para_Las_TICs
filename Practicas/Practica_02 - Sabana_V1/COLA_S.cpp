using namespace std;
class COLA_S{
public:
	COLA_S();
	int size();
	void push(string dato);
	string pop();
	string bas();
	string top();
	bool empty();
	void vaciar();
private:
	string matriz[8];
	int n,n1,n2;
};
COLA_S::COLA_S(){
	n = -1;
	n1 = 8;
	n2 = n1 - 3;
	for(int i = 0; i < n1; i++){
		matriz[i] = "";
	}
}
int COLA_S::size(){
	return n+1;
}
void COLA_S::push(string dato){
	n++;
	matriz[n] = dato;
}
string COLA_S::pop(){
	string dato = matriz[0];
	for(int i = -1; i < n2; i++){
		matriz[i+1] = matriz[i+2];
	}
	return dato;
}
string COLA_S::bas(){
	return matriz[0];
}
string COLA_S::top(){
	return matriz[n];
}
bool COLA_S::empty(){
	if(n != -1){
		return false;
	}
	return true;
}
void COLA_S::vaciar(){
	n = -1;
}
