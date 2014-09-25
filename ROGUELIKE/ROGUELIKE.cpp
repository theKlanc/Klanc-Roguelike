#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
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
			int i = 0, bufferheight,bufferlength;
			string buffer[255];
			ifstream textfile;
			textfile.open("map.txt");
			if (textfile.fail()){
				cerr << "error al obrir";
			}
			textfile >> bufferheight;
			textfile >> bufferlength;
			cout << bufferheight << endl << bufferlength << endl;
			bufferheight = bufferheight - 1; //apanyo
			while (!textfile.eof()){
				textfile >> buffer[i];
				i++;
			}
			textfile.close();
			char map[255][255];                     //
			for (int y = 1; y <= bufferheight; y++)      //EhtoEhMio el y=1 hauria d esser 0
			{
				for (int x = 1; x <= bufferlength; x++)  //
				{                                        //
					map[x][y] = buffer[y][x];       //APartirDAquiElCodiJaEsMeu
				}
			}
			cout << map[0][0];
		}
		if (option == 2){
			int i, j;
			cout << "Introdueix el numero de files: ";
			cin >> i;
			cout << "Introdueix el numero de columnes: ";
			cin >> j;
			ofstream textfile;
			textfile.open("map.txt");
			textfile << i<<endl<<j<<endl;
			
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
			//generatemapOPCIONS;
		}
		if (option == 4){
			return 0;
		}
	}
}