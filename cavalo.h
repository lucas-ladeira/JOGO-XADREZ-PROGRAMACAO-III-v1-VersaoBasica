#ifndef PECAS_H
#define PECAS_H

#include <iostream>
#include <string>
#include <cmath>

class Tabuleiro;

class Cavalo
{
public:
	/*	INICIALIZA_POSICAO
	 *		Recebe como parametros dois inteiros que representam uma posicao i e j (respectivamente) no tabuleiro.
	 *		Armazena os parametros recebidos nos respectivos atributos destinados para eles
	 */
	void inicializa_posicao(int pos_i, int pos_j);

	/*	VERIFICA_JOGADA
	 *		Recebe como parametros dois inteiros que representam uma posicao i e j (respectivamente) no tabuleiro e, um ponteiro pro tabuleiro.
	 *		Retorna um valor logico (true ou false) informando se a jogada solicitada eh valida.
	 */
	bool verifica_jogada( int pos_final_i, int pos_final_j, Tabuleiro *tabuleiro);
private:
	int pos_atual_i;	//posicao atual em i
	int pos_atual_j;	//posicao atual em j
};

#endif
