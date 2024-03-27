#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

char pedirDica(char letras_palavra[], char letras_acertadas[]) {
  int letra_aleatoria_invalida;
  char letra_aleatoria;

  srand(time(NULL));
  do {
    letra_aleatoria_invalida = 0;
    int indice_letra_aleatoria = rand() % (int)strlen(letras_palavra);
    letra_aleatoria = letras_palavra[indice_letra_aleatoria];
  
    for (int i = 0; i < (int)strlen(letras_palavra); i++) {
      if (tolower(letras_acertadas[i]) == letra_aleatoria) {
        letra_aleatoria_invalida++;
      }
    }
  } while(letra_aleatoria_invalida != 0);  

  return letra_aleatoria;
}

int verificarRepetida(char letra, char letras_erradas[], int erros) {

  for (int i = 0; i < erros; i++) {
    if (letra == letras_erradas[i]) {
      return 1;
    }
  }

  return 0;  
}

void verificarLetraNaPalavra(char letra, char letras_palavra[], char letras_acertadas[], char letras_erradas[], int erros) {
  int acertou = 0;

  for (int i = 0; i < (int)strlen(letras_palavra); i++) {
      if (tolower(letra) == letras_palavra[i]) {
          letras_acertadas[i] = toupper(letra);
          acertou++;
      }
  }

  if (acertou == 0 && !verificarRepetida(toupper(letra), letras_erradas, erros)) {
    letras_erradas[erros] = toupper(letra);
  }
}

void contarErros(char letras_erradas[], int *erros) {
  int erros_atuais = 0;

  for (int i = 0; i < 6; i++) {
    if (letras_erradas[i] != ' ') {
      erros_atuais++;
    }
  }

  *erros = erros_atuais;
}

void printarBonequinho(int erros, char letras_erradas[]) {
  char letras_erradas_string[13] = "";
  for (int i = 0; i < 12; i++) {
    if (i%2 == 0) {
      letras_erradas_string[i] = letras_erradas[i/2];
    } else {
      letras_erradas_string[i] = ' ';
    }
  }

  printf(">>>>>>> Jogo da Forca <<<<<<<\n\n");

  switch(erros) {
    case 0:
      printf(" ______\n |    |        %s\n |\n |\n |\n |\n |             ", letras_erradas_string);
      break;
    case 1:
      printf(" ______\n |    |        %s\n |    O\n |\n |\n |\n |             ", letras_erradas_string);  
      break;
    case 2:
      printf(" ______\n |    |        %s\n |    O\n |    |\n |    |\n |\n |             ", letras_erradas_string); 
      break;
    case 3:
      printf(" ______\n |    |        %s\n |    O\n |   /|\n |    |\n |\n |             ", letras_erradas_string);
      break;
    case 4:
      printf(" ______\n |    |        %s\n |    O\n |   /|\\ \n |    |\n |\n |             ", letras_erradas_string);
      break;
    case 5:
      printf(" ______\n |    |        %s\n |    O\n |   /|\\ \n |    |\n |   /\n |             ", letras_erradas_string); 
      break;
    case 6:
      printf(" ______\n |    |        %s\n |    O\n |   /|\\ \n |    |\n |   / \\ \n |             ", letras_erradas_string); 
      break;
  }
}

void printarPalavra(char* palavra_aleatoria, char letras_acertadas[]) {
  for (int i = 0; i < (int)strlen(palavra_aleatoria); i++) {
    printf("%c ", letras_acertadas[i]);
  }  
}

char pedirLetra(char letras_palavra[], char letras_acertadas[], int *dicas_restantes) {
  char letra;
  printf("\n\n");
  if (*dicas_restantes > 0) {
    printf("(insira 0 para receber uma letra da palavra)\n");
  }
  printf("Insira uma letra: ");
  scanf(" %c", &letra); 

  if (letra == '0' && *dicas_restantes > 0) {
    (*dicas_restantes)--;
    letra = pedirDica(letras_palavra, letras_acertadas);
  } else if (letra == '0' && *dicas_restantes == 0) {
    return ' ';
  }

  return letra;
}

