#include "arvore.h"
#include "arquivo.h"
#include "estruturaArvore.h"

//construtor da classe
BMais::BMais(){
    this->no.ehFolha       = true;
    this->no.numChaves     =    0;
    this->no.pai           =   -1;
    this->cab.posLivre     =   -1;
    this->cab.topo         =    0;
    this->cab.raiz         =   -1;
    this->no.filhos[ORDEM] =   -1;
    this->pos              =    0;
    this->arquivo.setNomeEntrada("arvore.bin");
    this->arquivo.setNomeSaida("arvore.bin");

}

//setter da variavel no
void BMais::setNo(NoBMais no){
    this->no = no;
}

//setter da variavel cab
void BMais::setCab(CabecalhoArvore cab){
    this->cab = cab;
}

//get da variavel no
NoBMais BMais::getNo(){
    return this->no;
}

//get da variavel cab
CabecalhoArvore BMais::getCab(){
    return this->cab;
}

//set da variavel pos
void BMais::setPos(int pos){
    this->pos = pos;
}

//get da variavel pos
int BMais::getPos(){
    return this->pos;
}

/* Método que busca a posição em que está ou estaria a chave em um nó
 * Entrada:      Árvore b+, A chave, Ponteiro para a posição em que estaria a chave
 * Retorno:      1 caso a chave esteja presente ou 0 caso contrário
 * Pré-condição: Nó não pode ser NULL
 * Pós-condição: Nenhuma
*/
bool BMais::buscarPos(int chave, int *pos){
    for((*pos) = 0; (*pos) < this->no.numChaves; (*pos)++){
        if(chave == this->no.chave[(*pos)].info)
            return true;
        else if(chave < this->no.chave[(*pos)].info)
            break;
    }
    return false;
}

/* Método que faz o split de um nó interno(Não folha)
 * Entrada:      Nó BMais e ponteiro para a chave que foi promovida
 * Retorno:      Nó criado pelo split
 * Pré-condição: Nó não pode ser NULL. Nó Deve estar cheio de chaves
 * Pós-condição: O nó sofre split e promove a chave mediana
*/
int BMais::splitB(Chave *chavePromovida){
    NoBMais novoNo;
    int metadeChaves   = this->no.numChaves/2,i,posnovono;
    novoNo.numChaves   = this->no.numChaves - metadeChaves - 1;
    this->no.numChaves = metadeChaves;
    *chavePromovida    = this->no.chave[metadeChaves];
    novoNo.filhos[0]   = this->no.filhos[metadeChaves + 1];
    novoNo.ehFolha = false;
    for(i=0;i < novoNo.numChaves;i++){
        novoNo.chave[i]    = this->no.chave[metadeChaves + 1 + i];
        novoNo.filhos[i+1] = this->no.filhos[metadeChaves + 2 + i];
    }
    novoNo.pai = this->no.pai;
    //Escreve o antigo nó novamente
    this->arquivo.escreverNo(this->no,this->pos);
    if(this->cab.posLivre == -1){
        //Escrevo o novo no, alterando o topo do cabecalho
        this->arquivo.escreverNo(novoNo,this->cab.topo);
        posnovono = (this->cab.topo);
        this->cab.topo++;
    }else{
        //Escrevo o novo no, alterando a posLivre no cabecalho
        NoBMais tempNo;
        tempNo = this->arquivo.lerNo(this->cab.posLivre);
        int novaposLivre = tempNo.pai;
        int possplit = this->cab.posLivre;
        this->arquivo.escreverNo(novoNo,this->cab.posLivre);
        this->cab.posLivre = novaposLivre;
        return possplit;/*  ARRUMAR OS FILHOS DO NOVO NO */
    }
    NoBMais filho;
    for(i=0;i<novoNo.numChaves+1;i++){
        filho = this->arquivo.lerNo(novoNo.filhos[i]);
        filho.pai = posnovono;
        this->arquivo.escreverNo(filho,novoNo.filhos[i]);
    }
    return posnovono;
}

