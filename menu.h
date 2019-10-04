#ifndef MENU_H
#define MENU_H

 
#define TECLAPARACIMA1 119
#define TECLAPARACIMA2 87
#define TECLAPARABAIXO1 115
#define TECLAPARABAIXO2 83
#define ENTER 10
#define SAIRDOPROGRAMA 0
#define CARREGARARQUIVOINICIAL 11
#define INSERIRLIVRO 2
#define ATUALIZAREXEMPLARES 3
#define REMOVERLIVRO 4
#define BUSCARDADOSDOLIVRO 5
#define IMPRIMIRARVORENIVEL 7
#define IMPRIMIRACERVO 8
#define MENUPRINCIPAL 1

/* Captura um char do terminal
 * Pré-condição: nenhuma
 * Pós-condição: retorna o caracter 
*/
char getchChar();
/* Exibe o retorno ao menu
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
*/
void backmenu();
/* Função auxiliar que ajuda a movimentação no menu
 * Pré-condição: Nenhuma
 * Pós-condição: A posição correta do menu é retornada
*/
int movmentMenu(int teclaPressionada, int *posicaoDoMenu, int primeiro, int ultimo);

/* Função que mostra na tela o menu base
 * Pré-condição: Nenhuma
 * Pós-condição: O menu base é executado
*/
void mainMenu(int *var);

/* Função que executa os menus
 * Pré-condição: Nenhuma
 * Pós-condição: O menu é executado
*/
void deciderMenu();
#endif
