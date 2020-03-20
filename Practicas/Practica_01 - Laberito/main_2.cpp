#include<iostream>
#include<cstdlib>
#include<windows.h>
#include"Escenario.cpp"

using namespace std;

int main(int argc, char *argv[]) {
	Escenario e;
	int cex,cey,csx,csy,jx,jy;
	e.generar_entrada();
	e.generar_salida();
	
	cex=e.get_ex();
	cey=e.get_ey();
	csy=e.get_sx();
	csx=e.get_sy();
	jx=e.get_ex();
	jy=e.get_ey();
	
	int o=0;
	int a,b,i,d;
	a=b=i=d=0;
	int ax,ay;
	ax=ay=0;
	
	cout<<"Entrada coordenadas ("<<cex<<","<<cey<<")"<<endl;
	cout<<"Salida coordenadas ("<<csx<<","<<csy<<")"<<endl;
	cout<<"Jugador coordenadas ("<<jx<<","<<jy<<")\n"<<endl;
	
	e.set_escenario(jy,jx,"X");
	e.imprimir_escenario();
	
	while(o!=1){
		system("cls");
		if(e.get_escenario(jy-1,jx) != "#"){//arriba
			if(e.get_escenario(jy-1,jx) != "X"){
				jy--;
				a++;
			}else{
				if(e.get_escenario(jy,jx+1) != "#"){//derecha
					if(e.get_escenario(jy,jx+1) != "X"){
						jx++;
						d++;
					}else{
						if(e.get_escenario(jy+1,jx) != "#"){//abajo
							if(e.get_escenario(jy+1,jx) != "X"){
								jy++;
								b++;
							}
						}else{//izquierda
							jx--;
							i++;
						}
					}
				}else{
					if(e.get_escenario(jy+1,jx) != "#"){//abajo
						if(e.get_escenario(jy,jx+1) != "X"){
							jy++;
							b++;
						}
					}else{//izquierda
						jx--;
						i++;
					}
				}
			}
		}else{
			if(e.get_escenario(jy,jx+1) != "#"){//derecha
				if(e.get_escenario(jy,jx+1) != "X"){
					jx++;
					d++;
				}
			}else{
				if(e.get_escenario(jy+1,jx) != "#"){//abajo
					if(e.get_escenario(jy,jx+1) != "X"){
						jy++;
						b++;
					}
				}else{//izquierda
					jx--;
					i++;
				}
			}
		}
		e.set_escenario(jy,jx,"X");
		Sleep(100);
		cout<<"Entrada coordenadas ("<<cex<<","<<cey<<")"<<endl;
		cout<<"Salida coordenadas ("<<csx<<","<<csy<<")"<<endl;
		cout<<"Jugador coordenadas ("<<jx<<","<<jy<<")\n"<<endl;
		e.imprimir_escenario();
		
		if(jx == csx){
			if(jy == csy){
				o=1;
			}
		}
	}
	return 0;
}