/* Método que faz o split de um nó interno(Folha)
 * Entrada:      Nó BMais e ponteiro para a chave que foi promovida
 * Retorno:      Nó criado pelo split
 * Pré-condição: Nó não pode ser NULL. Nó Deve estar cheio de chaves
 * Pós-condição: O nó sofre split e promove a chave mediana
*/
int BMais::splitBMais(Chave *chavePromovida){
    NoBMais novoNo;
    int metadeChaves         = this->no.numChaves/2,i,x,posnovono;
    for(i=0;i<ORDEM;i++)
        novoNo.filhos[i] = -1;
    x                        = this->no.filhos[ORDEM];
    novoNo.numChaves         = this->no.numChaves - metadeChaves - 1;
    novoNo.ehFolha           = true;
    this->no.numChaves       = metadeChaves;
    *chavePromovida          = this->no.chave[metadeChaves];
    for(i=0;i < novoNo.numChaves;i++){//alterado, revisar
        novoNo.chave[i+1]    = this->no.chave[metadeChaves + 1 + i];
    }
    novoNo.chave[0]    = this->no.chave[metadeChaves];
    novoNo.numChaves++;
    novoNo.filhos[ORDEM]   = x;
    novoNo.pai = this->no.pai;
    if(this->cab.posLivre == -1){
        //Escrevo o novo no, alterando o topo do cabecalho
        this->arquivo.escreverNo(novoNo,this->cab.topo);
        this->no.filhos[ORDEM] = cab.topo;
        posnovono = (this->cab.topo);
        this->cab.topo++;
    }else{
        //Escrevo o novo no, alterando a posLivre no cabecalho
        NoBMais tempNo;
        tempNo = this->arquivo.lerNo(this->cab.posLivre);
        int novaposLivre = tempNo.pai;
        posnovono = this->cab.posLivre;
        this->arquivo.escreverNo(novoNo,this->cab.posLivre);
        this->no.filhos[ORDEM] = cab.posLivre;
        this->cab.posLivre = novaposLivre;
    }
    //Escreve o antigo nó novamente
    this->arquivo.escreverNo(this->no,this->pos);
    return posnovono;
}

/* Método que adiciona uma chave à direita de pos
 * Entrada:      Nó, posição, chave e filho da direita
 * Retorno:      Nenhum
 * Pré-condição: Nó não pode ser NULL
 * Pós-condição: A chave é adiciona à direita de pos
*/
void BMais::adicionarDireita(int pos, Chave chave, int subarvore){
    int i;
    for(i=this->no.numChaves;i>pos;i--){
        this->no.chave[i]         = this->no.chave[i-1];
        this->no.filhos[i+1]      = this->no.filhos[i];
    }
    this->no.chave[pos]    = chave;
    this->no.filhos[pos+1] = subarvore;
    this->no.numChaves++;
    this->arquivo.escreverNo(this->no,this->pos);
}

/* Método que verifica se tem overflow no nó
 * Entrada:      Nenhuma
 * Retorno:      True se houver overflow false caso contrario
 * Pre-condicao: No não null
 * Pos-condicao: Nenhuma
*/
bool BMais::overflow(){
    return this->no.numChaves == ORDEM;
}

/* Método auxiliar para inserir uma chave
 * Entrada:      Arvore b+ e chave a ser inserida
 * Retorno:      Nenhum
 * Pré-condição: A árvore não pode ser NULL
 * Pós-condição: A chave é inserida na árvore
*/
void BMais::inserirAux(Chave chave){
    int posChave;
    if(!this->buscarPos(chave.info,&posChave)){ //Chave não está no nó atual
        if(this->no.ehFolha){
            adicionarDireita(posChave,chave,-1);
        }else{ //Não é folha
            this->mudarNo(this->no.filhos[posChave]);
            this->inserirAux(chave);
            if(this->overflow()){
                Chave m;//valor da chave mediana
                int nosplit;
                if(this->no.ehFolha){
                    nosplit = this->splitBMais(&m);
                }else{
                    nosplit = this->splitB(&m);
                }
                this->mudarNo(this->no.pai); //Volta o pai para o nó atual
                NoBMais temp = this->arquivo.lerNo(nosplit);
                temp.pai = this->pos;
                this->arquivo.escreverNo(temp,nosplit);
                this->adicionarDireita(posChave,m,nosplit);
                
            }else{
                this->mudarNo(this->no.pai); //Volta o pai para o nó atual
            }
        }
    }
}

