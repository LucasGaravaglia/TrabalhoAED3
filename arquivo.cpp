#include "arquivo.h"

//Construtor padrão da classe Arquivo
Arquivo::Arquivo(){
    this->entrada          =  NULL;
    this->saida            =  NULL;
    this->sucessoNaLeitura = false;
    this->nomeEntrada      =    "";
    this->nomeSaida        =    "";
    this->entradaAberta    = false;
    this->saidaAberta      = false;
}

//Construtor que recebe o nome do arquivo de entrada
Arquivo::Arquivo(string nomeEntrada){
    this->entrada          =        NULL;
    this->entradaAberta    =       false;
    this->saida            =        NULL;
    this->saidaAberta      =       false;
    this->nomeEntrada      = nomeEntrada;
    this->nomeSaida        =          "";
    this->sucessoNaLeitura =       false;
}

//Construtor que recebe o nome do arquivo de entrada e o de saida
Arquivo::Arquivo(string nomeEntrada, string nomeSaida){
    this->entrada          =        NULL;
    this->entradaAberta    =       false;
    this->saida            =        NULL;
    this->saidaAberta      =       false;
    this->nomeEntrada      = nomeEntrada;
    this->nomeSaida        =   nomeSaida;
    this->sucessoNaLeitura =       false;
}

/* Setter da variável nomeSaida
 * Entrada:      Nome do arquivo de saida
 * Retorno:      Nenhum
 * Pré-condição: Nenhuma
 * Pós-condição: A variável nomeSaida é atualizada com o parâmetro passado
*/
void Arquivo::setNomeSaida(string nomeSaida){
    this->nomeSaida = nomeSaida;
}

/* Getter da variável nomeSaida
 * Entrada:      Nenhuma
 * Retorno:      Nome do arquivo de saida
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
*/
string Arquivo::getNomeSaida(){
    return this->nomeSaida;
}

/* Setter da variável nomeEntrada
 * Entrada:      Nome do arquivo de entrada
 * Retorno:      Nenhum
 * Pré-condição: Nenhuma
 * Pós-condição: A variável nomeEntrada é atualizada com o parâmetro passado
*/
void Arquivo::setNomeEntrada(string nomeEntrada){
    this->nomeEntrada = nomeEntrada;
}

/* Getter da variável nomeEntrada
 * Entrada:      Nenhuma
 * Retorno:      Nome do arquivo de entrada
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
*/
string Arquivo::getNomeENtrada(){
    return this->nomeEntrada;
}

/* Setter da variável saida
 * Entrada:      Ponteiro para o arquivo de saida
 * Retorno:      Nenhum
 * Pré-condição: Nenhuma
 * Pós-condição: A variável saida é atualizada com o parâmetro passado
*/
void Arquivo::setSaida(FILE* saida){
    this->saida = saida;
}

/* Getter da variável saida
 * Entrada:      Nenhuma
 * Retorno:      Ponteiro para o arquivo de saida
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
*/
FILE* Arquivo::getSaida(){
    return this->saida;
}

/* Setter da variável entrada
 * Entrada:      Ponteiro para o arquivo de entrada
 * Retorno:      Nenhum
 * Pré-condição: Nenhuma
 * Pós-condição: A variável entrada é atualizada com o parâmetro passado
*/
void Arquivo::setEntrada(FILE* entrada){
    this->entrada = entrada;
}

/* Getter da variável entrada
 * Entrada:      Nenhuma
 * Retorno:      Ponteiro para o arquivo de entrada
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
*/
FILE* Arquivo::getEntrada(){
    return this->entrada;
}

/* Setter da variável sucessoNaLeitura
 * Entrada:      Boolean
 * Retorno:      Nenhum
 * Pré-condição: Nenhuma
 * Pós-condição: O valor da variável sucessoNaLeitura é atualizado
*/
void Arquivo::setSucesso(bool sucesso){
    this->sucessoNaLeitura = sucesso;
}

/* Getter da variável sucessoNaLeitura
 * Entrada:      Nenhuma
 * Retorno:      Verdadeiro ou falso
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
*/
bool Arquivo::getSucesso(){
    return this->sucessoNaLeitura;
}

/* Setter da variável saidaAberta
 * Entrada:      True ou false
 * Retorno:      Nenhum
 * Pré-condição: Nenhuma
 * Pós-condição: A variável é setada para o valor do parâmetro
*/
void Arquivo::setSaidaAberta(bool saidaAberta){
    this->saidaAberta = saidaAberta;
}

