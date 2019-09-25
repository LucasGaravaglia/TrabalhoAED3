#ifndef UTILIZAVEIS_H
#define UTILIZAVEIS_H

#include <iostream>

using namespace std;

class Log{
private:

public:
    //Construtor padrão da classe Log
    Log();

    /* Método que retorna uma mensagem de erro formatada
     * Entrada:      Descrição, severidade, arquivo, causa e linha do erro
     * Retorno:      String contendo a mensagem de erro formatada
     * Pré-condição: Nenhuma
     * Pós-condição: A mensagem de erro formatada é retornada
    */
    string printErrorMessage(string descricao, string severidade, string arquivo,
                           string causa, int linha);

    //Destrutor da classe Log
    ~Log();
};

#endif