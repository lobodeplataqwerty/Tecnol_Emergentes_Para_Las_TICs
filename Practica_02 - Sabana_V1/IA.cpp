using namespace std;
class IA{
public:
	IA();
	void cambiar_sentido();//cambia el sentido, con respecto al ultimo movimiento
	void cambiar_posicion();//f realizar avance
	bool regla_posicion();//1 verificar posicion con respecto al sentido
	bool regla_obstaculo(string dato);//regresa un verdadero si existe un obstaculo
	int avance_en_x();//siguiente posicion en x
	int avance_en_y();//siguiente posicion en y
	//metodos get y set
	string get_s();
	string get_e();
	int get_x();
	int get_y();
	int get_lx();
	int get_ly();
	void set_s(string s);
	void set_e(string e);
	void set_x(int x);
	void set_y(int y);
	void set_lx(int x);
	void set_ly(int y);
	void set_obs(string o);
protected:
	string s,e,obs;
	/*s - sentido: el sentido en que avanzara la IA en el escenario
	e - equipo: edintificador de la IA, puede ser igual
	obs - obstaculo: que es lo que la IA concidera un obstaculo*/
	int x,y,lx,ly;
	/*x/y: posiciones dentro del ecenario
	lx/ly: limite del valor que pueden llegar a tener x and y*/
};
IA::IA(){
	x = y = lx = ly = 0;
	s = "arriba";
	e = "J";
	obs = "#";
}
void IA::cambiar_posicion(){
	if(s == "arriba"){
		x--;
	}else if(s == "abajo"){
		x++;
	}else if(s == "izquierda"){
		y--;
	}else if(s == "derecha"){
		y++;
	}
}
bool IA::regla_posicion(){
	if(s == "arriba"){
		if(x > 0){
			return true;
		}else{
			return false;
		}
	}else{
		if(s == "abajo"){
			if(x < lx){
				return true;
			}
		}else{
			if(s == "izquierda"){
				if(y > 0){
					return true;
				}
			}else{
				if(s == "derecha"){
					if(y < ly){
						return true;
					}
				}
			}
		}
	}
	return false;
}
void IA::cambiar_sentido(){
	if(s == "arriba"){
		s = "derecha";
	}else{
		if(s == "derecha"){
			s = "abajo";
		}else{
			if(s == "abajo"){
				s = "izquierda";
			}else{
				if(s == "izquierda"){
					s = "arriba";
				}
			}
		}
	}
}
bool IA::regla_obstaculo(string dato){
	/*if(e == dato || obs == dato){*/
	if(e == dato){
		return true;
	}
	return false;
}
int IA::avance_en_x(){
	if(s == "arriba"){
		return x-1;
	}else if(s == "abajo"){
		return x+1;
	}else{
		return x;
	}
}
int IA::avance_en_y(){
	if(s == "izquierda"){
		return y-1;
	}else if(s == "derecha"){
		return y+1;
	}else{
		return y;
	}
}
string IA::get_s(){return s;}
string IA::get_e(){return e;}
int IA::get_x(){return x;}
int IA::get_y(){return y;}
int IA::get_lx(){return lx;}
int IA::get_ly(){return ly;}
void IA::set_s(string s){this->s = s;}
void IA::set_e(string e){this->e = e;}
void IA::set_x(int x){this->x = x;}
void IA::set_y(int y){this->y = y;}
void IA::set_lx(int x){this->lx = x;}
void IA::set_ly(int y){this->ly = y;}
void IA::set_obs(string o){this->obs = o;}