/* Getter da varável saidaAberta
 * Entrada:      Nenuma
 * Retorno:      True ou false
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
*/
bool Arquivo::getSaidaAberta(){
    return this->saidaAberta;
}

/* Setter da variável entradaAberta
 * Entrada:      True ou false
 * Retorno:      Nenhum
 * Pré-condição: Nenhuma
 * Pós-condição: A variável é setada para o valor do parâmetro
*/
void Arquivo::setEntradaAberta(bool entradaAberta){
    this->entradaAberta = entradaAberta;
}  

/* Getter da varável entradaAberta
 * Entrada:      Nenuma
 * Retorno:      True ou false
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
*/  
bool Arquivo::getEntradaAberta(){
    return this->entradaAberta;
}

/* Método que abre o arquivo de saida para a escrita
 * Entrada:      Nome do arquivo de saida
 * Retorno:      True caso consiga abrir ou false caso contrário
 * Pré-condição: Nenhuma
 * Pós-condição: O arquivo saida é aberto para escrita com a opção "r+b"
*/
bool Arquivo::abrirSaida(char* arquivo){
    if(this->saidaAberta == false){
        this->saida       = fopen(arquivo,"r+b");
        this->saidaAberta =                 true;
        return true;
    }else{
        cout << this->log.printErrorMessage(
                "Erro ao abrir arquivo",
                "Média",
                "arquivo.cpp",
                "Arquivo já aberto",
                182                        );
    }
    return false;
}

/* Método que fecha o arquivo de saida
 * Entrada:      Nenhuma
 * Retorno:      True caso consiga fechar ou false caso contrário
 * Pré-condição: O arquivo deve estar aberto
 * Pós-condição: O arquivo é fechado
*/
bool Arquivo::fecharSaida(){
    if(this->saidaAberta == true){
        fclose(this->saida);
        this->saidaAberta = false;
        return true;
    }else{
        cout << this->log.printErrorMessage     (
                "Erro ao fechar arquivo",
                "Alta",
                "arquivo.cpp",
                "Arquivo Não foi aberto",
                204                             )
                << endl;
    }
    return false;
}

/* Método que abre o arquivo de entrada para a leitura
 * Entrada:      Nome do arquivo de entrada
 * Retorno:      True caso consiga abrir ou false caso contrário
 * Pré-condição: Nenhuma
 * Pós-condição: O arquivo entrada é aberto para leitura
*/
bool Arquivo::abrirEntrada(char* arquivo){
    if(this->entradaAberta == false){
        this->entrada       = fopen(arquivo,"r+b");
        this->entradaAberta =                 true;
        return true;
    }else{
        cout << this->log.printErrorMessage(
                "Erro ao abrir arquivo",
                "Média",
                "arquivo.cpp",
                "Arquivo já aberto",
                227                        );
    }
    return false;
}

/* Método que fecha o arquivo de entrada
 * Entrada:      Nenhuma
 * Retorno:      True caso consiga fechar ou false caso contrário
 * Pré-condição: O arquivo deve estar aberto
 * Pós-condição: O arquivo é fechado
*/
bool Arquivo::fecharEntrada(){
        if(this->entradaAberta == true){
        fclose(this->entrada);
        this->entradaAberta = false;
        return true;
    }else{
        cout << this->log.printErrorMessage     (
                "Erro ao fechar arquivo",
                "Alta",
                "arquivo.cpp",
                "Arquivo Não foi aberto",
                249                             )
                << endl;
    }
    return false;
}

/* Método que escreve o cabeçalho no arquivo de livros
 * Entrada:      Ponteiro para a struct que contém o cabeçalho do arquivo de livros a ser escrito
 * Retorno:      True caso tenha dado certo ou false caso contrário
 * Pré-condição: A variável nomeSaida deve estar preenchida com o nome correto
 * Pós-condição: O cabeçalho é escrito no arquivo de saída
*/
bool Arquivo::escreverCabecalhoLivros(CabecalhoLivro* cab){
    if(this->nomeSaida != ""){
        char aux[this->nomeSaida.size() + 1];
        strcpy(aux,this->nomeSaida.c_str());
        this->abrirSaida(aux);
        if(this->saidaAberta == true){
            fseek(this->saida,0,SEEK_SET);
            this->sucessoNaLeitura = (fwrite(cab,sizeof(CabecalhoLivro),1,this->saida) == 1);
            this->fecharSaida();
            return this->sucessoNaLeitura;
        }
        this->sucessoNaLeitura = false;
    }else{
        cout << this->log.printErrorMessage                       (
                "Erro ao abrir arquivo",
                "Média",
                "arquivo.cpp",
                "Arquivo já aberto ou nome do arquivo não setado",
                272                                               )
                << endl;
    }
    return false;
}

