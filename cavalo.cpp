#include <iostream>
#include <string>
using namespace std;
#include "tabuleiro.h"
#include "cavalo.h"

void Cavalo::inicializa_posicao(int pos_i, int pos_j)
{
   pos_atual_i = pos_i;
   pos_atual_j = pos_j;
   return;
}

bool Cavalo::verifica_jogada( int pos_final_i, int pos_final_j, Tabuleiro *tabuleiro)
{
   if( (abs(pos_final_i-pos_atual_i)==2 && abs(pos_final_j-pos_atual_j)==1) || (abs(pos_final_i-pos_atual_i)==1 && abs(pos_final_j-pos_atual_j)==2) )
   {
      tabuleiro->setMatriz(pos_final_i, pos_final_j, tabuleiro->getMatriz(pos_atual_i, pos_atual_j));
		tabuleiro->setMatriz(pos_atual_i, pos_atual_j, "0");
		inicializa_posicao(pos_final_i, pos_final_j);
      return true;
   }
   return false;
}
