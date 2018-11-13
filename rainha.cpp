#include <iostream>
#include <string>

#include "tabuleiro.h"
#include "rainha.h"

void Rainha::inicializa_posicao(int pos_i, int pos_j)
{
	pos_atual_i = pos_i;
	pos_atual_j = pos_j;
	return;
}

bool Rainha::verifica_jogada( int pos_final_i, int pos_final_j, Tabuleiro *tabuleiro)
{
	//verificando se caminho final eh valido para caminho tipo da torre
	if( pos_atual_i == pos_final_i || pos_atual_j == pos_final_j ) // caso nao seja invalida a posicao
	{
		//conferindo se tem alguma peca para capturar
		if(peca_no_caminho_torre(pos_atual_i,pos_atual_j, pos_final_i, pos_final_j, tabuleiro) == 0)
		{
			tabuleiro->setMatriz(pos_final_i, pos_final_j, tabuleiro->getMatriz(pos_atual_i, pos_atual_j));
			tabuleiro->setMatriz(pos_atual_i, pos_atual_j, "0");
			inicializa_posicao(pos_final_i, pos_final_j);
			return true;
	    }
  	}

    //verificando se caminho final eh valido para caminho tipo do bispo
	if( (pos_final_j - pos_final_i) == (pos_atual_j - pos_atual_i) ||  (pos_final_j + pos_final_i) == (pos_atual_j + pos_atual_i) ) // caso nao seja invalida a posicao
	{
		//conferindo se tem alguma peca para capturar
		if(peca_no_caminho_bispo(pos_atual_i,pos_atual_j, pos_final_i, pos_final_j, tabuleiro) == 0)
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

int Rainha::peca_no_caminho_torre(int pos_atual_i, int pos_atual_j, int pos_final_i, int pos_final_j, Tabuleiro *tabuleiro)
{
if(pos_atual_i == pos_final_i && pos_atual_j == pos_final_j) return 1;

	if(pos_atual_i == pos_final_i && pos_atual_j > pos_final_j)//caso 1 = andando reto para  a esquerda
	{
		int i = pos_atual_i;
		int j = pos_atual_j-1;

		while(j > pos_final_j)
		{			
			if(tabuleiro->getMatriz(i, j) != "0")
			{
				return 1;//caso return 1 significa que tem peca
			}
			j--;
		}
		return 0;//se retornar zero que dizer que nao tem peca no caminho
	}

	if(pos_atual_i == pos_final_i && pos_atual_j < pos_final_j)//caso 2 = andando  reto para a direita
	{
		int i = pos_atual_i;
		int j = pos_atual_j+1;	

		while(j < pos_final_j)
		{			
			if(tabuleiro->getMatriz(i, j) != "0")
			{				
				return 1;//caso return 1 significa que tem peca
			}
			j++;
		}

		return 0;//se retornar zero que dizer que nao tem peca no caminho		
	}

	if(pos_atual_i < pos_final_i && pos_atual_j == pos_final_j)//caso 3  = andando para baixo  reto
	{
		int i = pos_atual_i+1;
		int j = pos_atual_j;
		while(i < pos_final_i)
		{			
			if(tabuleiro->getMatriz(i, j) != "0")
			{
				return 1;//caso return 1 significa que tem peca
			}
			i++;
		}
		return 0;//se retornar zero que dizer que nao tem peca no caminho
	}

	if(pos_atual_i > pos_final_i && pos_atual_j == pos_final_j)//caso 4 = andando para cima  direita
	{
		int i = pos_atual_i-1;
		int j = pos_atual_j;
		while(i > pos_final_i)
		{			
			if(tabuleiro->getMatriz(i, j) != "0")
			{
				return 1;//caso return 1 significa que tem peca
			}
			i--;
		}
		return 0;//se retornar zero que dizer que nao tem peca no caminho
	}

	return 0;
}	


int Rainha::peca_no_caminho_bispo(int pos_atual_i, int pos_atual_j, int pos_final_i, int pos_final_j, Tabuleiro *tabuleiro)
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

