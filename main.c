#include <stdio.h>
#define LinhasTabuleiro 8
#define ColunasTabuleiro 8

/*
    Centro Universitario SENAC Santo Amaro
    Engenharia da Computação
        Algoritmos e Programação
        Profº Fabio Lubacheski
        Trabalho 01 - Jogo de Damas

    Rafael Fortunatti Simoes
        rafael.fortunatti@gmail.com

*/

/*Regras basicas para esse jogo de damas:
    -As pecas normais se movimentam apenas nas diagonais em relaçao ao oponente
    -Não eh permitido "comer" mais de uma peca em uma unica jogada, por mais possivel que seja faze-lo.
    -Os jogadores serao identificados no tabuleiro pelas letras P e B.
*/


char checarPecaVazia (int tabuleiro[][8], int xMatriz, int yMatriz)
{
    //Esta funcao verifica o que existe em uma posicao especifica do tabuleiro nas coordenadas especificadas.
    //Caso esteja vazia, retorna 1; caso contrário, a peca presente.

    if(tabuleiro[xMatriz][yMatriz] == ' ')
        return 1;
    else
        return tabuleiro[xMatriz][yMatriz];

}

//A funcao game eh a que efetivamente faz a logica do jogo: recebe a jogada, valida e executa na estrutura de dados
//Fora o tabuleiro, recebe a ID do jogador (0 para Preto, 1 para Branco), as coordenadas da peca selecionada e
//a direcao da jogada, esquerda (0) ou direita (1).
//Retorna 1 para jogada valida e executada.
//Retorna 0 para jogada invalida.

