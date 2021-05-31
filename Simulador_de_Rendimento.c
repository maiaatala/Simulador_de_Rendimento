#include <stdio.h>
#include <stdlib.h> //for system ('cls');
#include <math.h>   //for pow

/* programa para calcular
valor acumulado em rendimento
sob depósitos mensais, como a poupança */

float calculo_valor_ac(float aplicacao, float tx, int m)
{
    float   va;
    //formula utilizada para calcular o valor acumulado da aplicação
    va  =   (aplicacao*(pow((1+tx),m)-1))/tx;

    return  (va);
}

void simulador_de_rendimento()
{
    //declaração de variaveis
    float   valor_ac, v_aplicacao, taxa;
    int     meses;

    //entrada de dados
    printf  ("\nInsira o valor a ser aplicado mensalmente: ");
    scanf   ("%f", &v_aplicacao);
    printf  ("Insira a taxa mensal em %% (o valor sera dividido por 100): ");
    scanf   ("%f", &taxa);
    printf  ("Insira a quantidade de meses da aplicacao: ");
    scanf   ("%i", &meses);

    //processamento de dados
    taxa        = taxa/100;
    valor_ac    = calculo_valor_ac(v_aplicacao,taxa,meses);

    //saida de dados
    printf  ("\n-=x=-=x=-=x=-=x=-=x=-=x=-=x=-=x=-=x=-=x=-\n");
    printf  ("O valor acumulado e: %5.2f reais\n", valor_ac);
    printf  ("O valor do rendimento e de: %5.2f reais \n", valor_ac - v_aplicacao*meses);  //para mostrar apenas foi ganho atravez da taxa
    printf  ("-=x=-=x=-=x=-=x=-=x=-=x=-=x=-=x=-=x=-=x=-\n");

}

void credits()
{
    //printf  (":--------------+--------------------:\n");
    printf  ("| Obrigada por utilizar o programa. |\n");
    printf  (":--------------+--------------------:\n");
    printf  ("| Autor:       | Ana Atala          |\n");
    printf  (":--------------+--------------------:\n");
    printf  ("| Data:        | Maio 28, 2021      |\n");
    printf  (":--------------+--------------------:\n");
    printf  ("| Materia:     | Lab Programacao I  |\n");
    printf  (":--------------+--------------------:\n");
    printf  ("| Faculdade:   | Unemat             |\n");
    printf  (":--------------+--------------------:\n\n");    
}

int main()
{
    //declaração de variaveis
    char    escolha;

    //intro do programa
    //system  ("cls"); //lipar tela do cmd;
    printf  ("\nPrograma para calcular o valor acumulado em aplicacoes mensais com rendimento %% ao mes\n");
    printf  ("--------------------------------------------------------------------------------------\n");

    //Loop do programa
    /* loop repete enquanto o usuario escolher que sim ('s')
    possibilitando a reutilizaçao do programa */
    do
    {
        simulador_de_rendimento();
        printf  ("\nDeseja simular outros valores para aplicacao mensal? (s/n): ");
        scanf   (" %c", &escolha);  //o espaco é para o programa ignorar white spaces
        printf  ("\n-------------------------------------\n");
    }while((escolha == 's')||(escolha == 'S')); //C is case sensitive

    //Credits
    credits();
    system  ("pause");
    return  (0);
}