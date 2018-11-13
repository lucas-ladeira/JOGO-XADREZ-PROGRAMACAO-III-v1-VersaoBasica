#include "tabuleiro.h"
#include "rei.h"
#include "torre.h"

class Torre;
void Rei::inicializa_posicao(int pos_i, int pos_j)
{
	pos_atual_i = pos_i;
	pos_atual_j = pos_j;
	return;
}

bool Rei::verifica_jogada( int pos_final_i, int pos_final_j, Tabuleiro *tabuleiro)
{
	

	if (tabuleiro->getMatriz(pos_final_i, pos_final_j) == "RP" || tabuleiro->getMatriz(pos_final_i, pos_final_j) == "RB" ) {return false;};//Condicao para o rei nao cpturar o outro rei
	

	if ((pos_atual_i -1 == pos_final_i && pos_atual_j == pos_final_j )|| ( pos_atual_i -1 == pos_final_i && pos_atual_j+1 == pos_final_j )|| (pos_atual_i -1 == pos_final_i && pos_atual_j-1 == pos_final_j)){
			tabuleiro->setMatriz(pos_final_i, pos_final_j, tabuleiro->getMatriz(pos_atual_i, pos_atual_j));
			tabuleiro->setMatriz(pos_atual_i, pos_atual_j, "0");
			inicializa_posicao(pos_final_i, pos_final_j);
			nJogadas ++;
			return true;
	}

	if ((pos_atual_i +1 == pos_final_i && pos_atual_j+1 == pos_final_j ) || (pos_atual_i +1 == pos_final_i && pos_atual_j == pos_final_j) || (pos_atual_i +1 == pos_final_i && pos_atual_j-1 == pos_final_j)){
			tabuleiro->setMatriz(pos_final_i, pos_final_j, tabuleiro->getMatriz(pos_atual_i, pos_atual_j));
			tabuleiro->setMatriz(pos_atual_i, pos_atual_j, "0");
			inicializa_posicao(pos_final_i, pos_final_j);
			nJogadas ++;
			return true;
	}

	if ((pos_atual_i == pos_final_i && pos_atual_j+1 == pos_final_j ) || (pos_atual_i == pos_final_i && pos_atual_j-1 == pos_final_j) ){
			tabuleiro->setMatriz(pos_final_i, pos_final_j, tabuleiro->getMatriz(pos_atual_i, pos_atual_j));
			tabuleiro->setMatriz(pos_atual_i, pos_atual_j, "0");
			inicializa_posicao(pos_final_i, pos_final_j);
			nJogadas ++;
	    	return true;
	}
	
	return false;
}



  	
