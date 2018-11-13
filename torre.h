#ifndef TORRE_H
#define TORRE_H

#include <iostream>
#include <string>

class Tabuleiro;

class Torre
{

public:
	Torre (): nJogadas(0){};
	bool verificando_xeque_(int n, int m);//na pos (0,2)(0,4)(0,6) que da pra ver se tem rico p rei	
	void inicializa_posicao(int pos_i, int pos_j);
	
	bool verifica_jogada( int pos_final_i, int pos_final_j, Tabuleiro *tabuleiro);	
	
	int getNjogadas ()
	{
		return nJogadas;
	}

	void setNjogadas()
	{
		nJogadas++;
	}

	int posicao_inicial_i()
	{
		return pos_atual_i;
	}

	int posicao_inicial_j()
	{
		return pos_atual_j;
	}

private:
	
	int peca_no_caminho(int pos_atual_i, int pos_atual_j, int pos_final_i, int pos_final_j, Tabuleiro *tabuleiro);	
	int nJogadas;
	int pos_atual_i;
	int pos_atual_j; //posicao atual em i e j
	
};

#endif
