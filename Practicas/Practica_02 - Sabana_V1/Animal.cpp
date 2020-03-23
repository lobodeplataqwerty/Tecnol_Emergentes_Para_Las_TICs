#include"IA.cpp"
#include"Escaner.cpp"
using namespace std;
class Animal : public IA, public Escaner{
public:
	Animal(string especie,int x,int y,string obstaculo);
	Animal(string especie,int x,int y,string objetivo, char i);
	
	void cambiar_sentido_anterior_01();
	void cambiar_sentido_anterior_02();
	
	void invertir_sentido();
	//metodos get y set
	string set_especie();
	char set_sexo();
	double set_peso();
	double set_altura();
	char set_tipo();
	bool set_vivo();
	bool set_instinto();
	string set_ss();
	void get_especie(string especie);
	void get_sexo(char sexo);
	void get_peso(double peso);
	void get_altura(double altura);
	void get_tipo(char tipo);
	void get_vivo(bool estado);
	void get_instinto(bool dato);
	void get_ss(string ss);
private:
	string especie,ss;
	char sexo;//Macho - M / Hembra - H / Indefinido I
	double peso, altura;
	char tipo;//Carnivoro / Hervivoro / Indefinido
	bool vivo, instinto;
protected:
	void cambiar_equipo(string dato);
	void cambiar_obstaculo(string dato);
	void cambiar_objetivo(string dato);
};
Animal::Animal(string especie,int x,int y,string objetivo){
	this->especie = especie;
	sexo = 'I';
	peso = 0.0;
	altura = 0.0;
	tipo = 'I';
	cambiar_equipo(especie);
	cambiar_objetivo(objetivo);
	cambiar_obstaculo(objetivo);
	set_lx(x);
	set_ly(y);
	vivo = true;
	instinto = false;
	reestablecer_vista();
}
Animal::Animal(string especie,int x,int y,string objetivo, char i){
	this->especie = especie;
	sexo = 'I';
	peso = 0.0;
	altura = 0.0;
	cambiar_equipo(especie);
	cambiar_objetivo(objetivo);
	set_lx(x);
	set_ly(y);
	vivo = true;
	instinto = false;
	reestablecer_vista();
	tipo = i;
}
void Animal::cambiar_equipo(string dato){
	set_e(dato.substr(0,1));
}
void Animal::cambiar_obstaculo(string dato){
	set_obs(dato.substr(0,1));
}
void Animal::cambiar_objetivo(string dato){
	get_obj(dato.substr(0,1));
}
void Animal::cambiar_sentido_anterior_01(){
	if(get_s() == "arriba"){
		set_s("derecha");
	}else{
		if(get_s() == "derecha"){
			set_s("abajo");
		}else{
			if(get_s() == "abajo"){
				set_s("izquierda");
			}else{
				if(get_s() == "izquierda"){
					set_s("arriba");
				}
			}
		}
	}
}
void Animal::cambiar_sentido_anterior_02(){
	if(ss == "arriba"){
		set_s("izquierda");
	}else{
		if(ss == "derecha"){
			set_s("arriba");
		}else{
			if(ss == "abajo"){
				set_s("derecha");
			}else{
				if(ss == "izquierda"){
					set_s("abajo");
				}
			}
		}
	}
}
void Animal::invertir_sentido(){
	if(get_s() == "arriba"){
		set_s("abajo");
	}else{
		if(get_s() == "derecha"){
			set_s("izquierda");
		}else{
			if(get_s() == "abajo"){
				set_s("arriba");
			}else{
				if(get_s() == "izquierda"){
					set_s("derecha");
				}
			}
		}
	}
}
string Animal::set_especie(){return especie;}
char Animal::set_sexo(){return sexo;}
double Animal::set_peso(){return peso;}
double Animal::set_altura(){return altura;}
char Animal::set_tipo(){return tipo;}
bool Animal::set_vivo(){return vivo;}
bool Animal::set_instinto(){return instinto;}
string Animal::set_ss(){return ss;}
void Animal::get_especie(string especie){this->especie = especie;}
void Animal::get_sexo(char sexo){this->sexo = sexo;}
void Animal::get_peso(double peso){this->peso = peso;}
void Animal::get_altura(double altura){this->altura = altura;}
void Animal::get_tipo(char tipo){this->tipo = tipo;}
void Animal::get_vivo(bool estado){this->vivo = estado;}
void Animal::get_instinto(bool dato){this->instinto = dato;}
void Animal::get_ss(string ss){this->ss = ss;}