/* Método que lê o cabeçalho no arquivo de livros
 * Entrada:      Nenhuma
 * Retorno:      Struct do cabeçalho lido ou NULL caso não leia
 * Pré-condição: A variável entrada deve estar preenchida com o nome correto.
 * Pós-condição: O cabeçalho é lido e retornado do arquivo de entrada
*/
CabecalhoLivro* Arquivo::lerCabecalhoLivros(){
    CabecalhoLivro *cab = new CabecalhoLivro;
    if(this->nomeEntrada != ""){
        char aux[this->nomeEntrada.size() + 1];
        strcpy(aux,this->nomeEntrada.c_str());
        this->abrirEntrada(aux);
        if(this->entradaAberta == true){
            fseek(this->entrada,0,SEEK_SET);
            this->sucessoNaLeitura = (fread(cab,sizeof(CabecalhoLivro),1,this->entrada) == 1);
            this->fecharEntrada();
            return cab;
        }
        return NULL;
    }else{
        cout << this->log.printErrorMessage                       (
        "Erro ao abrir arquivo",
        "Média",
        "arquivo.cpp",
        "Arquivo já aberto ou nome do arquivo não setado",
        302                                               )
        << endl;
    }
    return NULL;
}

/* Método que cria um arquivo de livros vazio
 * Entrada:      Nenhuma
 * Retorno:      True caso tenha dado certo ou false caso contrário
 * Pré-condição: A variavel nomeSaida deve possuir o nome correto
 * Pós-condição: O arquivo de livros é inicializado
*/
bool Arquivo::criarArquivoLivrosVazio(){
    if(this->nomeSaida != ""){
        string s = "rm ";
        s += this->nomeSaida;
        s += " & clear && echo arquivo antigo removido com sucesso!";
        system(s.c_str());
        CabecalhoLivro cab;
        cab.topo     =  0;
        cab.posLivre = -1;
        char aux[this->nomeSaida.size() +1];
        strcpy(aux,this->nomeSaida.c_str());
        this->saida       = fopen(aux,"w+b");
        this->saidaAberta = true;
        this->fecharSaida();
        this->escreverCabecalhoLivros(&cab);
        cout << "Arquivo de livros inicializado com sucesso!\n";
        return true;
    }else{
        cout << this->log.printErrorMessage              (
        "Erro criar arquivo vazio de livros",
        "Média",
        "arquivo.cpp",
        "Nome do arquivo de saída não definido",
        333                                              )
        << endl;
    }
    return false;
}

/* Método que escreve o cabeçalho no arquivo de árvore
 * Entrada:      Cabeçalho do arquivo de árvore
 * Retorno:      True caso consiga escrever ou false caso contrário
 * Pré-condição: A variável nomeSaida deve estar com o nome corereto
 * Pós-condição: O cabeçalho é escrito no arquivo de saida
*/
bool Arquivo::escreverCabecalhoArvore(CabecalhoArvore* cab){
    if(this->nomeSaida != ""){
        char aux[this->nomeSaida.size() + 1];
        strcpy(aux,this->nomeSaida.c_str());
        this->abrirSaida(aux);
        if(this->saidaAberta == true){
            fseek(this->saida,0,SEEK_SET);
            this->sucessoNaLeitura = (fwrite(cab,sizeof(CabecalhoArvore),1,this->saida) == 1);
            this->fecharSaida();
            return this->sucessoNaLeitura;
        }
        this->sucessoNaLeitura = false;
    }else{
        cout << this->log.printErrorMessage                       (
        "Erro ao abrir arquivo",
        "Média",
        "arquivo.cpp",
        "Arquivo já aberto ou nome do arquivo não setado",
        368                                               )
        << endl;
    }
    return false;
}

/* Método que lê o cabeçalho no arquivo de árvore
 * Entrada:      Nenhuma
 * Retorno:      Struct do cabeçalho lido ou NULL caso não leia
 * Pré-condição: A variável entrada deve estar preenchida com o nome correto.
 * Pós-condição: O cabeçalho é lido e retornado do arquivo de entrada
*/
CabecalhoArvore* Arquivo::lerCabecalhoArvore(){
     CabecalhoArvore *cab = new CabecalhoArvore;
    if(this->nomeEntrada != ""){
        char aux[this->nomeEntrada.size() + 1];
        strcpy(aux,this->nomeEntrada.c_str());
        this->abrirEntrada(aux);
        if(this->entradaAberta == true){
            fseek(this->entrada,0,SEEK_SET);
            this->sucessoNaLeitura = (fread(cab,sizeof(CabecalhoArvore),1,this->entrada) == 1);
            this->fecharEntrada();
            return cab;
        }
        return NULL;
    }else{
        cout << this->log.printErrorMessage               (
        "Erro ao abrir arquivo",
        "Média",
        "arquivo.cpp",
        "Arquivo já aberto ou nome do arquivo não setado",
        398                                               )
        << endl;
    }
    return NULL;
}