int game(char tabuleiro[][8], char idJogador, int xFrom, int yFrom, int leftRight)
{
    if(xFrom < 0 || yFrom > 7)
        return 0;

    //Logica de execucao para jogador Preto
    if(idJogador == 'P')
    {
        //Checo se realmente tem uma peca Preta no local indicado.
        if(tabuleiro[xFrom][yFrom] != 'P')
            return 0;
        else{
            //Movimentacao para a ESQUERDA
            if(leftRight == 0)
            {
               //Para a peca que vai para a esquerda, isto eh, seu index fica [x+1][y-1]
               //Primeiro checo se a posicao eh valida na estrutura da matriz
               if(xFrom + 1 > 7 || yFrom - 1 < 0)
                    return 0;
               if(checarPecaVazia(tabuleiro, xFrom + 1, yFrom - 1) == 'P')
                    return 0;
               if(checarPecaVazia(tabuleiro, xFrom + 1, yFrom - 1) == 'B')
               {
                   //Se tiver uma peca Branca para comer, obrigatoriamente vai descer duas casas diagonais
                   //Logo, preciso valida-las. A logica eh a mesma, mas a variacao do index eh 2 em vez de 1.
                   if(xFrom + 2 > 7 || yFrom - 2 < 0)
                        return 0;
                   tabuleiro[xFrom][yFrom] = ' ';
                   tabuleiro[xFrom + 1][yFrom - 1] = ' ';
                   tabuleiro[xFrom + 2][yFrom - 2] = 'P';
                   return 1;
               }

               if(tabuleiro[xFrom + 1][yFrom - 1] == ' ')
               {
                   tabuleiro[xFrom][yFrom] = ' ';
                   tabuleiro[xFrom + 1][yFrom - 1] = 'P';
                   return 1;
               }
            }
            //Movimentacao para a DIREITA
            if(leftRight == 1)
            {
                //Para a peca que vai para a esquerda, isto eh, seu index fica [x+1][y+1]
               //Primeiro checo se a posicao eh valida na estrutura da matriz
                if(xFrom + 1 > 7 || yFrom + 1 > 7)
                    return 0;
                //Verifico se a diagonal a direita esta ocupada e jogavel.
                if(checarPecaVazia(tabuleiro, (xFrom + 1), (yFrom + 1)) == 'P')
                    return 0;
                if(checarPecaVazia(tabuleiro, (xFrom + 1), (yFrom + 1)) == 'B')
                {
                   //Se tiver uma peca Branca para comer, obrigatoriamente vai descer duas casas diagonais
                   //Logo, preciso valida-las. A logica eh a mesma, mas a variacao do index eh 2 em vez de 1.
                   if(xFrom + 2 > 7 || yFrom + 2 > 7)
                        return 0;
                   tabuleiro[xFrom][yFrom] = ' ';
                   tabuleiro[xFrom + 1][yFrom + 1] = ' ';
                   tabuleiro[xFrom + 2][yFrom + 2] = 'P';
                   return 1;
                }

                if(tabuleiro[xFrom + 1][yFrom - 1] == ' ')
                {
                   tabuleiro[xFrom][yFrom] = ' ';
                   tabuleiro[xFrom + 1][yFrom + 1] = 'P';
                   return 1;
                }
            }
        }


    }
    //Logica de execucao pro jogador Branco
    //Semelhante a de B, porem atua de forma invertida no tabuleiro.
    if(idJogador == 'B')
    {
        //Checo se realmente tem uma peca Preta no local indicado.
        if(tabuleiro[xFrom][yFrom] != 'B')
            return 0;
        else{
            if(leftRight == 0)
            {
               //Para a peca que vai para a esquerda, isto eh, seu index fica [x-1][y-1]
               //Primeiro checo se a posicao eh valida na estrutura da matriz
               if(xFrom - 1 < 0 || yFrom + 1 < 0)
                    return 0;
               if(checarPecaVazia(tabuleiro, (xFrom - 1), (yFrom - 1)) == 'B')
                    return 0;
               if(checarPecaVazia(tabuleiro, (xFrom - 1), (yFrom - 1)) == 'P')
               {
                   //Se tiver uma peca Branca para comer, obrigatoriamente vai descer duas casas diagonais
                   //Logo, preciso valida-las. A logica eh a mesma, mas a variacao do index eh 2 em vez de 1.
                   if(xFrom - 2 > 7 || yFrom - 2 < 0)
                        return 0;
                   tabuleiro[xFrom][yFrom] = ' ';
                   tabuleiro[xFrom - 1][yFrom - 1] = ' ';
                   tabuleiro[xFrom - 2][yFrom - 2] = 'B';
                   return 1;
               }

               if(tabuleiro[xFrom - 1][yFrom - 1] == ' ')
               {
                   tabuleiro[xFrom][yFrom] = ' ';
                   tabuleiro[xFrom - 1][yFrom - 1] = 'B';
                   return 1;
               }
            }
            if(leftRight == 1)
            {
                //Para a peca que vai para a esquerda, isto eh, seu index fica [x+1][y+1]
               //Primeiro checo se a posicao eh valida na estrutura da matriz
                if(xFrom - 1 < 0 || yFrom + 1 > 7)
                    return 0;
                //Verifico se a diagonal a direita esta ocupada e jogavel.
                if(checarPecaVazia(tabuleiro, (xFrom - 1), (yFrom + 1)) == 'B')
                    return 0;
                if(checarPecaVazia(tabuleiro, (xFrom - 1), (yFrom + 1)) == 'P')
                {
                   //Se tiver uma peca Branca para comer, obrigatoriamente vai descer duas casas diagonais
                   //Logo, preciso valida-las. A logica eh a mesma, mas a variacao do index eh 2 em vez de 1.
                   if(xFrom - 2 < 0 || yFrom + 2 > 7)
                        return 0;
                   tabuleiro[xFrom][yFrom] = ' ';
                   tabuleiro[xFrom - 1][yFrom + 1] = ' ';
                   tabuleiro[xFrom - 2][yFrom + 2] = 'B';
                   return 1;
                }

                if(tabuleiro[xFrom - 1][yFrom + 1] == ' ')
                {
                   tabuleiro[xFrom][yFrom] = ' ';
                   tabuleiro[xFrom - 1][yFrom + 1] = 'B';
                   return 1;
                }
            }
        }


    }

}

//A função status, que recebe apenas o tabuleiro como parametro, conta a quantidade de pecas brancas e pretas presente.
//Isto eh, quantos chars de P e B existem na matriz. Caso retorne 0, o jogo continua. 1 para Preto vencedor e 2 para Branco.

int status(char tabuleiro[][8])
{
    int presentePreto = 0;
    int presenteBranco = 0;
    int counterX, counterY;
    //Conto as pecas pretas
    for(counterX = 0; counterX <= 7; counterX++)
    {
        for(counterY = 0; counterY <= 7; counterY++)
        {
            if(tabuleiro[counterX][counterY] == 'P')
                presentePreto = 1;
            if(tabuleiro[counterX][counterY] == 'B')
                presenteBranco = 1;
        }
    }
    if(presentePreto && presenteBranco)
        return 0;
    if(presentePreto)
        return 1;
    if(presenteBranco)
        return 2;
}

