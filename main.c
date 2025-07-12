#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

//opções do menu
char options(){
    printf("Selecione uma operação:\n");
    printf("1. Adição\n");
    printf("2. Subtração\n");
    printf("3. Multiplicação\n");
    printf("4. Divisão\n");
    printf("5. Sair\n");
    printf("Opção:\n");

    char a;
    scanf(" %c", &a);
    return a;
}

//functions utils

double add(double a, double b){
    return a+b;
}

double sub(double a, double b){
    return a-b;
}

double mul(double a, double b){
    return a * b;
}

double divi(double a, double b){
    return a / b;
}

bool operation(int op, char simbol){
    double fn, sn, resul;
    printf("Digite o primeiro número: ");
    scanf("%lf", &fn);
    printf("Digite o segundo número: ");
    scanf("%lf", &sn);

    if(op == 4 && sn == 0){ 
        printf("Erro: Divisão por zero não é permitida.\n");
        return 1;
    }
    switch (op){
        case 1:
            resul = add(fn, sn);
            break;
        case 2:
            resul = sub(fn, sn);
            break;
        case 3: 
            resul = mul(fn, sn);
            break;
        case 4:
            resul = divi(fn, sn);
    }

    printf("Resultado: %lf %c %lf = %lf\n", fn, simbol, sn, resul);
    
    return 0;
}

int new_operation(){
    while(true){
        printf("Deseja realizar outra operação? (s/n):\n");
        char a;
        scanf(" %c", &a);

        if(a == 's' || a == 'S') return 1;
        else if(a == 'n' || a == 'N') return 5;
        else {
            printf("Resposta inválida. Por favor, digite 's' para sim ou 'n' para não.\n");
        }
    }
}

//programa da calculadora
int program(){
    printf("===============================\n");
    printf("   Calculadora Simples\n");
    printf("===============================\n");

    char choice = options();
    char simbols[] = {' ', '+', '-', '*', '/'};

    bool f = true;

    while(f){
        f = 0;

        if(choice == '1' || choice == '2' || choice == '3' || choice == '4'){
            int op = choice-'0';
            if(operation(op, simbols[op])){
                f = true;
                new_operation();
            }
        }
        else if(choice == '5') return 5;
        else {
            f = true;
            printf("Erro: Escolha uma opção válida!\n");
            choice = options();   
        }
    }

    return new_operation();
}

//função main
int main(){
    setlocale(LC_ALL, "");

    //program run
    while(program() != 5){}

    printf("Obrigado por usar a calculadora! Até a próxima.\n");

    return 0;
}