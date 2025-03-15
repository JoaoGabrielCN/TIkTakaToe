/*
 * Tabuleiro.cpp
 *
 *  Created on: 14 de mar. de 2025
 *      Author: Aldo
 */

#include "Tabuleiro.h"

Tabuleiro::Tabuleiro() {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			tab[i][j] = '-';
		}
	}
}

void Tabuleiro::exibe() {
	cout << endl;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cout << tab[i][j];
			if (j != 2)
				cout << "|";
		}
		cout << endl;
	}
}

void Tabuleiro::atualiza(char letra) {
	int x, y;
	cout << "Insira as posições que voce deseja jogar" << endl;
	cin >> x;
	cin >> y;

	if (tab[x][y] == 'O' || tab[x][y] == 'X' || x > 2 || y > 2) {
		cout << "Posição inválida!" << endl;
	} else {
		tab[x][y] = letra;
	}
}

bool Tabuleiro::verifica() {
	int cont = 0;
	for (int i = 0; i < 3; ++i) {
		cont = 0;

		char ref = tab[i][0];
		for (int j = 0; j < 3; ++j) {
			if (j != 0 && tab[i][j] == ref && ref != '-') {
				cont++;
				if (cont == 2) {

					return true;
				}
			}
		}
	}

	cont = 0;

	for (int i = 0; i < 3; ++i) {
		cont = 0;

		char ref = tab[0][i];
		for (int j = 0; j < 3; ++j) {
			if (j != 0 && tab[j][i] == ref && ref != '-') {
				cont++;
				if (cont == 2) {

					return true;
				}
			}
		}
	}

	cont = 0;

	for (int i = 0; i < 3; ++i) {

		char ref = tab[0][0];
		for (int j = 0; j < 3; ++j) {
			if (i != 0 && tab[i][j] == ref && ref != '-' && i == j) {
				cont++;
				if (cont == 2) {
					return true;
				}
			}
		}

	}
	cont = 0;

	for (int i = 0; i < 3; ++i) {

		char ref = tab[0][2];
		for (int j = 0; j < 3; ++j) {
			if (i != 0 && tab[i][j] == ref && ref != '-' && i + j == 2) {
				cont++;
				if (cont == 2) {
					return true;
				}
			}
		}

	}
	return false;

}

bool Tabuleiro::verificaVelha() {
	int cont = 0;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (tab[i][j] == 'X' || tab[i][j] == 'O')
				cont++;
		}
	}

	if (cont == 9) {
		return true;
	}

	return false;
}

bool Tabuleiro::gameOver(char letra) {
	letra = (letra == 'O') ? 'X' : 'O';

	if (verifica() || verificaVelha()) {
		if (verifica()) {
			exibe();
			cout << "O jogador " << letra << " ganhou!" << endl;
			return true;
		} else {
			cout << "Deu velha!" << endl;
			return true;
		}
	}
	return false;

}