/* Método que insere uma chave na arvore , fazendo split caso necessario
 * Entrada:      chave a ser inserida
 * Retorno:      Nenhum
 * Pre-condicao: Nenhum
 * Pos-condicao: Nenhum
*/
void BMais::inserir(Chave chave){
    this->cab = this->arquivo.lerCabecalhoArvore();
    int i;
    if(this->cab.topo == 0){ //Não tem raiz
        this->cab.topo     = 1;
        this->cab.raiz     = 0;
        this->no.chave[0]  = chave;
        for(i=0;i<ORDEM;i++)
            this->no.filhos[i] = -1;
        this->no.numChaves = 1;
        this->setPos(0); //Posição em que foi inserida a raiz
    }else{
        this->mudarNo(this->cab.raiz); //Coloca a raiz no nó atual
        this->inserirAux(chave);
        if(this->overflow()){
            Chave chavePromovida;
            int noSplit;
            if(this->no.ehFolha){
                noSplit = this->splitBMais(&chavePromovida);
            }else{
                noSplit = this->splitB(&chavePromovida);
            }
            NoBMais novaraiz;
            novaraiz.chave[0]  = chavePromovida;
            novaraiz.filhos[0] = this->pos;
            novaraiz.filhos[1] = noSplit;
            novaraiz.numChaves = 1;
            novaraiz.ehFolha   = false;
            if(this->cab.posLivre == -1){ //Inserir no topo
                novaraiz.pai = -1;
                this->arquivo.escreverNo(novaraiz,this->cab.topo); 
                this->cab.raiz = this->cab.topo;
                this->mudarNo(this->cab.topo); //Coloca a nova Raiz no nó atual
                this->cab.topo++;
            }else{ //Inserir no posLivre /* OLHAR DEPOIS */
                NoBMais temp;
                temp = this->arquivo.lerNo(this->cab.posLivre);
                this->arquivo.escreverNo(novaraiz,this->cab.posLivre);
               // this->no.pai = this->cab.posLivre;
                this->cab.raiz = this->cab.posLivre;
                novaraiz.pai = this->cab.raiz; /* INSERIR O NÓ NO ARQUIVO DEPOIS DISSO */
                this->cab.posLivre = temp.pai;
            }
            NoBMais filho;
            for(i=0;i<this->no.numChaves+1;i++){ //Arrumando os ponteiros dos filhos para os pais
                filho = this->arquivo.lerNo(this->no.filhos[i]);
                if(filho.numChaves != -1){
                    filho.pai = this->pos;
                    this->arquivo.escreverNo(filho,this->no.filhos[i]);
                }
            }
        }
    }
    this->arquivo.escreverCabecalhoArvore(this->cab);
    this->arquivo.escreverNo(this->no,this->pos);
}

/* Método que imprime um vetor da árvore B+
 * Entrada:      Vetor e tamanho do vetor
 * Retorno:      Nenhum
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
*/
void BMais::printVetBMais(Chave v[], int n){
    int i;
    printf("[");
    for(i=0;i<n;i++){
        if(i<n-1)
            printf("%d,",v[i].info);
        else
            printf("%d",v[i].info);
    }
    printf("]");
}

/* Método que imprime um nivel da árvore b+
 * Entrada:      Nível a ser impresso e nível atual
 * Retorno:      Nenhum
 * Pré-condição: Raiz não nula
 * Pós-condição: O nível é impresso por nível.
*/
void BMais::imprimirPorNivel(int nivel, int atual){
    if(nivel == atual){
        this->printVetBMais(this->no.chave,this->no.numChaves);
    }else{
        int i,posVoltar;
        BMais aux = *this;
        if(atual <= nivel){
            for(i=0;i<aux.no.numChaves+1 && aux.no.filhos[i] != -1;i++){
                aux.mudarNo(aux.no.filhos[i]); //Coloca o nó no próximo filho
                aux.imprimirPorNivel(nivel,atual+1);
                aux.mudarNo(aux.no.pai);
            }
        }
    }
}

/* Método que calcula a altura da árvore B+
 * Entrada:      Nenhuma
 * Retorno:      Altura da árvore B+
 * Pré-condição: Raiz não nula
 * Pós-condição: A altura da árvore é calculada e retornada
*/
int BMais::altura(){
    int altura=0;
    BMais aux;
    CabecalhoArvore cab = this->arquivo.lerCabecalhoArvore();
    aux.no = this->arquivo.lerNo(cab.raiz);
    for(;aux.no.filhos[0] != -1;altura++){
        aux.mudarNo(aux.no.filhos[0]);
    }
    return altura + 1;
}

/* Método que imprime todos os níveis da árvore b+
 * Entrada:      Nenhuma
 * Retorno:      Nenhum
 * Pré-condição: Nenhuma
 * Pós-condição: Todos os níveis da árvore são impressos
*/
void BMais::imprimirTodoOsNiveis(){
    int i,alt,posAtual;
    posAtual            = this->getPos();
    CabecalhoArvore cab = this->arquivo.lerCabecalhoArvore();
    this->mudarNo(cab.raiz);
    alt                  = this->altura();
    for(i=0;i<alt;i++){
        this->imprimirPorNivel(i,0);
        printf("\n");
    }
    this->mudarNo(posAtual);
}

