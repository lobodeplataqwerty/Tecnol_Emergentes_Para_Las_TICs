using namespace std;
class COLA{
public:
	COLA();
	int size();
	void push(int dato);
	int pop();
	int top();
	bool empty();
	void vaciar();
private:
	int matriz[16],n,n1,n2;
};
COLA::COLA(){
	n = -1;
	n1 = 16;
	n2 = n1 - 3;
	for(int i = 0; i < n1; i++){
		matriz[i] = 0;
	}
}
int COLA::size(){
	return n+1;
}
void COLA::push(int dato){
	n++;
	matriz[n] = dato;
}
int COLA::pop(){
	int dato = matriz[0];
	for(int i = -1; i <= n2; i++){
		matriz[i+1] = matriz[i+2];
	}
	return dato;
}
int COLA::top(){
	return matriz[n];
}
bool COLA::empty(){
	if(n != -1){
		return false;
	}
	return true;
}
void COLA::vaciar(){
	n = -1;
}
