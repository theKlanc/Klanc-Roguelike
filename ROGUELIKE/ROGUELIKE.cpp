﻿﻿#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <windows.h>

using namespace std;

int main()
{
	int n = 0;
	cout << "Launcher by..." << endl;
	cout << "      _             _    ____   ___  _ " << endl;
	cout << "  ___| | __ _ _ __ | | _|___ \\ / _ \\/ |" << endl;
	cout << " / __| |/ _` | '_ \\| |/ / __) | | | | |" << endl;
	cout << "| (__| | (_| | | | |   < / __/| |_| | |" << endl;
	cout << " \\___|_|\\__,_|_| |_|_|\\_\\_____|\\___/|_|" << endl;
	while (1)
	{
		int option;
		cout << "Escull una opcio" << endl << "1) Programa1" << endl << "2) Crear mapa" << endl << "3) Opcions" << endl << "4) Exit" << endl;
		cin >> option;
		if (option == 1){
			/*d aqui fins al proxim comment es la carrega de mapa*/
			int i = 0, mapheight, maplength;
			string temp1[255];
			ifstream textfile;
			textfile.open("map.txt");
			if (textfile.fail()){
				cerr << "error al obrir";
			}
			textfile >> mapheight;
			textfile >> maplength;
			cout << mapheight << endl << maplength << endl;
			mapheight = mapheight - 1; //NOapanyo
			maplength = maplength - 1; //otro apanyo, tot i k potser al final no son apanyosEDIT:nohoson
			while (!textfile.eof()){
				textfile >> temp1[i];
				i++;
			}
			textfile.close();
			char map[255][255];                          //
			for (int y = 0; y <= mapheight; y++)      //EhtoEhMio el y=1 hauria d esser 0
			{
				for (int x = 0; x <= maplength; x++)  //
				{                                        //
					map[x][y] = temp1[y][x];            //APartirDAquiElCodiJaEsMeu
				}
			}
			/*for (int i = 0; i <= mapheight; i++){
			for (int j = 0; j <= maplength; j++){
			cout << map[j][i];
			}
			cout << endl;
			}*/




			/*a partir d aqui comensa el joc...*/


			int posx = 1, posy = 1;
			char screenbuffer[255][255];
			while (1){
				/*int tecla = _getch();
				switch (tecla){
				case 22475 : {
				posx = posx - 1;
				}
				case 22472 : {
				posy = posy - 1;
				}
				case 22480 : {
				posy = posy + 1;
				}
				case 22477 : {
				posx = posx + 1;
				}
				default:{}
				}*/
				if (GetAsyncKeyState(VK_LEFT)){
					posx = posx - 1;
					cout << "trolasso";
				}
				if (GetAsyncKeyState(VK_UP)){
					posy = posy - 1;
				}
				if (GetAsyncKeyState(VK_DOWN)){
					posy = posy + 1;
				}
				if (GetAsyncKeyState(VK_RIGHT)){
					posx = posx + 1;
				}




				for (int i = 0; i <= mapheight; i++){
					for (int j = 0; j <= maplength; j++){
						screenbuffer[j][i] = map[j][i];
					}
				}
				cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
				screenbuffer[posx][posy] = 'O';
				for (int i = 0; i <= mapheight; i++){
					for (int j = 0; j <= maplength; j++){
						cout << screenbuffer[j][i];
					}
					cout << endl;
				}
				//cout << "X=" << posx << " Y=" << posy << endl << n;
				//n++;
				Sleep(160);
			}






		}
		if (option == 2){
			int i, j;
			cout << "Introdueix el numero de files: ";
			cin >> i;
			cout << "Introdueix el numero de columnes: ";
			cin >> j;
			ofstream textfile;
			textfile.open("map.txt");
			textfile << i << endl << j << endl;

			if (textfile.fail()){
				cerr << "error al obrir";
			}

			while (i != 0){
				string temp;
				cin >> temp;
				textfile << temp;
				textfile << endl;
				i--;
			}
			textfile.close();

		}
		if (option == 3){
			while (1){
				if (GetAsyncKeyState(VK_LEFT)){
					cout << "trolasso";
				}
				if (GetAsyncKeyState(VK_UP)){
					cout << "trolasso";
				}
				if (GetAsyncKeyState(VK_DOWN)){
					cout << "trolasso";
				}
				if (GetAsyncKeyState(VK_RIGHT)){
					cout << "trolasso";
				}
			}
		}
		if (option == 4){
			return 0;
		}
	}
}