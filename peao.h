#ifndef PEAO_H
#define PEAO_H

#include <iostream>
#include <string>

class Tabuleiro;

class Peao
{
public:
	void inicializa_posicao(int pos_i, int pos_j);
	bool verifica_jogada( int pos_final_i, int pos_final_j, Tabuleiro *tabuleiro);
	int getNJogadas(void);
	int posicao_inicial_i(void);
	int posicao_inicial_j(void);
	void set_duas_vezes_true() { duas_vezes = true; }
	void set_duas_vezes_false() { duas_vezes = false; }
	bool get_duas_vezes() { return duas_vezes; }
	int get_linha_atual() { return pos_atual_i; }
	int get_coluna_atual() { return pos_atual_j; }
	void incremento_nJogadas() { nJogadas++; }

private:
	int peca_no_caminho(int pos_atual_i, int pos_atual_j, int pos_final_i, int pos_final_j, Tabuleiro *tabuleiro);
	int nJogadas = 0;
	int pos_atual_i;
	int pos_atual_j; //posicao atual em i e j
	bool duas_vezes = false; //diz se andou duas casas
};

#endif