/* Método que muda o nó que está carregado na classe
 * Entrada:      Posição do nó que será carregado do arquivo
 * Retorno:      True caso consiga ler ou False caso contrário
 * Pré-condição: Nenhum
 * Pós-condição: O nó é carregado para a classe
*/
bool BMais::mudarNo(int posNo){
    NoBMais aux;
    aux = this->arquivo.lerNo(posNo);
    if(aux.numChaves != -1){ //Sucesso na leitura. Muda o nó que está na classe
        this->setPos(posNo);
        this->no = this->arquivo.lerNo(posNo);
        return true;
    }
    return false;
}

/* Método usado para ler todas as informações de um nó inseridoo no arquivo
 * Entrada:      Posição do nó no arquivo
 * Retorno:      Nenhum
 * Pre-condicao: Nenhum
 * Pos-condicao: Nenhum
*/
void BMais::DeBug(int pos){
    int i;
    this->mudarNo(pos);
    printf("pos   = %d\npai   = %d: \nfilho = ",pos,this->no.pai);//
    for(i=0;i<=this->no.numChaves;i++)
        printf("%d | ",this->no.filhos[i]);
    printf("\nchave = ");
    for(i=0;i<this->no.numChaves;i++)
        printf(" %d | ",this->no.chave[i]);
    printf("Quantidade de chaves = %d\n",this->no.numChaves);
    if(this->no.ehFolha)
        printf("\nproxima folha = %d",this->no.filhos[ORDEM]);
    printf("\n\n");    
}

/* Método que busca em qual nó FOLHA está uma chave
 * Entrada:      Chave a ser procurada e ponteiro para a chave no vetor
 * Retorno:      Nó em que a chave foi encontrada ou no.numChaves 1 caso não a ache
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
 */ 
NoBMais BMais::buscarChave(Chave chave, int *pos){
    int i;
    BMais aux;
    CabecalhoArvore cab;
    cab = this->arquivo.lerCabecalhoArvore();
    aux.mudarNo(cab.raiz);
    for(i=0;i < aux.no.numChaves && !aux.no.ehFolha;i++){ //Percorrimento da árvore
        if(chave.info < aux.no.chave[i].info) //Vai para a esquerda
            aux.mudarNo(aux.no.filhos[i]);
        else if(i == aux.no.numChaves-1) //Vai para a direita
            aux.mudarNo(aux.no.filhos[i+1]);
    }
    if(aux.no.ehFolha){ //Achou o nó em que deveria estar a chave
        if(aux.buscarPos(chave.info,pos)){ //Achou a posição no vetor em que deveria estar a chave
            if(chave.info == aux.no.chave[*pos].info){ //Achou a chave
                return aux.no;
            }
        }
    }//Não achou a chave
    aux.no.numChaves = -1;
    return aux.no;
}

/* Método que busca em qual nó FOLHA está uma chave
 * Entrada:      Chave a ser procurada, ponteiro para a chave no vetor e para o nó no arquivo
 * Retorno:      Nó em que a chave foi encontrada ou no.numChaves 1 caso não a ache
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
*/
NoBMais BMais::buscarChave(Chave chave, int *posChave, int *posNo){
    int i;
    BMais aux;
    CabecalhoArvore cab;
    cab = this->arquivo.lerCabecalhoArvore();
    aux.mudarNo(cab.raiz);
    for(i=0;i < aux.no.numChaves && !aux.no.ehFolha;i++){ //Percorrimento da árvore
        if(chave.info < aux.no.chave[i].info) //Vai para a esquerda
            aux.mudarNo(aux.no.filhos[i]);
        else if(i == aux.no.numChaves-1) //Vai para a direita
            aux.mudarNo(aux.no.filhos[i+1]);
    }
    if(aux.no.ehFolha){ //Achou o nó em que deveria estar a chave
        if(aux.buscarPos(chave.info,posChave)){ //Achou a posição no vetor em que deveria estar a chave
            if(chave.info == aux.no.chave[*posChave].info){ //Achou a chave
                *posNo = aux.pos;
                return aux.no;
            }
        }
    }//Não achou a chave
    aux.no.numChaves = -1;
    return aux.no;
}

