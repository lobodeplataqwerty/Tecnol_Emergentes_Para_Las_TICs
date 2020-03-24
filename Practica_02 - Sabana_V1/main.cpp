#include<iostream>
#include<cstdlib>
#include<ctime>
#include<windows.h>
#include<conio.h>
#include<stdio.h>
#include"Escenario.cpp"
#include"Animal.cpp"
#include"Sistema.cpp"
using namespace std;
void ocultar_cursor(){//desaparecer Cursor
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 50;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(hCon,&cci);
}
int main(int argc, char *argv[]) {
	ocultar_cursor();
	Escenario E;
	string J1 = "Leon", J2 = "Impala";
	int x =49, y = 49, tiempo = 0, i = 0;
	Animal* A[8];
	Sistema S;
	char tecla;
	
	for(i = 0; i<3; i++){A[i] = new Animal(J1,x,y,J2,'C');}
	for(i = 3; i<8; i++){A[i] = new Animal(J2,x,y,J1,'H');}

	S.numero_random();
	for(i = 0; i<3; i++){A[i]->set_x(S.set_numero_random());}
	for(i = 0; i<3; i++){A[i]->set_y(S.set_numero_random());}
	for(i = 3; i<8; i++){A[i]->set_x(S.set_numero_random());}
	for(i = 3; i<8; i++){A[i]->set_y(S.set_numero_random());}
	S.limpiar_memoria_num();
	
	S.string_random();
	for(i = 0; i<8; i++){A[i]->set_s(S.set_sentido());}
	S.limpiar_memoria_sen();
	
	for(i = 0; i<8; i++){E.set_escenario(A[i]->get_x(),A[i]->get_y(),A[i]->get_e());}
	
	E.imprimir_escenario();
	
	while(true){
		for(i = 0; i<8; i++){
			if(A[i]->set_vivo()){
				/* - Matriz de Vista -
				Inicio de introducción de datos*/
				if(A[i]->get_s() == "arriba"){
					if(A[i]->get_x() > 1){
						if(A[i]->get_y() == 0 ){
							A[i]->get_vista(E.get_escenario(A[i]->get_x() - 2, A[i]->get_y()),1,1);
							A[i]->get_vista(E.get_escenario(A[i]->get_x() - 2, A[i]->get_y() + 1),1,2);
						}else if(A[i]->get_y() > 1 && A[i]->get_y() < 49){
							A[i]->get_vista(E.get_escenario(A[i]->get_x() - 2, A[i]->get_y() - 1),1,0);
							A[i]->get_vista(E.get_escenario(A[i]->get_x() - 2, A[i]->get_y()),1,1);
							A[i]->get_vista(E.get_escenario(A[i]->get_x() - 2, A[i]->get_y() + 1),1,2);
						}else if(A[i]->get_y() == 49 ){
							A[i]->get_vista(E.get_escenario(A[i]->get_x() - 2, A[i]->get_y() - 1),1,0);
							A[i]->get_vista(E.get_escenario(A[i]->get_x() - 2, A[i]->get_y()),1,1);
						}
					}
					if(A[i]->get_x() > 0){
						A[i]->get_vista(E.get_escenario(A[i]->get_x() - 1, A[i]->get_y()),2,1);
					}
				}else if(A[i]->get_s() == "abajo"){
					if(A[i]->get_x() < 48){
						if(A[i]->get_y() == 0 ){
							A[i]->get_vista(E.get_escenario(A[i]->get_x() + 2, A[i]->get_y()),1,1);
							A[i]->get_vista(E.get_escenario(A[i]->get_x() + 2, A[i]->get_y() + 1),1,2);
						}else if(A[i]->get_y() > 1 && A[i]->get_y() < 49){
							A[i]->get_vista(E.get_escenario(A[i]->get_x() + 2, A[i]->get_y() - 1),1,0);
							A[i]->get_vista(E.get_escenario(A[i]->get_x() + 2, A[i]->get_y()),1,1);
							A[i]->get_vista(E.get_escenario(A[i]->get_x() + 2, A[i]->get_y() + 1),1,2);
						}else if(A[i]->get_y() == 49 ){
							A[i]->get_vista(E.get_escenario(A[i]->get_x() + 2, A[i]->get_y() - 1),1,0);
							A[i]->get_vista(E.get_escenario(A[i]->get_x() + 2, A[i]->get_y()),1,1);
						}
					}
					if(A[i]->get_x() < 49){
						A[i]->get_vista(E.get_escenario(A[i]->get_x() + 1, A[i]->get_y()),0,1);
					}
				}else if(A[i]->get_s() == "izquierda"){
					if(A[i]->get_y() > 1){
						if(A[i]->get_x() == 0){
							A[i]->get_vista(E.get_escenario(A[i]->get_x(), A[i]->get_y() - 1),1,1);
							A[i]->get_vista(E.get_escenario(A[i]->get_x() + 1, A[i]->get_y() - 1),2,1);
						}else if(A[i]->get_x() > 0 && A[i]->get_x() < 49){
							A[i]->get_vista(E.get_escenario(A[i]->get_x() - 1, A[i]->get_y() - 1),0,1);
							A[i]->get_vista(E.get_escenario(A[i]->get_x(), A[i]->get_y() - 1),1,1);
							A[i]->get_vista(E.get_escenario(A[i]->get_x() + 1, A[i]->get_y() - 1),2,1);
						}else if(A[i]->get_x() == 49 ){
							A[i]->get_vista(E.get_escenario(A[i]->get_x() - 1, A[i]->get_y() - 1),0,1);
							A[i]->get_vista(E.get_escenario(A[i]->get_x(), A[i]->get_y() - 1),1,1);
						}
					}
					if(A[i]->get_y() > 0){
						A[i]->get_vista(E.get_escenario(A[i]->get_x(), A[i]->get_y() - 1),1,2);
					}
				}else if(A[i]->get_s() == "derecha"){
					if(A[i]->get_y() < 48){
						if(A[i]->get_x() == 0){
							A[i]->get_vista(E.get_escenario(A[i]->get_x(), A[i]->get_y() + 1),1,1);
							A[i]->get_vista(E.get_escenario(A[i]->get_x() + 1, A[i]->get_y() + 1),2,1);
						}else if(A[i]->get_x() > 0 && A[i]->get_x() < 49){
							A[i]->get_vista(E.get_escenario(A[i]->get_x() - 1, A[i]->get_y() + 1),0,1);
							A[i]->get_vista(E.get_escenario(A[i]->get_x(), A[i]->get_y() + 1),1,1);
							A[i]->get_vista(E.get_escenario(A[i]->get_x() + 1, A[i]->get_y() + 1),2,1);
						}else if(A[i]->get_x() == 49 ){
							A[i]->get_vista(E.get_escenario(A[i]->get_x() - 1, A[i]->get_y() + 1),0,1);
							A[i]->get_vista(E.get_escenario(A[i]->get_x(), A[i]->get_y() + 1),1,1);
						}
					}
					if(A[i]->get_y() < 49){
						A[i]->get_vista(E.get_escenario(A[i]->get_x(), A[i]->get_y() + 1),1,0);
					}
				}
				/*Fin de introducción de datos*/
				/*Si se encuentra al objetivo, se activa el instinto*/
				if(A[i]->obj_encontrado()){
					A[i]->get_instinto(true);
					if(A[i]->set_tipo() == 'C'){
						if(A[i]->regla_posicion()){
							if(!A[i]->regla_obstaculo(E.get_escenario(A[i]->avance_en_x(),A[i]->avance_en_y()))){
								E.set_escenario(A[i]->get_x(),A[i]->get_y(),E.get_simbolo());
								A[i]->cambiar_posicion();
								E.set_escenario(A[i]->get_x(),A[i]->get_y(),A[i]->get_e());
							}else{
								A[i]->cambiar_sentido();
							}
						}else{
							A[i]->cambiar_sentido();
						}
					}else if(A[i]->set_tipo() == 'H'){
						A[i]->invertir_sentido();
						A[i]->reestablecer_vista();
						if(A[i]->get_s() == "arriba"){
							if(A[i]->get_x() > 1){
								if(A[i]->get_y() == 0 ){
									A[i]->get_vista(E.get_escenario(A[i]->get_x() - 2, A[i]->get_y()),1,1);
									A[i]->get_vista(E.get_escenario(A[i]->get_x() - 2, A[i]->get_y() + 1),1,2);
								}else if(A[i]->get_y() > 1 && A[i]->get_y() < 49){
									A[i]->get_vista(E.get_escenario(A[i]->get_x() - 2, A[i]->get_y() - 1),1,0);
									A[i]->get_vista(E.get_escenario(A[i]->get_x() - 2, A[i]->get_y()),1,1);
									A[i]->get_vista(E.get_escenario(A[i]->get_x() - 2, A[i]->get_y() + 1),1,2);
								}else if(A[i]->get_y() == 49 ){
									A[i]->get_vista(E.get_escenario(A[i]->get_x() - 2, A[i]->get_y() - 1),1,0);
									A[i]->get_vista(E.get_escenario(A[i]->get_x() - 2, A[i]->get_y()),1,1);
								}
							}
							if(A[i]->get_x() > 0){
								A[i]->get_vista(E.get_escenario(A[i]->get_x() - 1, A[i]->get_y()),2,1);
							}
						}else if(A[i]->get_s() == "abajo"){
							if(A[i]->get_x() < 48){
								if(A[i]->get_y() == 0 ){
									A[i]->get_vista(E.get_escenario(A[i]->get_x() + 2, A[i]->get_y()),1,1);
									A[i]->get_vista(E.get_escenario(A[i]->get_x() + 2, A[i]->get_y() + 1),1,2);
								}else if(A[i]->get_y() > 1 && A[i]->get_y() < 49){
									A[i]->get_vista(E.get_escenario(A[i]->get_x() + 2, A[i]->get_y() - 1),1,0);
									A[i]->get_vista(E.get_escenario(A[i]->get_x() + 2, A[i]->get_y()),1,1);
									A[i]->get_vista(E.get_escenario(A[i]->get_x() + 2, A[i]->get_y() + 1),1,2);
								}else if(A[i]->get_y() == 49 ){
									A[i]->get_vista(E.get_escenario(A[i]->get_x() + 2, A[i]->get_y() - 1),1,0);
									A[i]->get_vista(E.get_escenario(A[i]->get_x() + 2, A[i]->get_y()),1,1);
								}
							}
							if(A[i]->get_x() < 49){
								A[i]->get_vista(E.get_escenario(A[i]->get_x() + 1, A[i]->get_y()),0,1);
							}
						}else if(A[i]->get_s() == "izquierda"){
							if(A[i]->get_y() > 1){
								if(A[i]->get_x() == 0){
									A[i]->get_vista(E.get_escenario(A[i]->get_x(), A[i]->get_y() - 1),1,1);
									A[i]->get_vista(E.get_escenario(A[i]->get_x() + 1, A[i]->get_y() - 1),2,1);
								}else if(A[i]->get_x() > 0 && A[i]->get_x() < 49){
									A[i]->get_vista(E.get_escenario(A[i]->get_x() - 1, A[i]->get_y() - 1),0,1);
									A[i]->get_vista(E.get_escenario(A[i]->get_x(), A[i]->get_y() - 1),1,1);
									A[i]->get_vista(E.get_escenario(A[i]->get_x() + 1, A[i]->get_y() - 1),2,1);
								}else if(A[i]->get_x() == 49 ){
									A[i]->get_vista(E.get_escenario(A[i]->get_x() - 1, A[i]->get_y() - 1),0,1);
									A[i]->get_vista(E.get_escenario(A[i]->get_x(), A[i]->get_y() - 1),1,1);
								}
							}
							if(A[i]->get_y() > 0){
								A[i]->get_vista(E.get_escenario(A[i]->get_x(), A[i]->get_y() - 1),1,2);
							}
						}else if(A[i]->get_s() == "derecha"){
							if(A[i]->get_y() < 48){
								if(A[i]->get_x() == 0){
									A[i]->get_vista(E.get_escenario(A[i]->get_x(), A[i]->get_y() + 1),1,1);
									A[i]->get_vista(E.get_escenario(A[i]->get_x() + 1, A[i]->get_y() + 1),2,1);
								}else if(A[i]->get_x() > 0 && A[i]->get_x() < 49){
									A[i]->get_vista(E.get_escenario(A[i]->get_x() - 1, A[i]->get_y() + 1),0,1);
									A[i]->get_vista(E.get_escenario(A[i]->get_x(), A[i]->get_y() + 1),1,1);
									A[i]->get_vista(E.get_escenario(A[i]->get_x() + 1, A[i]->get_y() + 1),2,1);
								}else if(A[i]->get_x() == 49 ){
									A[i]->get_vista(E.get_escenario(A[i]->get_x() - 1, A[i]->get_y() + 1),0,1);
									A[i]->get_vista(E.get_escenario(A[i]->get_x(), A[i]->get_y() + 1),1,1);
								}
							}
							if(A[i]->get_y() < 49){
								A[i]->get_vista(E.get_escenario(A[i]->get_x(), A[i]->get_y() + 1),1,0);
							}
						}
						if(A[i]->obj_encontrado()){
							A[i]->cambiar_sentido();
							A[i]->reestablecer_vista();
							if(A[i]->get_s() == "arriba"){
								if(A[i]->get_x() > 1){
									if(A[i]->get_y() == 0 ){
										A[i]->get_vista(E.get_escenario(A[i]->get_x() - 2, A[i]->get_y()),1,1);
										A[i]->get_vista(E.get_escenario(A[i]->get_x() - 2, A[i]->get_y() + 1),1,2);
									}else if(A[i]->get_y() > 1 && A[i]->get_y() < 49){
										A[i]->get_vista(E.get_escenario(A[i]->get_x() - 2, A[i]->get_y() - 1),1,0);
										A[i]->get_vista(E.get_escenario(A[i]->get_x() - 2, A[i]->get_y()),1,1);
										A[i]->get_vista(E.get_escenario(A[i]->get_x() - 2, A[i]->get_y() + 1),1,2);
									}else if(A[i]->get_y() == 49 ){
										A[i]->get_vista(E.get_escenario(A[i]->get_x() - 2, A[i]->get_y() - 1),1,0);
										A[i]->get_vista(E.get_escenario(A[i]->get_x() - 2, A[i]->get_y()),1,1);
									}
								}
								if(A[i]->get_x() > 0){
									A[i]->get_vista(E.get_escenario(A[i]->get_x() - 1, A[i]->get_y()),2,1);
								}
							}else if(A[i]->get_s() == "abajo"){
								if(A[i]->get_x() < 48){
									if(A[i]->get_y() == 0 ){
										A[i]->get_vista(E.get_escenario(A[i]->get_x() + 2, A[i]->get_y()),1,1);
										A[i]->get_vista(E.get_escenario(A[i]->get_x() + 2, A[i]->get_y() + 1),1,2);
									}else if(A[i]->get_y() > 1 && A[i]->get_y() < 49){
										A[i]->get_vista(E.get_escenario(A[i]->get_x() + 2, A[i]->get_y() - 1),1,0);
										A[i]->get_vista(E.get_escenario(A[i]->get_x() + 2, A[i]->get_y()),1,1);
										A[i]->get_vista(E.get_escenario(A[i]->get_x() + 2, A[i]->get_y() + 1),1,2);
									}else if(A[i]->get_y() == 49 ){
										A[i]->get_vista(E.get_escenario(A[i]->get_x() + 2, A[i]->get_y() - 1),1,0);
										A[i]->get_vista(E.get_escenario(A[i]->get_x() + 2, A[i]->get_y()),1,1);
									}
								}
								if(A[i]->get_x() < 49){
									A[i]->get_vista(E.get_escenario(A[i]->get_x() + 1, A[i]->get_y()),0,1);
								}
							}else if(A[i]->get_s() == "izquierda"){
								if(A[i]->get_y() > 1){
									if(A[i]->get_x() == 0){
										A[i]->get_vista(E.get_escenario(A[i]->get_x(), A[i]->get_y() - 1),1,1);
										A[i]->get_vista(E.get_escenario(A[i]->get_x() + 1, A[i]->get_y() - 1),2,1);
									}else if(A[i]->get_x() > 0 && A[i]->get_x() < 49){
										A[i]->get_vista(E.get_escenario(A[i]->get_x() - 1, A[i]->get_y() - 1),0,1);
										A[i]->get_vista(E.get_escenario(A[i]->get_x(), A[i]->get_y() - 1),1,1);
										A[i]->get_vista(E.get_escenario(A[i]->get_x() + 1, A[i]->get_y() - 1),2,1);
									}else if(A[i]->get_x() == 49 ){
										A[i]->get_vista(E.get_escenario(A[i]->get_x() - 1, A[i]->get_y() - 1),0,1);
										A[i]->get_vista(E.get_escenario(A[i]->get_x(), A[i]->get_y() - 1),1,1);
									}
								}
								if(A[i]->get_y() > 0){
									A[i]->get_vista(E.get_escenario(A[i]->get_x(), A[i]->get_y() - 1),1,2);
								}
							}else if(A[i]->get_s() == "derecha"){
								if(A[i]->get_y() < 48){
									if(A[i]->get_x() == 0){
										A[i]->get_vista(E.get_escenario(A[i]->get_x(), A[i]->get_y() + 1),1,1);
										A[i]->get_vista(E.get_escenario(A[i]->get_x() + 1, A[i]->get_y() + 1),2,1);
									}else if(A[i]->get_x() > 0 && A[i]->get_x() < 49){
										A[i]->get_vista(E.get_escenario(A[i]->get_x() - 1, A[i]->get_y() + 1),0,1);
										A[i]->get_vista(E.get_escenario(A[i]->get_x(), A[i]->get_y() + 1),1,1);
										A[i]->get_vista(E.get_escenario(A[i]->get_x() + 1, A[i]->get_y() + 1),2,1);
									}else if(A[i]->get_x() == 49 ){
										A[i]->get_vista(E.get_escenario(A[i]->get_x() - 1, A[i]->get_y() + 1),0,1);
										A[i]->get_vista(E.get_escenario(A[i]->get_x(), A[i]->get_y() + 1),1,1);
									}
								}
								if(A[i]->get_y() < 49){
									A[i]->get_vista(E.get_escenario(A[i]->get_x(), A[i]->get_y() + 1),1,0);
								}
							}
							if(A[i]->obj_encontrado()){
								A[i]->invertir_sentido();
								A[i]->reestablecer_vista();
								if(A[i]->get_s() == "arriba"){
									if(A[i]->get_x() > 1){
										if(A[i]->get_y() == 0 ){
											A[i]->get_vista(E.get_escenario(A[i]->get_x() - 2, A[i]->get_y()),1,1);
											A[i]->get_vista(E.get_escenario(A[i]->get_x() - 2, A[i]->get_y() + 1),1,2);
										}else if(A[i]->get_y() > 1 && A[i]->get_y() < 49){
											A[i]->get_vista(E.get_escenario(A[i]->get_x() - 2, A[i]->get_y() - 1),1,0);
											A[i]->get_vista(E.get_escenario(A[i]->get_x() - 2, A[i]->get_y()),1,1);
											A[i]->get_vista(E.get_escenario(A[i]->get_x() - 2, A[i]->get_y() + 1),1,2);
										}else if(A[i]->get_y() == 49 ){
											A[i]->get_vista(E.get_escenario(A[i]->get_x() - 2, A[i]->get_y() - 1),1,0);
											A[i]->get_vista(E.get_escenario(A[i]->get_x() - 2, A[i]->get_y()),1,1);
										}
									}
									if(A[i]->get_x() > 0){
										A[i]->get_vista(E.get_escenario(A[i]->get_x() - 1, A[i]->get_y()),2,1);
									}
								}else if(A[i]->get_s() == "abajo"){
									if(A[i]->get_x() < 48){
										if(A[i]->get_y() == 0 ){
											A[i]->get_vista(E.get_escenario(A[i]->get_x() + 2, A[i]->get_y()),1,1);
											A[i]->get_vista(E.get_escenario(A[i]->get_x() + 2, A[i]->get_y() + 1),1,2);
										}else if(A[i]->get_y() > 1 && A[i]->get_y() < 49){
											A[i]->get_vista(E.get_escenario(A[i]->get_x() + 2, A[i]->get_y() - 1),1,0);
											A[i]->get_vista(E.get_escenario(A[i]->get_x() + 2, A[i]->get_y()),1,1);
											A[i]->get_vista(E.get_escenario(A[i]->get_x() + 2, A[i]->get_y() + 1),1,2);
										}else if(A[i]->get_y() == 49 ){
											A[i]->get_vista(E.get_escenario(A[i]->get_x() + 2, A[i]->get_y() - 1),1,0);
											A[i]->get_vista(E.get_escenario(A[i]->get_x() + 2, A[i]->get_y()),1,1);
										}
									}
									if(A[i]->get_x() < 49){
										A[i]->get_vista(E.get_escenario(A[i]->get_x() + 1, A[i]->get_y()),0,1);
									}
								}else if(A[i]->get_s() == "izquierda"){
									if(A[i]->get_y() > 1){
										if(A[i]->get_x() == 0){
											A[i]->get_vista(E.get_escenario(A[i]->get_x(), A[i]->get_y() - 1),1,1);
											A[i]->get_vista(E.get_escenario(A[i]->get_x() + 1, A[i]->get_y() - 1),2,1);
										}else if(A[i]->get_x() > 0 && A[i]->get_x() < 49){
											A[i]->get_vista(E.get_escenario(A[i]->get_x() - 1, A[i]->get_y() - 1),0,1);
											A[i]->get_vista(E.get_escenario(A[i]->get_x(), A[i]->get_y() - 1),1,1);
											A[i]->get_vista(E.get_escenario(A[i]->get_x() + 1, A[i]->get_y() - 1),2,1);
										}else if(A[i]->get_x() == 49 ){
											A[i]->get_vista(E.get_escenario(A[i]->get_x() - 1, A[i]->get_y() - 1),0,1);
											A[i]->get_vista(E.get_escenario(A[i]->get_x(), A[i]->get_y() - 1),1,1);
										}
									}
									if(A[i]->get_y() > 0){
										A[i]->get_vista(E.get_escenario(A[i]->get_x(), A[i]->get_y() - 1),1,2);
									}
								}else if(A[i]->get_s() == "derecha"){
									if(A[i]->get_y() < 48){
										if(A[i]->get_x() == 0){
											A[i]->get_vista(E.get_escenario(A[i]->get_x(), A[i]->get_y() + 1),1,1);
											A[i]->get_vista(E.get_escenario(A[i]->get_x() + 1, A[i]->get_y() + 1),2,1);
										}else if(A[i]->get_x() > 0 && A[i]->get_x() < 49){
											A[i]->get_vista(E.get_escenario(A[i]->get_x() - 1, A[i]->get_y() + 1),0,1);
											A[i]->get_vista(E.get_escenario(A[i]->get_x(), A[i]->get_y() + 1),1,1);
											A[i]->get_vista(E.get_escenario(A[i]->get_x() + 1, A[i]->get_y() + 1),2,1);
										}else if(A[i]->get_x() == 49 ){
											A[i]->get_vista(E.get_escenario(A[i]->get_x() - 1, A[i]->get_y() + 1),0,1);
											A[i]->get_vista(E.get_escenario(A[i]->get_x(), A[i]->get_y() + 1),1,1);
										}
									}
									if(A[i]->get_y() < 49){
										A[i]->get_vista(E.get_escenario(A[i]->get_x(), A[i]->get_y() + 1),1,0);
									}
								}
							}else{//muerte
								if(A[i]->regla_posicion()){
									if(!A[i]->regla_obstaculo(E.get_escenario(A[i]->avance_en_x(),A[i]->avance_en_y()))){
										E.set_escenario(A[i]->get_x(),A[i]->get_y(),E.get_simbolo());
										A[i]->cambiar_posicion();
										E.set_escenario(A[i]->get_x(),A[i]->get_y(),A[i]->get_e());
									}else{
										A[i]->cambiar_sentido();
									}
								}else{
									A[i]->cambiar_sentido();
								}
							}
						}else{//muerte
							if(A[i]->regla_posicion()){
								if(!A[i]->regla_obstaculo(E.get_escenario(A[i]->avance_en_x(),A[i]->avance_en_y()))){
									E.set_escenario(A[i]->get_x(),A[i]->get_y(),E.get_simbolo());
									A[i]->cambiar_posicion();
									E.set_escenario(A[i]->get_x(),A[i]->get_y(),A[i]->get_e());
								}else{
									A[i]->cambiar_sentido();
								}
							}else{
								A[i]->cambiar_sentido();
							}
						}
					}
				}else{
					A[i]->get_instinto(false);
					if(A[i]->regla_posicion()){
						if(!A[i]->regla_obstaculo(E.get_escenario(A[i]->avance_en_x(),A[i]->avance_en_y()))){
							E.set_escenario(A[i]->get_x(),A[i]->get_y(),E.get_simbolo());
							A[i]->cambiar_posicion();
							E.set_escenario(A[i]->get_x(),A[i]->get_y(),A[i]->get_e());
						}else{
							A[i]->cambiar_sentido();
						}
					}else{
						A[i]->cambiar_sentido();
					}
					
				}
			}
			A[i]->reestablecer_vista();
		}
		system("cls");
		E.imprimir_escenario();
		Sleep(100);
		//system("pause");
		if(tiempo>10){
			tiempo=0;
			
			S.string_random();
			for(i = 0; i<8; i++){
				if(!A[i]->set_instinto()){
					A[i]->set_s(S.set_sentido());
				}
			}
			S.limpiar_memoria_sen();
			
		}else{tiempo++;}
		
		if(kbhit()){
			tecla = getch();
			if(tecla == 'p'){getch();}//pausar la ejecución del programa
			if(tecla == 'q'){getch(); exit(1);}//terminar la ejecución del programa
		}
	}
	return 0;
}
