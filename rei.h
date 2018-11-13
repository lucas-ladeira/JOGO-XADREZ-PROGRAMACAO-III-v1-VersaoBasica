#ifndef REI_H
#define REI_H

#include <iostream>
#include <string>

class Tabuleiro;
class Bispo;
class Rei
{
public:
	Rei (): nJogadas(0){};
	void inicializa_posicao(int pos_i, int pos_j);	

	bool verifica_jogada( int pos_final_i, int pos_final_j, Tabuleiro *tabuleiro);
	int getNjogadas (){
		return nJogadas;
	}
	void setNjogadas (){
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

	//int peca_no_caminho_torre(int pos_atual_i, int pos_atual_j, int pos_final_i, int pos_final_j, Tabuleiro *tabuleiro);
    //int peca_no_caminho_bispo(int pos_atual_i, int pos_atual_j, int pos_final_i, int pos_final_j, Tabuleiro *tabuleiro);  	
	int nJogadas ;
	int pos_atual_i;
	int pos_atual_j; //posicao atual em i e j
};

#endif
