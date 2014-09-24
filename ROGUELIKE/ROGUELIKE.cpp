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
			int i = 0;
			string buffer[255];
			ifstream textfile;
			textfile.open("map.txt");
			if (textfile.fail()){
				cout << "error al obrir";
			}
			while (!textfile.eof()){
				textfile >> buffer[i];
				//cout << buffer[i] << endl;
				i++;
			}
			textfile.close();
		   
			int x = 0;
			int y = 0;
			int TempNumOne = buffer[y].size();       //AquestTroçDeCodiNoEsMeu    
			char Filename[255][255];                 //
			for (int x = 0; x <= TempNumOne; x++)    //
			{                                        //
			Filename[x][y] = buffer[y][x];              //APartirDAquiElCodiJaEsMeu
			}
			cout << Filename[0][1]<<endl;
		}
		if (option == 2){
			int i;
			cout << "Introdueix el numero de files: ";
			cin >> i;
			ofstream textfile;
			textfile.open("map.txt");
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