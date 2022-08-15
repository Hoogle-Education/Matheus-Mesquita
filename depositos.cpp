#include <stdio.h>

float proximoInvestimento(float mensal, float salario, float inicial) {

  mensal += inicial;

  if (mensal > 0.1*salario) {
    return inicial;
  } else {
    return mensal;
  }

}

int main(){

  // criando variaveis
  float valor_inicial, salario;
  int nSemanas;
  
  // pedimos para digitar o salario
  printf("Digite o salario: ");
  scanf(" %f", &salario);
  
  // pediu para digitar o valor inicial
  printf("Digite o valor inicial: ");
  scanf(" %f", &valor_inicial);

  // validacao
  // se estourar um limite OU estourar o outro
  while(valor_inicial < 20.0 || valor_inicial > 0.1*salario){
    // informo o erro
    printf("Por favor digite um valor entre R$20.00 e R$%.2f\n", 0.1*salario);

    // peço para digitar novamente
    printf("Digite o valor inicial: ");
    scanf(" %f", &valor_inicial);    
  }

  // peço para digitar o numero de semanas
  printf("Digite o numero de semanas: ");
  scanf(" %d", &nSemanas);

  // começo com o total investido zerado
  float total = 0.0;

  // e meu primeiro deposito sera configurado depois
  float  deposito_mensal = 0.0;

  // estrutura basica de TODA estrutura de repetição
  // inicializacao
  // verificacao
  // atualizacao

  // int cont = 0; //inicialiazao

  // while(cont <= 10) { // verificao
  //   printf("O contador esta valendo %d\n", cont);
  //   cont++; // cont += 1 // atualizao
  // }

  // loop passando por cada valor de semana entre 
  // 1 e o numero de semanas
  int semana;
  for(semana = 1; semana <= nSemanas; semana++) {

    //  o mensal recebe o proprio valor do mensal + inicial
    deposito_mensal = proximoInvestimento(deposito_mensal, salario, valor_inicial);

    // total acumula o deposito mensal
    total += deposito_mensal; 

    // apresento o valor investido em cada semana
    printf("Semana %d : R$%.2f\n", semana, deposito_mensal);
  }

  // apresenta o valor total
  printf("Valor total a ser depositado: R$%.2f", total);

  return 0;
}