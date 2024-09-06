#include <stdio.h>
#include <string.h>

typedef struct _Livro Livro;
struct _Livro {
  char isbn[14], titulo[31], autor[31];
};

int busca(Livro livros[], int qtd, char titulo[]) {
  for (int i = 0; i < qtd; i++) {
    if (strcmp(livros[i].titulo, titulo) == 0) {
      return i;
    }
  }
  return -1;
}

void descobreTitulos(Livro livros[], int qtd, char titulo[]) {
  int index = busca(livros, qtd, titulo);
  if (index == -1) {
    printf("Livro não encontrado\n");
  } else {
    for (int i = 0; i < qtd; i++) {
      if (strcmp(livros[i].autor, livros[index].autor) == 0) {
        printf("%s\n", livros[i].titulo);
      }
    }
  }
}

int main() {
  Livro livros[5] = {
    {"978-3-16", "Livro A", "Autor X"},
    {"978-1-23", "Livro B", "Autor Y"},
    {"978-0-12", "Livro C", "Autor X"},
    {"978-9-87", "Livro D", "Autor Z"},
    {"978-4-56", "Livro E", "Autor X"}
  };

  char tituloBusca[31] = "Livro C";
  descobreTitulos(livros, 5, tituloBusca);

  return 0;
}