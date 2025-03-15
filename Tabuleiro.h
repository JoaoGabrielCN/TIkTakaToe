/*
 * Tabuleiro.h
 *
 *  Created on: 14 de mar. de 2025
 *      Author: Aldo
 */
#include<iostream>
using namespace std;

#ifndef TABULEIRO_H_
#define TABULEIRO_H_

class Tabuleiro {
private:
	char tab[3][3];
public:
	Tabuleiro();
	void exibe();
	void atualiza(char letra);
	bool verifica();
	bool verificaVelha();
};

#endif /* TABULEIRO_H_ */
