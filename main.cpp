/*
 * main.cpp
 *
 *  Created on: 14 de mar. de 2025
 *      Author: Aldo
 */

#include <iostream>
#include <cstdlib>
#include "Tabuleiro.h"

using namespace std;


int main(int argc, char **argv) {
	char letra = 'O';

	Tabuleiro tab;



	while (!tab.verifica() && !tab.verificaVelha()) {
		tab.exibe();
		tab.atualiza(letra);

		letra = (letra == 'O') ? 'X' : 'O';


	}

	letra = (letra == 'O') ? 'X' : 'O';

	if (tab.verifica()) {
		tab.exibe();
		cout << "O jogador " << letra << " ganhou!" << endl;
	}else{
		cout<<"Deu velha!"<<endl;
	}
}