/* Método que cria um arquivo de árvore vazio
 * Entrada:      Nenhuma
 * Retorno:      True caso tenha dado certo ou false caso contrário
 * Pré-condição: A variavel nomeSaida deve possuir o nome correto
 * Pós-condição: O arquivo de árvore é inicializado
*/
bool Arquivo::criarArquivoArvoreVazio(){
    if(this->nomeSaida != ""){
        string s = "rm ";
        s += this->nomeSaida;
        s += " & clear && echo arquivo antigo removido com sucesso!";
        system(s.c_str());
        CabecalhoArvore cab;
        cab.topo     =  0;
        cab.posLivre = -1;
        cab.raiz     = -1;
        char aux[this->nomeSaida.size() +1];
        strcpy(aux,this->nomeSaida.c_str());
        this->saida       = fopen(aux,"w+b");
        this->saidaAberta = true;
        this->fecharSaida();
        this->escreverCabecalhoArvore(&cab);
        cout << "Arquivo de livros inicializado com sucesso!\n";
        return true;
    }else{
        cout << this->log.printErrorMessage              (
        "Erro criar arquivo vazio de livros",
        "Média",
        "arquivo.cpp",
        "Nome do arquivo de saída não definido",
        429                                              )
        << endl;
    }
    return false;
}

/* Método que lê um nó do arquivo binário de árvore B+
 * Entrada:      Posição do nó que será lido no arquivo
 * Retorno:      Nó lido ou NULL caso não exista
 * Pré-condição: A variavel nomeEntrada deve possuir o nome correto do arquivo
 * Pós-condição: O nó é lido do arquivo
*/
NoBMais* Arquivo::lerNo(int pos){
    char aux[this->nomeEntrada.size() + 1];
    strcpy(aux,this->nomeEntrada.c_str());
    this->abrirEntrada(aux);
    if(this->entradaAberta){
        NoBMais* noLido = new NoBMais;
        fseek(this->entrada,sizeof(CabecalhoArvore)+(pos*sizeof(NoBMais)),SEEK_SET);
        fread(noLido,sizeof(NoBMais),1,this->entrada);
        this->fecharEntrada();
        return noLido;
    }
    this->log.printErrorMessage(
        "Erro ao abrir arquivo binário de árvore",
        "Média",
        "arquivo.cpp",
        "Não conseguiu abrir o arquivo",
        465                    );
    return NULL;
}

/* Método que escreve um nó no árquivo binário de árvore
 * Entrada:      Nó da árvore B+ e posição em que será escrito o nó
 * Retorno:      Nenhum
 * Pré-condição: A variável nomeSaida deve estar com o nome correto do arquivo
 * Pós-condição: O nó é escrito no arquivo
*/
void Arquivo::escreverNo(NoBMais no, int pos){
    char aux[this->nomeSaida.size() + 1];
    strcpy(aux,this->nomeSaida.c_str());
    this->abrirSaida(aux);
    if(this->saidaAberta){
        fseek(this->saida,sizeof(CabecalhoArvore)+(pos*sizeof(NoBMais)),SEEK_SET);
        fwrite(&no,sizeof(NoBMais),1,this->saida);
        this->fecharSaida();
    }else{
    this->log.printErrorMessage(
        "Erro ao abrir arquivo binário de árvore",
        "Média",
        "arquivo.cpp",
        "Não conseguiu abrir o arquivo",
        491                    );
    }
}

/* Método que busca a proxima posição livre para ser escrita no arquivo bínario de arvore
 * Entrada:      Cabeçalho do arquivo binario de arvore
 * Retorno:      Posição livre para escrita
 * Pré-condição: Variavel nomeEntrada deve possuir o nome correto do arquivo
 * Pós-condição: Nenhuma
*/
int buscaProxPos(CabecalhoArvore cab){
    if(cab.posLivre == -1){
        return cab.topo;
    }
    
    return cab.posLivre
}

//Destrutor padrão da classe Arquivo
Arquivo::~Arquivo(){

}