/* Método que busca em qual nó FOLHA está uma chave
 * Entrada:      Chave a ser procurada, ponteiro para a chave no vetor e para o nó no arquivo
 * Retorno:      Posição do livro no arquivo de dados ou -1 caso não encontre
 * Pré-condição: Chave existente
 * Pós-condição: Nenhuma
*/
int BMais::buscarChave(Chave chave){
    int i;
    int posChave;
    BMais aux;
    CabecalhoArvore cab = this->arquivo.lerCabecalhoArvore();
    aux.mudarNo(cab.raiz);
    for(i=0;i < aux.no.numChaves && !aux.no.ehFolha;i++){ //Percorrimento da árvore
        if(chave.info < aux.no.chave[i].info) //Vai para a esquerda
            aux.mudarNo(aux.no.filhos[i]);
        else if(i == aux.no.numChaves-1) //Vai para a direita
            aux.mudarNo(aux.no.filhos[i+1]);
    }
    if(aux.no.ehFolha){ //Achou o nó em que deveria estar a chave
        if(aux.buscarPos(chave.info,&posChave)){ //Achou a posição no vetor em que deveria estar a chave
            if(chave.info == aux.no.chave[posChave].info){ //Achou a chave
                return aux.no.chave[posChave].posLivro;
            }
        }
    }//Não achou a chave
    return -1;
}

/* Método que retorna a posição do folha mais à esquerda
 * Entrada:      Nenhuma
 * Retorno:      Posição da primeira folha no arquivo de nós ou -1 caso não tenha
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
*/
int BMais::pegarPrimeiraFolha(){
    BMais aux;
    CabecalhoArvore cab = this->arquivo.lerCabecalhoArvore();
    aux.no = this->arquivo.lerNo(cab.raiz);
    while(!aux.no.ehFolha){
        aux.mudarNo(aux.no.filhos[0]);
    }
    return aux.pos;
}

/* Métod que checa se um nó está em underflow
 * Entrada:      Nenhuma
 * Retorno:      True caso o nó esteja em uderflow ou False caso contrário
 * Pré-condição: Nó não nulo
 * Pós-condição: Nenhuma
*/
bool BMais::underflow(){
    return (this->no.numChaves < (ORDEM/2));
}

/* Método que arrasta tudo que está à direita de pos para pós no vetor de chaves
 * Entrada:      Posição que será apagada
 * Retorno:      Nenhum
 * Pré-condição: O nó que está sendo manipulado deve estar carregado na classe
 * Pós-condição: A chave na posição pos é retirada do vetor
*/
void BMais::arrastaPraEsquerda(int pos){
    int i;
    for(i=pos;i<this->no.numChaves-1;i++){
        this->no.chave[i] = this->no.chave[i+1];
    }
}

/* Método que remove uma chave de um nó folha
 * Entrada:      Chave a ser removida
 * Retorno:      Posição do livro no arquivo de livros da chave que foi removida
 * Pré-condição: Nó não nulo. Nó em que a chave será removida deve estar na classe
 * Pós-condição: A chave é removida do nó
*/
void BMais::removerChaveNaFolha(Chave chave){
    int posChave,posLivro;
    this->buscarPos(chave.info,&posChave);
    this->arrastaPraEsquerda(posChave);
    this->no.numChaves--;
    this->arquivo.escreverNo(this->no,this->pos);
}


/* Método que pega uma chave emprestada de um dos irmãos e coloca no nó atual
 * Entrada:      Nenhuma
 * Retorno:      Nenhum
 * Pré-condição: O nó com underflow deve estar carregado na classe. Pelo menos um dos irmãos deve poder
 *               Emprestar uma chave
 * Pós-condição: Uma chave é emprestada de um dos irmãos e as alterações necessárias são feitas
*/
void BMais::empresta(Chave chave){
    int posChave;
    BMais pai,esquerda,direita;
    pai.mudarNo(this->no.pai);
    if(pai.buscarPos(chave.info,&posChave)){ //Tem irmão à direita e à esquerda
        esquerda.mudarNo(pai.no.filhos[posChave]);
        direita.mudarNo(pai.no.filhos[posChave+2]);
        if(esquerda.no.numChaves > ORDEM/2){ //Pega emprestado do irmão à esquerda
            this->adicionarDireita(0,esquerda.no.chave[esquerda.no.numChaves-1],-1);
            esquerda.removerChaveNaFolha(esquerda.no.chave[esquerda.no.numChaves-1]);
            pai.no.chave[posChave] = this->no.chave[0];
            esquerda.arquivo.escreverNo(esquerda.no,esquerda.getPos());
        }else{ //Pega emprestado do irmão à direita
            this->adicionarDireita(this->no.numChaves,direita.no.chave[0],-1);
            direita.removerChaveNaFolha(direita.no.chave[0]);
            pai.no.chave[posChave+1] = direita.no.chave[0];
            direita.arquivo.escreverNo(direita.no,direita.getPos());
        }
    }else{
        direita.mudarNo(pai.no.filhos[posChave+1]);
        if(posChave != 0){ //Tem um nó à esquerda
            esquerda.mudarNo(pai.no.filhos[posChave-1]);
            if(esquerda.no.numChaves > ORDEM/2){
                this->adicionarDireita(0,esquerda.no.chave[esquerda.no.numChaves-1],-1);
                esquerda.removerChaveNaFolha(esquerda.no.chave[esquerda.no.numChaves-1]);
                pai.no.chave[posChave-1] = this->no.chave[0];
                esquerda.arquivo.escreverNo(esquerda.no,esquerda.getPos());
            }else{
                this->adicionarDireita(this->no.numChaves,direita.no.chave[0],-1);
                direita.removerChaveNaFolha(direita.no.chave[0]);
                pai.no.chave[posChave] = direita.no.chave[0];
                direita.arquivo.escreverNo(direita.no,direita.getPos());  
            }
        }else{ //Não tem nó à esquerda
            this->adicionarDireita(this->no.numChaves,direita.no.chave[0],-1);
            direita.removerChaveNaFolha(direita.no.chave[0]);
            pai.no.chave[posChave] = direita.no.chave[0];
            direita.arquivo.escreverNo(direita.no,direita.getPos());   
        }
    }
    pai.arquivo.escreverNo(pai.no,pai.getPos());
}

