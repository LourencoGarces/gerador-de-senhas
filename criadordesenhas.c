/*
Claro! Um gerador de senhas é um programa que cria senhas aleatórias de acordo com critérios estabelecidos pelo usuário. 
O objetivo é fornecer senhas seguras e únicas que possam ser usadas em diversas contas e serviços.

Aqui está uma descrição geral de como você pode implementar um gerador de senhas em C:

Defina os critérios: No início do programa, você pode solicitar ao usuário os critérios para a senha, como comprimento mínimo e máximo,
e se a senha deve incluir caracteres especiais, letras maiúsculas, letras minúsculas e números.

Crie um conjunto de caracteres: Com base nos critérios fornecidos, você pode criar um conjunto de caracteres válidos que serão usados para gerar
a senha. Esse conjunto pode incluir letras maiúsculas, letras minúsculas, números e caracteres especiais, dependendo das preferências do usuário.

Gere a senha: Utilize uma função de geração de números aleatórios em C para selecionar caracteres aleatórios do conjunto criado.
Repita esse processo até atingir o comprimento desejado para a senha.

Valide a senha: É uma boa prática verificar se a senha gerada atende aos critérios definidos pelo usuário. 
Verifique se a senha contém pelo menos um caractere de cada tipo especificado (letras maiúsculas, letras minúsculas, números, caracteres especiais)
e se seu comprimento está dentro do intervalo definido.

Exiba a senha: Após gerar uma senha válida, você pode exibi-la ao usuário. Certifique-se de que a senha seja exibida de forma segura, 
por exemplo, usando asteriscos ou pontos para ocultar os caracteres.

Lembre-se de que a segurança das senhas é um aspecto importante ao criar um gerador de senhas. 
Certifique-se de fornecer uma opção para que o usuário escolha senhas fortes e encoraje o uso de critérios robustos para criar senhas mais seguras.

Com essas etapas básicas, você pode começar a desenvolver um gerador de senhas em C. À medida que você se aprofundar na implementação,
poderá adicionar recursos adicionais, como a capacidade de salvar as senhas geradas em um arquivo ou permitir que o usuário gere várias
senhas de uma vez.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void criterios(int *maiusculas_comfirmacao, int *minusculas_comfirmacao, int *numeros_comfirmacao, int *especiais_comfirmacao) {
    char maiusculas, minusculas, numeros, especiais;
    printf("Digite se deseja letras maiúsculas (S/N): ");
    scanf(" %c", &maiusculas);
    getchar(); // Consumir nova linha pendente

    printf("\nDigite se deseja letras minúsculas (S/N): ");
    scanf(" %c", &minusculas);
    getchar(); // Consumir nova linha pendente

    printf("\nDigite se deseja números (S/N): ");
    scanf(" %c", &numeros);
    getchar(); // Consumir nova linha pendente

    printf("\nDigite se deseja caracteres especiais (S/N): ");
    scanf(" %c", &especiais);
    getchar(); // Consumir nova linha pendente

    if (maiusculas == 'S' || maiusculas == 's') {
        *maiusculas_comfirmacao = 1;
    } else if (minusculas == 'S' || minusculas == 's') {
        *minusculas_comfirmacao = 1;
    } else if (numeros == 'S' || numeros == 's') {
        *numeros_comfirmacao = 1;
    } else if (especiais == 'S' || especiais == 's') {
        *especiais_comfirmacao = 1;
    }
}

void gerador_senha(){
    srand(time(NULL));
    int tamanho, opcao, i;int maiusculas_comfirmacao = 0;
    int minusculas_comfirmacao = 0;
    int numeros_comfirmacao = 0;
    int especiais_comfirmacao = 0;
    char caracteres_final[73] = "";
    char caracteres_letras[27] = "abcdefghijklmnopqrstuvwxyz";
    char caracteres_letras_maiusculas[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char caracteres_numeros[11] = "0123456789";
    char caracteres_especiais[11] = "!@#$&*()_+";
    char senha[100];

    criterios(&maiusculas_comfirmacao, &minusculas_comfirmacao, &numeros_comfirmacao, &especiais_comfirmacao);

    printf("Digite o tamanho da senha: ");
    scanf("%d", &tamanho);

    if (maiusculas_comfirmacao == 1 && minusculas_comfirmacao == 1 && numeros_comfirmacao == 1 && especiais_comfirmacao == 1)
    {
        strcat(caracteres_letras, caracteres_letras_maiusculas);
        strcat(caracteres_letras, caracteres_numeros);
        strcat(caracteres_letras, caracteres_especiais);
        strcat(caracteres_final, caracteres_letras);
    }
    else if (maiusculas_comfirmacao == 0 && minusculas_comfirmacao == 1 && numeros_comfirmacao == 1 && especiais_comfirmacao == 1)
    {
        strcat(caracteres_letras, caracteres_numeros);
        strcat(caracteres_letras, caracteres_especiais);
        strcat(caracteres_final, caracteres_letras);
    }
    else if (maiusculas_comfirmacao == 0 && minusculas_comfirmacao == 0 && numeros_comfirmacao == 1 && especiais_comfirmacao == 1)
    {
        strcat(caracteres_letras, caracteres_especiais);
        strcat(caracteres_final, caracteres_letras);
    }
    else if (maiusculas_comfirmacao == 0 && minusculas_comfirmacao == 0 && numeros_comfirmacao == 0 && especiais_comfirmacao == 1)
    {
        strcat(caracteres_final, caracteres_especiais);
    }
    else if (maiusculas_comfirmacao == 0 && minusculas_comfirmacao == 0 && numeros_comfirmacao == 0 && especiais_comfirmacao == 0)
    {
        printf("A senha não pode ser gerada!\n");
    }
    else if (maiusculas_comfirmacao == 1 && minusculas_comfirmacao == 0 && numeros_comfirmacao == 0 && especiais_comfirmacao == 0)
    {
        strcat(caracteres_final, caracteres_letras_maiusculas);
    }
    else if (maiusculas_comfirmacao == 1 && minusculas_comfirmacao == 1 && numeros_comfirmacao == 0 && especiais_comfirmacao == 0)
    {
        strcat(caracteres_letras, caracteres_letras_maiusculas);
        strcat(caracteres_final, caracteres_letras);
    }
    else if (maiusculas_comfirmacao == 1 && minusculas_comfirmacao == 1 && numeros_comfirmacao == 1 && especiais_comfirmacao == 0)
    {
        strcat(caracteres_letras, caracteres_letras_maiusculas);
        strcat(caracteres_letras, caracteres_numeros);
        strcat(caracteres_final, caracteres_letras);
    }
    else if (maiusculas_comfirmacao == 0 && minusculas_comfirmacao == 1 && numeros_comfirmacao == 0 && especiais_comfirmacao == 1)
    {
        strcat(caracteres_letras, caracteres_especiais);
        strcat(caracteres_final, caracteres_letras);
    }
    else if (maiusculas_comfirmacao == 0 && minusculas_comfirmacao == 1 && numeros_comfirmacao == 1 && especiais_comfirmacao == 0)
    {
        strcat(caracteres_letras, caracteres_numeros);
        strcat(caracteres_final, caracteres_letras);
    }
    else if (maiusculas_comfirmacao == 0 && minusculas_comfirmacao == 0 && numeros_comfirmacao == 1 && especiais_comfirmacao == 0)
    {
        strcat(caracteres_final, caracteres_numeros);
    }
    else if (maiusculas_comfirmacao == 1 && minusculas_comfirmacao == 0 && numeros_comfirmacao == 1 && especiais_comfirmacao == 0)
    {
        strcat(caracteres_letras, caracteres_letras_maiusculas);
        strcat(caracteres_letras, caracteres_numeros);
        strcat(caracteres_final, caracteres_letras);
    }
    else if (maiusculas_comfirmacao == 1 && minusculas_comfirmacao == 0 && numeros_comfirmacao == 0 && especiais_comfirmacao == 1)
    {
        strcat(caracteres_letras, caracteres_letras_maiusculas);
        strcat(caracteres_letras, caracteres_especiais);
        strcat(caracteres_final, caracteres_letras);
    }
    else if (maiusculas_comfirmacao == 0 && minusculas_comfirmacao == 1 && numeros_comfirmacao == 0 && especiais_comfirmacao == 0)
    {
        strcat(caracteres_final, caracteres_letras);
    }
    else if (maiusculas_comfirmacao == 0 && minusculas_comfirmacao == 1 && numeros_comfirmacao == 1 && especiais_comfirmacao == 0)
    {
        strcat(caracteres_letras, caracteres_numeros);
        strcat(caracteres_final, caracteres_letras);
    }
    else if (maiusculas_comfirmacao == 0 && minusculas_comfirmacao == 1 && numeros_comfirmacao == 1 && especiais_comfirmacao == 1)
    {
        strcat(caracteres_letras, caracteres_numeros);
        strcat(caracteres_letras, caracteres_especiais);
        strcat(caracteres_final, caracteres_letras);
    }
    else if (maiusculas_comfirmacao == 1 && minusculas_comfirmacao == 1 && numeros_comfirmacao == 0 && especiais_comfirmacao == 1)
    {
        strcat(caracteres_letras, caracteres_letras_maiusculas);
        strcat(caracteres_letras, caracteres_especiais);
        strcat(caracteres_final, caracteres_letras);
    }
    else if (maiusculas_comfirmacao == 1 && minusculas_comfirmacao == 1 && numeros_comfirmacao == 1 && especiais_comfirmacao == 1)
    {
        strcat(caracteres_letras, caracteres_letras_maiusculas);
        strcat(caracteres_letras, caracteres_numeros);
        strcat(caracteres_letras, caracteres_especiais);
        strcat(caracteres_final, caracteres_letras);
    }

    printf("%s\n", caracteres_final);
    for (i = 0; i < tamanho; i++) {
        senha[i] = caracteres_final[rand() % strlen(caracteres_final)];
    }

    printf("A senha gerada é: %s\n", senha);
    
}

void menu(int *opcao){
    printf("1- Gerar senha\n");
    printf("2- Sair\n");
    printf("Digite a opção desejada: ");
    scanf("%d", opcao);
}

int main(){
    int opcao;
    while (1){
        menu(&opcao);
        switch(opcao){
            case 1:
                gerador_senha();
                break;
            case 2:
                printf("Obrigado por usar o gerador de senhas!\n");
                exit(0);
                break;        
            default:
                printf("Opção inválida!\n");
                break;
        }
    }
    return 0;
}