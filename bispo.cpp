#include <iostream>
#include <string>

#include "tabuleiro.h"
#include "bispo.h"

void Bispo::inicializa_posicao(int pos_i, int pos_j)
{
	pos_atual_i = pos_i;
	pos_atual_j = pos_j;
	return;
}

//funcao responsavel por verificar se a jogada eh valida
bool Bispo::verifica_jogada( int pos_final_i, int pos_final_j, Tabuleiro *tabuleiro)
{
	//verificando se caminho final eh valido
	if( (pos_final_j - pos_final_i) == (pos_atual_j - pos_atual_i) ||  (pos_final_j + pos_final_i) == (pos_atual_j + pos_atual_i) ) // caso nao seja invalida a posicao
	{
			//conferindo se tem alguma peca para capturar
			if(peca_no_caminho(pos_atual_i,pos_atual_j, pos_final_i, pos_final_j, tabuleiro) == 0)
			{
				tabuleiro->setMatriz(pos_final_i, pos_final_j, tabuleiro->getMatriz(pos_atual_i, pos_atual_j));
				tabuleiro->setMatriz(pos_atual_i, pos_atual_j, "0");
				inicializa_posicao(pos_final_i, pos_final_j);
				return true;
		  	}
			return false;
  	}
 	else return false;
	}

int Bispo::peca_no_caminho(int pos_atual_i, int pos_atual_j, int pos_final_i, int pos_final_j, Tabuleiro *tabuleiro)
{
	if(pos_atual_i == pos_final_i && pos_atual_j == pos_final_j) return 1;

	if(pos_atual_i > pos_final_i && pos_atual_j > pos_final_j) //caso 1 = andando para cima  a esquerda
	{
		int i = pos_atual_i-1;
		int j = pos_atual_j-1;

		while(i > pos_final_i && j > pos_final_j)
		{			
			if(tabuleiro->getMatriz(i, j) != "0")
			{
		    	return 1;//caso return 1 significa que tem peca
			}
			i--;
			j--;
		}
		return 0;//se retornar zero que dizer que nao tem peca no caminho
	}

	if(pos_atual_i > pos_final_i && pos_atual_j < pos_final_j)//caso 2 = andando para cima  a direita
	{
		int i = pos_atual_i-1;
		int j = pos_atual_j+1;

		while(i > pos_final_i && j < pos_final_j)
		{			
			if(tabuleiro->getMatriz(i, j)!= "0")
			{
		    	return 1;//caso return 1 significa que tem peca
			}
			i--;
			j++;
		}
		return 0;//se retornar zero que dizer que nao tem peca no caminho
	}

	if(pos_atual_i < pos_final_i && pos_atual_j < pos_final_j)//caso 3  = andando para baixo  a esquerda
	{
		int i = pos_atual_i+1;
		int j = pos_atual_j+1;

		while(i < pos_final_i && j < pos_final_j)
		{			
			if(tabuleiro->getMatriz(i, j)!= "0")
			{
	    		return 1;//caso return 1 significa que tem peca
			}
			i++;
			j++;
		}
		return 0;//se retornar zero que dizer que nao tem peca no caminho
	}

	if(pos_atual_i < pos_final_i && pos_atual_j > pos_final_j)//caso 4 = andando para baixo  a direita
	{
		int i = pos_atual_i+1;
		int j = pos_atual_j-1;

		while(i < pos_final_i && j > pos_final_j)
		{			
			if(tabuleiro->getMatriz(i, j)!= "0")
			{
				return 1;//caso return 1 significa que tem peca
			}
			i++;
			j--;
		}
		return 0;//se retornar zero que dizer que nao tem peca no caminho
	}
	
	return 0;	
}
