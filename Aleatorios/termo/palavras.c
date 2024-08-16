#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void sortearPalavra(char palavra[6]) {
  srand(time(NULL));
    
    char *palavras[310] = {
        "amora", "pente", "trigo", "mundo", "prato", "barra", "noite", "focar", "dente",
        "cegar", "magia", "cesta", "bolsa", "corpo", "grito", "ritmo", "vinho", "salto",
        "firme", "pedra", "calor", "nobre", "haste", "folha", "pleno", "perda", "rosto",
        "curso", "gosto", "larva", "vento", "falta", "troca", "ponto", "livro", "carro",
        "garra", "sonho", "leite", "plano", "bravo", "valer", "pesco", "porta", "feira",
        "cerco", "chave", "fauna", "flora", "lento", "negar", "turma", "ombro", "verde",
        "sabia", "sabor", "morte", "pacto", "limpo", "palha", "feixe", "ruido", "cinco",
        "blusa", "viver", "tarde", "breve", "mosca", "feita", "pular", "calar", "longo",
        "aroma", "tensa", "solto", "lapso", "brisa", "pingo", "rival", "campo", "bicho",
        "piano", "surto", "fator", "lenda", "nuvem", "rever", "treze", "frota", "ganso",
        "linha", "lousa", "creme", "jarro", "fibra", "manta", "perto", "arroz", "ferro",
        "grupo", "banco", "pedir", "morfo", "jovem", "amplo", "nevea", "faixa", "gueto",
        "honra", "louco", "fenda", "burro", "passo", "queda", "obter", "caixa", "trama",
        "plumo", "lucro", "rocha", "volta", "feudo", "balsa", "conto", "manso", "morto",
        "cofre", "sutil", "haste", "aereo", "missa", "coeso", "farol", "calma", "fraco",
        "missa", "denso", "saira", "ameno", "bacia", "antro", "relva", "jarra", "pulso",
        "retro", "carma", "limpo", "frase", "linha", "prumo", "rubro", "saber", "conto",
        "casal", "senha", "coral", "fugir", "praga", "fruto", "lindo", "negar", "geral",
        "abrir", "leito", "clima", "suave", "claro", "traje", "danca", "suino", "junta",
        "vosso", "nariz", "feste", "terno", "lance", "terno", "folga", "natal", "foice",
        "vasco", "nobre", "gordo", "amigo", "brava", "alado", "mesmo", "larva", "citar",
        "parar", "farol", "notar", "fixar", "gente", "baixo", "vigor", "verde", "fraco",
        "duplo", "pasta", "venha", "porta", "fecho", "pisar", "terco", "linha", "trevo",
        "reino", "inato", "gesto", "lesto", "vasto", "trova", "veado", "sogra", "cenho",
        "vejam", "cifra", "feroz", "chato", "folha", "magro", "pacto", "sadio", "verde",
        "largo", "cisne", "notar", "porta", "viver", "haste", "velho", "lerdo", "guia",
        "fibra", "cheio", "dizer", "livro", "corpo", "clara", "parco", "senha", "nuvem",
        "marca", "cegar", "fazer", "prato", "troco", "morar", "moral", "risco", "sonho",
        "certa", "couro", "firma", "cenho", "vejao", "frear", "humor", "leigo", "corpo",
        "corvo", "lindo", "fonte", "feito", "parca", "vasto", "mesma", "super", "freio",
        "vento", "manso", "senha", "canto", "chato", "lerdo", "nuvem", "fruto", "manta"
    };

    char palavraSorteada[6], palavraEmMaiusculo[6];
    strcpy(palavraSorteada, palavras[rand() % (sizeof(palavras) / sizeof(palavras[0]))]);

    for (int i = 0; i < 5; i++) {
        palavraEmMaiusculo[i] = palavraSorteada[i] >= 97 && palavraSorteada[i] <= 122 ? palavraSorteada[i] - 32 : palavraSorteada[i];
    }
    
    strcpy(palavra, palavraEmMaiusculo);
}