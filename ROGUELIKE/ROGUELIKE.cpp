#include <fstream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

void clearscreen()//codirobat per evitar flickers
{
	HANDLE hOut;
	COORD Position;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

int main()
{
	int n = 0;
	cout << "Launcher by.." << endl;
	cout << "      _             _    ____   ___  _ " << endl;
	cout << "  ___| | __ _ _ __ | | _|___ \\ / _ \\/ |" << endl;
	cout << " / __| |/ _` | '_ \\| |/ / __) | | | | |" << endl;
	cout << "| (__| | (_| | | | |   < / __/| |_| | |" << endl;
	cout << " \\___|_|\\__,_|_| |_|_|\\_\\_____|\\___/|_|" << endl;
	while (1)
	{
		int option;
		cout << "Escull una opcio" << endl << "1) Començar" << endl << "2) Crear mapa" << endl << "3) TESTAREA" << endl << "4) Exit" << endl;
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
				for (int i = 0; i <= mapheight+1; i++){
					for (int j = 0; j <= maplength+1; j++){
						if (map[j][i] == 'X'){
							map[j][i] = ' ';
						}
					}
				}
				clearscreen();
				screenbuffer[posx][posy] = 'X';
				for (int i = 0; i <= mapheight; i++){
					for (int j = 0; j <= maplength; j++){
						cout << screenbuffer[j][i];
					}
					cout << endl;
				}
				
				//ComençaLaDeteccioDeTecles
				if (GetAsyncKeyState(VK_LEFT)){
					if (map[posx - 1][posy] == ' '){
						posx = posx - 1;
					}
				}
				if (GetAsyncKeyState(VK_UP)){
					if (map[posx][posy - 1] == ' '){
						posy = posy - 1;
					}
				}
				if (GetAsyncKeyState(VK_DOWN)){
					if (map[posx][posy + 1] == ' '){
						posy = posy + 1;
					}
				}
				if (GetAsyncKeyState(VK_RIGHT)){
					if (map[posx + 1][posy] == ' '){
						posx = posx + 1;
					}
				}
				if (GetAsyncKeyState('Q')){
					return 0;
				}
				if (GetAsyncKeyState('A')){
					switch (map[posx - 1][posy]){
					case ' ':
						map[posx - 1][posy] = '1';
						break;

					case '1':
						map[posx - 1][posy] = ' ';
						break;
					}
				}
				if (GetAsyncKeyState('W')){
					switch (map[posx][posy-1]){
					case ' ':
						map[posx][posy-1] = '1';
						break;

					case '1':
						map[posx][posy-1] = ' ';
						break;
					}
				}
				if (GetAsyncKeyState('S')){
					switch (map[posx][posy+1]){
					case ' ':
						map[posx][posy+1] = '1';
						break;

					case '1':
						map[posx][posy+1] = ' ';
						break;
					}
				}
				if (GetAsyncKeyState('D')){
					switch (map[posx + 1][posy]){
					case ' ':
						map[posx + 1][posy] = '1';
						break;

					case '1':
						map[posx + 1][posy] = ' ';
						break;
					}
				}
				//AcabaLaDeteccioDeLletres

				//PreparaElProximFrame
				for (int i = 0; i <= mapheight; i++){
					for (int j = 0; j <= maplength; j++){
						screenbuffer[j][i] = map[j][i];
					}
				}
				cout << "X=" << posx << " Y=" << posy << endl << n;
				n++;
				Sleep(50);
				
				//GuardaMapa
				
				for (int i = 0; i <= mapheight+1; i++){
					for (int j = 0; j <= maplength+1; j++){
						if (map[j][i] == ' '){
							map[j][i] = 'X';
						}
					}
				}

				ofstream textfilesave;
				textfilesave.open("map.txt");
				textfilesave << mapheight+1 << endl << maplength+1 << endl;
				for (int i = 0; i <= mapheight; i++){
					for (int j = 0; j <= maplength; j++){
						textfilesave << map[j][i];
					}
					textfilesave << endl;
				}
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
			if (textfile.fail()){
				cerr << "error al obrir";
			}
			textfile << i << endl << j << endl;

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
			//TESTAREA
		}
		if (option == 4){
			return 0;
		}
	}
}