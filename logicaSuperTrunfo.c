#include <stdio.h>
#include <string.h>


 char estados[] = {'A','B'};// array com as letras pra formar o codigo do estado
 int indice = 0; // variavel para Contar as posiçoes dos arrays e adicionar e salvar as cartas   
 

 typedef struct { //variaveis usando o comando struct que serve pra juntar as informaçoes ao invez de separa-las
    char estado;
    char cidade[50];
    unsigned int populacao;
    float area;
    float pib;
    int pontosturisticos;
    char codigo[5];
    float densidade;
    float pibpercapita;
    unsigned int poder;

}cartas;

void entradados(cartas carta[2]){ // função para a entrada dos dados 
    

 //laço for duplo que acabei de descobri, feito pra por os codigos da carta e pegar informaçoes das cartas
 for(int i = 0; i < 2; i++) {
      /*descobri essa função chamada sprintf que 
      mostra a informação na tela mas tambem salva em string*/
      // aqui é para pedir os dados das cartas
      //usei o fgets para ler strings com espaços

      carta[indice].estado = estados[i];

      sprintf(carta[indice].codigo, "%c%02d", estados[i], i + 1);


      printf("Digite o nome da cidade: \n");
      fgets(carta[indice].cidade, sizeof(carta[indice].cidade), stdin);
      carta[indice].cidade[strcspn(carta[indice].cidade, "\n")] = '\0'; // Remove o caractere de nova linha lido pelo fgets

      printf("Qual a população da cidade?: \n");
      scanf("%u", &carta[indice].populacao);

      getchar(); // Limpa o buffer do teclado

      printf("Qual a area em KM² da cidade?: \n");
      scanf("%f", &carta[indice].area);
            
      getchar(); // Limpa o buffer do teclado

      printf("Digite o PIB: \n");
      scanf("%f", &carta[indice].pib);
            
      getchar(); // Limpa o buffer do teclado

      printf("Numero de pontos turísticos?: \n");
      scanf("%d", &carta[indice].pontosturisticos);
 
      getchar(); // Limpa o buffer do teclado 
       
      indice++; // incrementa o indice para a próxima carta
        
    }
  }

void calculos(cartas carta[2]){ //função para fazer os cálculos necessários
     
    for(int k = 0; k < 2; k++) { 

      //calculo da densidade populacional
      carta[k].densidade = (float)carta[k].populacao / carta[k].area;

     //calculo do pib per capita
      carta[k].pibpercapita = (float)carta[k].pib / carta[k].populacao;

      // calcula o poder total da carta
      carta[k].poder = carta[k].pib + carta[k].area + carta[k].pibpercapita + carta[k].pontosturisticos + carta[k].densidade / 1;
  }
}
 
void saidadados(cartas carta[2]){ //chama a função para mostrar os dados
        
   //mostrar as cartas cadastradas     
   printf("\nCartas cadastradas:\n");

  for(int k = 0; k < 2; k++) { 

   printf("Estado: %c \n", carta[k].estado);  
   printf("Código: %s \n", carta[k].codigo);
   printf("Cidade: %s \n", carta[k].cidade);
   printf("População: %u \n", carta[k].populacao);
   printf("Área: %.2f KM² \n", carta[k].area);
   printf("PIB: %.2f \n", carta[k].pib);
   printf("Pontos Turísticos: %d \n", carta[k].pontosturisticos);
   printf("Densidade Populacional é : %.2f \n", carta[k].densidade);
   printf("Pib per capta é: %.2f \n", carta[k].pibpercapita);
   printf("o nivel de poder total é: %u \n", carta[k].poder);
   printf("-------------------------\n");  
 }
}


 void comparar(cartas carta[2]){
  
   if (carta[0].poder > carta[1].poder){
    printf("A carta 1 tem mais poder que a carta 2! Carta 1 Venceu!!!!");

  }
  else if (carta[0].poder < carta[1].poder)
  { 
    printf("A carta 2 tem mais poder que a carta 1! Carta 2 Venceu!!!!");
  }
  else{
    printf("Empatou!!!");     
  }
 }



int main(){  
    cartas carta[2];
    entradados(carta);
    calculos(carta);
    saidadados(carta);
    comparar(carta);
    return 0;
};

//fim do código}
  
