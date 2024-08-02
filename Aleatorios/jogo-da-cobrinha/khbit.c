#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

int kbhit() {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);  // Obtém configurações atuais do terminal
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);  // Desativa o buffering de linha e echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);  // Aplica as novas configurações
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);  // Obtém o status atual dos flags
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);  // Define o modo não-bloqueante

    ch = getchar();  // Tenta ler um caractere

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);  // Restaura configurações do terminal
    fcntl(STDIN_FILENO, F_SETFL, oldf);  // Restaura flags

    if(ch != EOF) {
        ungetc(ch, stdin);  // Coloca o caractere de volta no buffer
        return 1;  // Indica que uma tecla foi pressionada
    }

    return 0;  // Nenhuma tecla pressionada
}