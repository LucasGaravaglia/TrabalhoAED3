#include "utilizaveis.h"

//Construtor padrão da classe Log
Log::Log(){

}

/* Método que retorna uma mensagem de erro formatada
 * Entrada:      Descrição, severidade, arquivo, causa e linha do erro
 * Retorno:      String contendo a mensagem de erro formatada
 * Pré-condição: Nenhuma
 * Pós-condição: A mensagem de erro formatada é retornada
*/
string Log::printErrorMessage(string descricao, string severidade, string arquivo,
                                string causa, int linha){
    string error =               "";
    error       +=         "Erro: ";
    error       +=        descricao;
    error       +=             "\n";
    error       +=   "Severidade: ";
    error       +=       severidade;
    error       +=             "\n";
    error       +=        "Causa: ";
    error       +=            causa;
    error       +=             "\n";
    error       +=      "Arquivo: ";
    error       +=          arquivo;
    error       +=             "\n";
    error       +=        "Linha: ";
    error       += to_string(linha);
    return error;
}

//Destrutor da classe Log
Log::~Log(){

}