/* Método que remove uma chave na folha e corrige a folha que fica com underflow
 * Entrada:      Chave a ser removida
 * Retorno:      Nenhum
 * Pré-condição: O nó que sofrerá a remoção deve estar carregado na classe. 
 *               Ter um irmão com chave disponivel para emprestar
 * Pós-condição: A chave é removida da folha e os nós envolvidos são rearranjados
*/
void BMais::removerChaveNaFolhaComUnderflow(Chave chave){
    this->removerChaveNaFolha(chave);
    this->empresta(chave);
}

/* Arrasta todas as chaves à direita de pos para à esquerda, eliminando pos, arrumando os filhos
 * Entrada:      Posição a ser eliminada
 * Retorno:      Nenhum
 * Pré-condição: Nenhuma
 * Pós-condição: O elemento de pos é removido e o vetor rearranjado
*/
void BMais::arrastaPraEsquerdaComFilhos(int pos){
    int i;
    for(i=pos;i<this->no.numChaves-1;i++){
        this->no.chave[i] = this->no.chave[i+1];
        this->no.filhos[i+1] = this->no.filhos[i+2];
    }
}

/* Método que remove um chave que não está na folha durante o merge
 * Entrada:      Chave a ser removida
 * Retorno:      Nenhum
 * Pré-condição: Nó não nulo. Nó em que será a remoção deve estar carregado na classe
 * Pós-condição: A chave é removida do nó
*/
void BMais::removerChaveNaoFolhaNoMerge(Chave chave){
    int posChave,posLivro;
    this->buscarPos(chave.info,&posChave);
    this->arrastaPraEsquerdaComFilhos(posChave);
    this->no.numChaves--;
    this->arquivo.escreverNo(this->no,this->pos);
}

/* Método que concatena duas folhas, caso houver underflow
 * Entrada:      Nó que sofrerá merge e deixará de existir
 * Retorno:      Nenhum
 * Pré-condição: Somatório do número de chave dos dois nós não ser maior que ordem-1. Nós não nulos
 * Pós-condição: Nó recebido como parâmetro sofre merge com o nó carregado na classe e é removido
*/
void BMais::mergeFolha(BMais removido, Chave chave){
    int i;
    BMais pai;
    for(i=0;i<removido.no.numChaves;i++){
        this->no.chave[this->no.numChaves + i] = removido.no.chave[i];
    }
    this->no.filhos[ORDEM] = removido.no.filhos[ORDEM];
    pai.mudarNo(this->no.pai);
    pai.removerChaveNaoFolhaNoMerge(chave);
    this->no.numChaves += removido.no.numChaves;
    pai.arquivo.escreverNo(pai.no,pai.getPos());
    this->arquivo.escreverNo(this->no,this->getPos());
    this->cab = this->arquivo.lerCabecalhoArvore();
    removido.no.pai = this->cab.posLivre;
    this->cab.posLivre = removido.getPos();
    removido.arquivo.escreverNo(removido.no,removido.getPos());
    this->arquivo.escreverCabecalhoArvore(this->getCab());
}