int main() {
  int erros = 0;
  char* lista_palavras[] = {"casa", "arvore", "carro", "bola", "gato", "cachorro", "livro", "mesa", "caneta", "chuva", "sol", "mar", "vento", "praia", "montanha", "rio", "telefone", "computador", "papel", "copo", "porta", "janela", "cadeira", "corrente", "lampada", "chave", "chuva", "sapato", "estrada", "pedra", "terra", "folha", "flor", "maquina", "fruta", "panela", "lapis", "borracha", "escola", "pessoa", "pote", "garfo", "faca", "prato", "tigela", "garrafa", "fogo", "terra", "arvore", "terra", "fogo", "pedra", "rio", "lago", "ponte", "piscina", "pneu", "cama", "cobertor", "travesseiro", "almofada", "armario", "espelho", "brinquedo", "dinheiro", "banco", "caixa", "cofre", "telefone", "celular", "tablet", "escova", "espuma", "escada", "sabonete", "toalha", "cabelo", "unha", "mao", "barriga", "braco", "perna", "cabeca", "orelha", "nariz", "boca", "vermelho", "verde", "azul", "amarelo", "rosa", "laranja", "roxo", "marrom", "preto", "branco", "cinza", "teclado", "lasanha", "pizza", "carne", "vaca", "galinha", "porco", "banana", "maca", "pessego", "comida", "alimento", "morte", "vida", "felicidade", "tristeza", "amor", "programar", "sorte", "aleatorio", "monitor", "tela", "palavra", "termo", "jogo", "bicicleta", "aviao", "chocolate", "relogio", "casaco", "piano", "cachecol", "radio", "musica", "feliz", "triste", "calor", "lua", "estrela", "futebol", "basquete", "volei", "nadar", "dancar", "dormir", "acordar", "correr", "andar", "divertido", "brincar", "trabalhar", "trabalho", "amigo", "amiga", "bolo", "suco", "pao", "leite", "cha", "biscoito", "macarrao", "sorvete", "doce", "salgado", "odio", "alegria", "medo", "saudade", "esperanca", "paz", "guerra", "amizade", "inimigo", "familia", "companheiro", "companheira", "irmao", "irma", "pai", "mae", "primo", "prima", "avo", "tio", "tia", "filho", "filha", "neto", "neta", "genro", "nora", "padrinho", "madrinha", "vizinho", "vizinha", "colega", "professor", "professora", "aluno", "aluna", "medico", "engenheiro", "advogado", "programador", "artista", "musico", "escritor", "pintor", "chef", "jardineiro", "padeiro", "policial", "bombeiro", "vendedor", "garcom", "motorista", "piloto", "macaco", "girafa", "elefante", "leao", "tigre", "urso", "passaro", "peixe", "tubarao", "tartaruga", "polvo", "camera", "veleiro", "abacaxi", "tenis", "brinco", "caneca", "grande", "pequeno", "alto", "baixo", "gordo", "magro", "cabeludo", "careca", "velho", "novo", "jovem", "idoso", "feio", "bonito", "simpatico", "antipatico", "educado", "generoso", "egoista", "corajoso", "medroso", "otimista", "pessimista", "curioso", "preocupado", "criativo", "racional", "alegre", "enorgico", "preguicoso", "paciente", "impaciente", "calmo", "agitado", "organizado", "baguncado",  "silencioso", "barulhento", "lento", "rapido", "delicado", "rude", "azedo", "picante", "amargo", "macio", "aspero", "quente", "frio", "claro", "escuro", "ensolarado", "nublado", "chuvoso", "gelado", "umido", "seco", "limpo", "sujo", "cheio", "vazio", "aberto", "fechado", "longe", "perto", "caro", "barato", "positivo", "negativo"};
  srand(time(NULL));
  int indice_aleatorio = rand() % sizeof(lista_palavras)/sizeof(lista_palavras[0]);
  int dicas_restantes = 1;
  char palavra_aleatoria[12];
  strcpy(palavra_aleatoria, lista_palavras[indice_aleatorio]);

  char letras_palavra[strlen(palavra_aleatoria)],
        letras_acertadas[strlen(palavra_aleatoria)],
        letras_erradas[6] = {' ', ' ', ' ', ' ', ' ', ' '};
  for (int i = 0; i < (int)strlen(palavra_aleatoria); i++) {
    letras_palavra[i] = palavra_aleatoria[i];
    letras_acertadas[i] = '_';
  }

  system(CLEAR);
  while (erros < 6 && strchr(letras_acertadas, '_') != NULL) {
    printarBonequinho(erros, letras_erradas);
    printarPalavra(palavra_aleatoria, letras_acertadas);
    verificarLetraNaPalavra(pedirLetra(letras_palavra, letras_acertadas, &dicas_restantes), letras_palavra, letras_acertadas, letras_erradas, erros);
    contarErros(letras_erradas, &erros);
    system(CLEAR);
  }

  if (erros == 6) {
    contarErros(letras_erradas, &erros);
    printarBonequinho(erros, letras_erradas);
    printarPalavra(palavra_aleatoria, letras_acertadas);
    printf("\n\nPoxa... A palavra era \"%s\"", palavra_aleatoria);
  } else {
    printarBonequinho(erros, letras_erradas);
    printarPalavra(palavra_aleatoria, letras_acertadas);
    printf("\n\nParabéns, você ganhou! A palavra era \"%s\"", palavra_aleatoria);
  }

  return 0;
}