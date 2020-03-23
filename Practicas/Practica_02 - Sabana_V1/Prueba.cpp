#include<iostream>
#include<windows.h>
#include<conio.h>
#include<stdio.h>
using namespace std;

int main(int argc, char *argv[]) {
	int a = 1;
	char tecla;
	while(true){
		cout<<a<<endl;
		a++;
//		if(kbhit()){
//			tecla = getch();
//			if(tecla=='q'){a=0;}
//			if(tecla=='p'){getch();}
//		}
		if(kbhit()){
			tecla = getch();
			switch(tecla){
			case 'q':
				a=0;
				break;
			case 'p':
				getch();
				break;
			}
		}
		Sleep(100);
	}
return 0;
}