/* Método que remove uma chave da folha que sofrerá merge
 * Entrada:      Chave a ser removida
 * Retorno:      Nenhum
 * Pré-condição: O nó que sofrerá a remoção deve estar carregado na classe.
 *               Nós não nulos.
 *               Deve haver nós possíveis para se fazer merge
 * Pós-condição: A chave é removida do nó
*/
void BMais::removerChaveNaFolhaComMerge(Chave chave){
    BMais pai,esquerda,direita,temp;
    int posChave,chaveARemoverNoPai;
    this->removerChaveNaFolha(chave);
    pai.mudarNo(this->no.pai);
    if(pai.buscarPos(chave.info,&posChave)){//this = posChave+1
        esquerda.mudarNo(posChave);
        direita.mudarNo(posChave+2);
        if(this->no.numChaves+esquerda.no.numChaves < ORDEM-1){
            temp.mudarNo(this->getPos());
            this->mudarNo(esquerda.getPos());
            this->mergeFolha(temp,chave);
        }else{
            this->mergeFolha(direita,chave);
        }
    }else{//this = posChave
        direita.mudarNo(posChave+1);
        if(posChave != 0){ //Tem irmão da esquerda
            esquerda.mudarNo(posChave-1);
            if(this->no.numChaves+esquerda.no.numChaves < ORDEM-1){
                temp.mudarNo(this->getPos());
                this->mudarNo(esquerda.getPos());
                this->mergeFolha(temp,temp.no.chave[0]);
            }else{
                this->mergeFolha(direita,temp.no.chave[0]);
            }
        }else{
            this->mergeFolha(direita,temp.no.chave[0]);
        }
    }
}

/* Método que faz o merge em dois nós internos
 * Entrada:      Nó que deixara de existir e sofrerá merge com o nó carregado em memória
 * Retorno:      Nenhum
 * Pré-condição: O nó que receberá o merge deve estar carregado na memória.
 *               O nó passado como parâmetro deve estar com underflow.
 *               Somatório do número de chave dos dois nós não ser maior que ordem-1
 * Pós-condição: O nó passado como parâmetro é copiado para o nó carregado e depois é apagado
*/
void BMais::mergeNaoFolha(BMais removido, Chave chave){
    int i;
    BMais pai;
    BMais filho;
    pai.mudarNo(this->no.pai);
    this->adicionarDireita(this->no.numChaves,pai.no.chave[0],-1);
    pai.removerChaveNaoFolhaNoMerge(chave);
    for(i=0;i<removido.no.numChaves;i++){
        this->no.chave[this->no.numChaves + i] = removido.no.chave[i];
        this->no.filhos[this->no.numChaves+i+1] = removido.no.filhos[i];
        filho.mudarNo(this->no.filhos[this->no.numChaves+i+1]);
        filho.no.pai = this->getPos();
        filho.arquivo.escreverNo(filho.no,filho.getPos());
    }
    this->no.numChaves += removido.no.numChaves;
    pai.arquivo.escreverNo(pai.no,pai.getPos());
    this->arquivo.escreverNo(this->no,this->getPos());
    this->cab = this->arquivo.lerCabecalhoArvore();
    removido.no.pai = this->cab.posLivre;
    this->cab.posLivre = removido.getPos();
    removido.arquivo.escreverNo(removido.no,removido.getPos());
    this->arquivo.escreverCabecalhoArvore(this->getCab());
}

