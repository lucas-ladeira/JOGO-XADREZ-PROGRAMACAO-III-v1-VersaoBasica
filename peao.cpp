#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;
#include "tabuleiro.h"
#include "peao.h"

void Peao::inicializa_posicao(int pos_i, int pos_j)
{
   pos_atual_i = pos_i;
   pos_atual_j = pos_j;
   return;
}

bool Peao::verifica_jogada( int pos_final_i, int pos_final_j, Tabuleiro *tabuleiro)
{

   char cor = tabuleiro->getMatriz(pos_atual_i, pos_atual_j).back();

   //PEAO CAPTURA
   if( tabuleiro->getMatriz(pos_final_i, pos_final_j)!="0" && tabuleiro->getMatriz(pos_final_i, pos_final_j).back()!=cor && abs(pos_final_i-pos_atual_i)==1 && abs(pos_final_j-pos_atual_j)==1 )
   {
   	  if( abs(pos_final_i-pos_atual_i) == 2 ) duas_vezes = true;
   	  else duas_vezes = false;

      tabuleiro->setMatriz(pos_final_i, pos_final_j, tabuleiro->getMatriz(pos_atual_i, pos_atual_j));
      tabuleiro->setMatriz(pos_atual_i, pos_atual_j, "0");
      inicializa_posicao(pos_final_i, pos_final_j);
      nJogadas++;
      return true;
   }

   //PECAS PRETAS
   if(cor=='P')
   {
      if( pos_final_i==pos_atual_i+1 && pos_atual_j==pos_final_j )
      {
         if(peca_no_caminho(pos_atual_i,pos_atual_j, pos_final_i, pos_final_j, tabuleiro) == 0)
         {

         	if( abs(pos_final_i-pos_atual_i) == 2 ) duas_vezes = true;
   	  		else duas_vezes = false;

            tabuleiro->setMatriz(pos_final_i, pos_final_j, tabuleiro->getMatriz(pos_atual_i, pos_atual_j));
            tabuleiro->setMatriz(pos_atual_i, pos_atual_j, "0");
            inicializa_posicao(pos_final_i, pos_final_j);
            nJogadas++;
            return true;
         }
      }

      else if( pos_final_i==pos_atual_i+2 && pos_atual_j==pos_final_j && nJogadas==0)
      {
         if(peca_no_caminho(pos_atual_i,pos_atual_j, pos_final_i, pos_final_j, tabuleiro) == 0)
         {
         	if( abs(pos_final_i-pos_atual_i) == 2 ) duas_vezes = true;
   	  		else duas_vezes = false;

            tabuleiro->setMatriz(pos_final_i, pos_final_j, tabuleiro->getMatriz(pos_atual_i, pos_atual_j));
            tabuleiro->setMatriz(pos_atual_i, pos_atual_j, "0");
            inicializa_posicao(pos_final_i, pos_final_j);
            nJogadas++;
            return true;
         }
      }
      return false;
   }
   //PECAS BRANCAS
   else if(cor == 'B')
   {
      if( pos_final_i==pos_atual_i-1 && pos_atual_j==pos_final_j )
      {
         if(peca_no_caminho(pos_atual_i,pos_atual_j, pos_final_i, pos_final_j, tabuleiro) == 0)
         {
         	if( abs(pos_final_i-pos_atual_i) == 2 ) duas_vezes = true;
   	  		else duas_vezes = false;

            tabuleiro->setMatriz(pos_final_i, pos_final_j, tabuleiro->getMatriz(pos_atual_i, pos_atual_j));
            tabuleiro->setMatriz(pos_atual_i, pos_atual_j, "0");
            inicializa_posicao(pos_final_i, pos_final_j);
            nJogadas++;
            return true;
         }
      }

      else if( pos_final_i==pos_atual_i-2 && pos_atual_j==pos_final_j && nJogadas==0)
      {
         if(peca_no_caminho(pos_atual_i,pos_atual_j, pos_final_i, pos_final_j, tabuleiro) == 0)
         {
         	if( abs(pos_final_i-pos_atual_i) == 2 ) duas_vezes = true;
   	  		else duas_vezes = false;
   	  		
            tabuleiro->setMatriz(pos_final_i, pos_final_j, tabuleiro->getMatriz(pos_atual_i, pos_atual_j));
            tabuleiro->setMatriz(pos_atual_i, pos_atual_j, "0");
            inicializa_posicao(pos_final_i, pos_final_j);
            nJogadas++;
            return true;
         }
      }
      return false;
   }
   return false;
}

int Peao::getNJogadas(void)
{
   return nJogadas;
}

int Peao::posicao_inicial_i(void)
{
   return pos_atual_i;
}

int Peao::posicao_inicial_j(void)
{
   return pos_atual_j;
}

int Peao::peca_no_caminho(int pos_atual_i, int pos_atual_j, int pos_final_i, int pos_final_j, Tabuleiro *tabuleiro)
{
   int x = pos_atual_j;
   int y = pos_atual_i;

   int valor;
   if(pos_final_i > y) valor = 1;
   else valor = -1;

   if(tabuleiro->getMatriz(pos_final_i, pos_final_j)!="0" && pos_atual_j==pos_final_j)
   {
      return 1;
   }

   y += valor;
   while(y != pos_final_i)
   {

      if(tabuleiro->getMatriz(y, x)!= "0")
         return 1;

      y += valor;
   }
   return 0;
}