void initialize(char tabuleiro[][8])
{
    //Preencho minha matriz com espacos vazios antes de qualquer coisa.

    int cntLinha, cntColuna;

    for(cntLinha = 0; cntLinha<=7; cntLinha++){
       for(cntColuna = 0; cntColuna <= 7; cntColuna++){
           tabuleiro[cntLinha][cntColuna] = ' ';
       }
    }

    //Como o tabuleiro de Damas tem apenas 24 pecas, eh mais facil fazer seis lacos que preenchem
    //  as casas da forma conveniente, sendo tres lacos para cada jogador.

    //Preencho a primeira linha de P
    for(cntColuna = 1; cntColuna <= 7; cntColuna += 2)
        tabuleiro[0][cntColuna] = 'P';
     //Preencho a segunda linha de P
    for(cntColuna = 0; cntColuna <= 6; cntColuna += 2)
        tabuleiro[1][cntColuna] = 'P';
     //Preencho a terceira linha de P
    for(cntColuna = 1; cntColuna <= 7; cntColuna += 2)
        tabuleiro[2][cntColuna] = 'P';

    //Preencho a primeira linha de B
    for(cntColuna = 6; cntColuna >= 0; cntColuna -= 2)
        tabuleiro[7][cntColuna] = 'B';
     //Preencho a segunda linha de B
    for(cntColuna = 7; cntColuna >= 1; cntColuna -= 2)
        tabuleiro[6][cntColuna] = 'B';
     //Preencho a terceira linha de B
    for(cntColuna = 6; cntColuna >= 0; cntColuna -= 2)
        tabuleiro[5][cntColuna] = 'B';


}

void imprimeTabuleiro(char tabuleiro[][8])
{
    //Imprime o tabuleiro com as barras, usando a logica de linha e coluna. Uma impressao simples de matriz.
    int iLinha, iColuna;

    printf("  0 1 2 3 4 5 6 7\n");
    for(iLinha = 0; iLinha <= 7; iLinha++){
        printf("%d", iLinha);
        for(iColuna = 0; iColuna <= 7; iColuna++){
           printf("|%c", tabuleiro[iLinha][iColuna]);
        }
       printf("|\n");
    }
}


int main(){

    char **tabuleiroMatriz[8][8];
    char idenJogador = 'P';
    initialize(tabuleiroMatriz);

    int leftRight;
    int xJogador, yJogador;

    //Acima estao declaradas variaveis como:
    //tabuleiroMatriz: ponteiro para a matriz tabuleiro, inicializada em initialize()
    //leftRight, um int binário que recebe a ordem do jogador de esquerda ou direita
    //xJogador e yJogador guardam as coordenadas da peca escolhida no tabuleiro, sendo xJogador a linha e yJogador a coluna.

    //O laco que efetivamente roda o jogo
    do{
        printf("Jogo de Damas\n\n");
        printf("Vez do jogador %c\n", idenJogador);
        imprimeTabuleiro(tabuleiroMatriz);

        printf("\nEntre com a coordenada da linha:");
        scanf("%d", &xJogador);
        printf("\nEntre com a coordenada da coluna:");
        scanf("%d", &yJogador);
        printf("\nEsquerda (0) ou Direita(1)?");
        scanf("%d", &leftRight);
        //Se a jogada em game() retornar 0, continua no laco indefinidamente com o mesmo jogador ate ser uma jogada valida que retorna 0
        if(!game(tabuleiroMatriz, idenJogador, xJogador, yJogador, leftRight))
        {
            system("cls");
            printf("\nJogada invalida. Tente novamente\n\n");
            //imprimeTabuleiro(tabuleiroMatriz);
            continue;
        }
        else
        {
            //Com a jogada concluida, os jogadores sao trocados e a logica recomeca.
            if(idenJogador == 'P')
                idenJogador = 'B';
            else
                idenJogador = 'P';
        }
        system("cls");
        //Isto acima roda ate status() retornar o jogador ganhador, com status() > 0.
    }while(!status(tabuleiroMatriz));

    if(status(tabuleiroMatriz) == 1)
        printf("\nJogador preto vencedor!");
    else
        printf("\nJogador branco vencedor!");

    system("PAUSE");
}
