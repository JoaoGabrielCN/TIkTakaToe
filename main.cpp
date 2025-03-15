/*
 * main.cpp
 *
 *  Created on: 14 de mar. de 2025
 *      Author: Aldo
 */

#include <iostream>
#include "Tabuleiro.h"

using namespace std;

int main(int argc, char **argv) {
	char letra = 'O';
	Tabuleiro tab;

	while (!tab.gameOver(letra)) {
		tab.exibe();
		tab.atualiza(letra);

		letra = (letra == 'O') ? 'X' : 'O';

	}

	return 0;
}