/* Método auxiliar para remoção
 * Entrada:      Chave para remover e posição onde deveria estar a chave no vetor
 * Retorno:      Nenhum
 * Pré-condição: Nenhuma
 * Pós-condição: A chave é removida da árvore
*/
void BMais::removerAux(Chave chave){
    int posChave;
    int posChaveArquivo;
    if(this->buscarPos(chave.info,&posChave)){
        if(this->no.ehFolha){
            if(this->no.numChaves > ORDEM/2){
                this->removerChaveNaFolha(chave);
            }else{
                BMais pai,esquerda,direita;
                int posChaveAux;
                pai.mudarNo(this->no.pai);
                if(pai.buscarPos(chave.info,&posChaveAux)){ //this = posChave+1
                    esquerda.mudarNo(pai.no.filhos[posChaveAux]);
                    direita.mudarNo(pai.no.filhos[posChaveAux+2]);
                    if(esquerda.no.numChaves > ORDEM/2 || direita.no.numChaves > ORDEM/2){ //Empresta
                        this->removerChaveNaFolhaComUnderflow(chave);
                        printf("a\n");
                    }else{ //Merge na folha
                        if(esquerda.no.numChaves+this->no.numChaves-1 > ORDEM/2 || direita.no.numChaves+this->no.numChaves-1 > ORDEM/2 ){
                            this->removerChaveNaFolhaComMerge(chave);
                            printf("b\n");
                        }
                    }
                }else{ //this = posChave
                    direita.mudarNo(posChave+1);
                    if(posChave != 0){
                        esquerda.mudarNo(posChave-1);
                        if(esquerda.no.numChaves > ORDEM/2 || direita.no.numChaves > ORDEM/2){ //Empresta
                            this->removerChaveNaFolhaComUnderflow(chave);
                            printf("c\n");
                        }else{ //Merge na folha
                            if(esquerda.no.numChaves+this->no.numChaves-1 > ORDEM/2 || direita.no.numChaves+this->no.numChaves-1 > ORDEM/2 ){
                                this->removerChaveNaFolhaComMerge(chave);
                                printf("d\n");
                            }
                        }
                    }else{
                        if(direita.no.numChaves > ORDEM/2){ //Empresta
                            this->removerChaveNaFolhaComUnderflow(chave);
                            printf("e\n");
                        }else{ //Merge na folha
                            this->removerChaveNaFolhaComMerge(chave);
                            printf("fffff\n");
                        }
                    }
                }
            }
        }else{ //Descendo até a folha para remover e verificando underflow no nó interno
            int posChaveLocal,aux;
            aux = this->pos;
            this->buscarChave(chave,&posChaveLocal,&posChaveArquivo); 
            this->mudarNo(posChaveArquivo); //O nó folha que tem a chave
            this->removerAux(chave);
            this->mudarNo(aux); //Pai antes de pegar a folha
            if(this->underflow()){ //Faz merge interno
                BMais pai,esquerda,direita;
                pai.mudarNo(this->no.pai);
                if(pai.buscarPos(chave.info,&posChaveLocal)){ //this = posChave+1
                    esquerda.mudarNo(pai.no.filhos[posChave]);
                    direita.mudarNo(pai.no.filhos[posChave+2]);
                    if(this->no.numChaves + esquerda.no.numChaves < ORDEM-1){
                        esquerda.mergeNaoFolha(*this,chave);
                        printf("g\n");
                    }else if(this->no.numChaves + direita.no.numChaves < ORDEM-1){
                        direita.mergeNaoFolha(*this,chave);
                        printf("h\n");
                    }
                }else{
                    direita.mudarNo(posChave+1);
                    if(posChave != 0){
                        esquerda.mudarNo(posChave-1);
                        if(this->no.numChaves + esquerda.no.numChaves < ORDEM-1){
                            esquerda.mergeNaoFolha(*this,this->no.chave[0]);
                            printf("i\n");
                        }else if(this->no.numChaves + direita.no.numChaves < ORDEM-1){
                            direita.mergeNaoFolha(*this,this->no.chave[0]);
                            printf("j\n");
                        }
                    }else{
                        direita.mergeNaoFolha(*this,this->no.chave[0]);
                        printf("k\n");
                    }
                }
            }else{
                int posAux;
                BMais filhoAux;
                this->buscarPos(chave.info,&posAux);
                filhoAux.mudarNo(this->no.filhos[posAux+1]);
                this->no.chave[posAux] = filhoAux.no.chave[0];
                this->arquivo.escreverNo(this->no,this->pos);
                printf("l\n");
            }
        }
    }else{ //Pesquisando na árvore
        int posLocal;
        this->buscarPos(chave.info,&posLocal);
        this->mudarNo(this->no.filhos[posLocal]);
        this->removerAux(chave);
    }    
}


/* Método que remove uma chave da árvore
 * Entrada:      Chave a ser removida
 * Retorno:      Nenhum
 * Pré-condição: Nenhuma
 * Pós-condição: A chave é removida da árvore
*/
void BMais::remover(Chave chave){
    this->setCab(this->arquivo.lerCabecalhoArvore());
    if(this->cab.raiz != -1){//Árvore não é vazia
        this->mudarNo(this->getCab().raiz);
        this->removerAux(chave);
        this->mudarNo(this->getCab().raiz);
        if(this->no.numChaves == 0){
            this->no.pai = this->cab.posLivre;
            this->cab.posLivre = this->cab.raiz;
            this->arquivo.escreverNo(this->no,this->getPos());
            this->mudarNo(this->no.filhos[0]);
            this->cab.raiz = this->getPos();
            this->arquivo.escreverCabecalhoArvore(this->cab);
            this->arquivo.escreverNo(this->no,this->getPos());
        }
    }
}

//destrutor da classe
BMais::~BMais(){

}