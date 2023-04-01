#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define N 100

void rodar_cobra_caixa();
void jogo_cobra_caixa();
void valorant_quiz();
int p1();
int p2();
int p3();
int p4();
int p5();

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	
	int escolha_usuario, status_jogo = 1;

	while(status_jogo == 1){
		
		
		printf("\n<<<<< MINI GAMES >>>>>\n\n");
		printf("Escolha o jogo que deseja jogar:\n");
		printf("1 - Pergunta e resposta\n");
		printf("2 - Cobra na caixa!\n");
		printf("3 - Sair\n");
	
		printf("Digite o numero de sua escolha: ");	
		scanf("%d", &escolha_usuario);	
		fflush(stdin);
		
		if(escolha_usuario == 1){
			valorant_quiz();
		}else if(escolha_usuario == 2){
			rodar_cobra_caixa();
		}else if(escolha_usuario == 3){
			printf("\nPrograma encerrado!\n");
			break;
		}else{
			printf("\nDigite apenas os numeros das ações correspondentes!\n\n\n");
		}
	}
	
	
	return 0;
}

void rodar_cobra_caixa(){
	char jogador1[N], jogador2[15];
	int inicia_jogando;
	
	printf("\n\n\n<<<<< COBRA NA CAIXA >>>>>\n");
	printf("Você e seu colega de trabalho estavam explorando a tumba do faraó Neebe quando \nentraram em uma grande sala com escrituras na parede. Enquanto inspecionavam as \nescrituras, vocês acidentalmente pressionaram um botão escondido que lacrou as \nportas, prendendo-os lá dentro.\n\n");
	printf("Então, cinco caixas apareceram no centro da sala, uma \ndelas contendo o botão para abrir as portas, mas uma delas contém uma cobra mortal!\n\n");
	printf("Vocês devem jogar alternando entre turnos para abrir uma caixa de cada vez, na esperança de não \nencontrar a cobra.\n\n");
	printf("Esse é um jogo de sorte, onde ganha o jogador que descobrir a caixa que contém o \nbotão e perde aquele que descobrir a caixa com a cobra.\n\n");
	
	printf("Digite seu primeiro nome Jogador 1: ");
	scanf("%s", jogador1);
	fflush(stdin);

	printf("Digite seu primeiro nome Jogador 2: ");	
	scanf("%s", jogador2);
	fflush(stdin);
	
	printf("\nJogador 1: %s\n", jogador1);
	printf("Jogador 2: %s\n\n", jogador2);
	
	inicia_jogando = rand() % 2;
	
	if(inicia_jogando == 0){
		printf("%s inicia!\n", jogador1);
		jogo_cobra_caixa(jogador1, jogador2);
	}else if(inicia_jogando == 1){
		printf("%s inicia!\n", jogador2);
		jogo_cobra_caixa(jogador2, jogador1);
	}
}

void jogo_cobra_caixa(char primeiro_jogador[15], char segundo_jogador[15]){
	
	int cobra = 0, botao = 0, escolha, status_jogo = 1, jogada = 1, vencedor;
	int caixas[5] = {0, 0, 0, 0, 0};
	
	while(cobra == botao){
		cobra = rand() % 5;	
		botao = rand() % 5;
	}
	
	printf("\n\nA caixa da cobra é %d\n\n", cobra);
	caixas[cobra] = 1;
	caixas[botao] = 2;
	
	
	while(1){
		
		if(jogada == 1){
			printf("\n%s escolha uma das 5 caixas: ", primeiro_jogador);
		}else{
			printf("\n%s escolha uma das 5 caixas: ", segundo_jogador);	
		}
		scanf("%d", &escolha);
		fflush(stdin);
		
		escolha = escolha - 1;
		
		if(caixas[escolha] == 0){
			printf("\n\nUFAA CAIXA VAZIA\n\n");
			caixas[escolha] = -1;
		}else if(caixas[escolha] == -1){
			printf("\n\nESSA CAIXA JA HAVIA SIDO ESCOLHIDA!\n\n");
		}else if(caixas[escolha] == 1){
			printf("\n\nCOBRAAAAAAAAAAAAA\n\n");
			if(jogada == 1){
				vencedor = 2;
			}else{
				vencedor = 1;
			}
			break;
		}else if(caixas[escolha] == 2){
			printf("\n\nBOTAOOOOOOO\n\n");
			if(jogada == 1){
				vencedor = 1;
			}else{
				vencedor = 2;
			}
			break;
		}else{
			printf("\nDigite um numero de 1 a 5 !\n");
		}
		
		if(jogada == 1){
			jogada = 2;
		}else{
			jogada = 1;
		}
	}
	
	if(vencedor == 1){
		printf("\n\n%s VENCEU!\n\n", primeiro_jogador);
	}else{
		printf("\n\n%s VENCEU!\n\n", segundo_jogador);
	}
}

void valorant_quiz(){
    int pontuacao = 0;
    printf("\n\n\n<<<<< VALORANT QUIZ >>>>>\n");
    pontuacao = p1(pontuacao);
    pontuacao = p2(pontuacao);
    pontuacao = p3(pontuacao);
    pontuacao = p4(pontuacao);
    pontuacao = p5(pontuacao);
    printf("\nSua pontuacao: %d\n\n", pontuacao);
  
}

int p1(int pontuacao){
    char pergunta[100] = "Quando Valorant foi lançado?";
    char opcao0[100] = "2 de junho de 2020",
    opcao1[100] = "4 de novembro de 2020", 
    opcao2[100] = "11 de julho de 2020", 
    opcao3[100] = "20 de agosto de 2021";
    int resposta_usuario, resposta_correta = 0;


    printf("\n%s", pergunta);
    printf(" \n0 - %s", opcao0);
    printf(" \n1 - %s", opcao1);
    printf(" \n2 - %s", opcao2);
    printf(" \n3 - %s", opcao3);
    printf(" \nEscolha uma opcao: \n");
    scanf("%d", &resposta_usuario);  
    fflush(stdin);
    while (resposta_usuario < 0 || resposta_usuario > 3)
    {
        printf("Opção inválida!\nDigite novamente:\n");
        scanf("%d", &resposta_usuario);
        fflush(stdin);
    }
    if (resposta_usuario == resposta_correta)
    {
        printf("Resposta correta!\n");
        return pontuacao + 1;
        
    }else
    {
        printf("Resposta errada!\nAlternativa correta: ");
        printf(opcao0);
        return pontuacao;
    }
}

int p2(int pontuacao){
    char pergunta[100] = "\nQual a nacionalidade da Neon?";
    char opcao0[100] = "Filipinas",
    opcao1[100] = "Tailandia", 
    opcao2[100] = "Portugal", 
    opcao3[100] = "Espanha";
    int resposta_usuario, resposta_correta = 0;


    printf("\n%s", pergunta);
    printf(" \n0 - %s", opcao0);
    printf(" \n1 - %s", opcao1);
    printf(" \n2 - %s", opcao2);
    printf(" \n3 - %s", opcao3);
    printf(" \nEscolha uma opcao: \n");
    scanf("%d", &resposta_usuario);  
    fflush(stdin);
    while (resposta_usuario < 0 || resposta_usuario > 3)
    {
        printf("Opção inválida!\nDigite novamente:\n");
        scanf("%d", &resposta_usuario);
        fflush(stdin);
    }
    if (resposta_usuario == resposta_correta)
    {
        printf("Resposta correta!\n");
        return pontuacao + 1;
        
    }else
    {
        printf("Resposta errada!\nAlternativa correta: ");
        printf(opcao0);
        return pontuacao;
    }
}

int p3(int pontuacao){
    char pergunta[100] = "\nOnde fica o mapa Breeze?";
    char opcao0[100] = "Cotijuba",
    opcao1[100] = "Estados unidos", 
    opcao2[100] = "Mosqueiro", 
    opcao3[100] = "Triangulo das bermudas";
    int resposta_usuario, resposta_correta = 3;


    printf("\n%s", pergunta);
    printf(" \n0 - %s", opcao0);
    printf(" \n1 - %s", opcao1);
    printf(" \n2 - %s", opcao2);
    printf(" \n3 - %s", opcao3);
    printf(" \nEscolha uma opcao: \n");
    scanf("%d", &resposta_usuario);  
    fflush(stdin);
    while (resposta_usuario < 0 || resposta_usuario > 3)
    {
        printf("Opção inválida!\nDigite novamente:\n");
        scanf("%d", &resposta_usuario);
        fflush(stdin);
    }
    if (resposta_usuario == resposta_correta)
    {
        printf("Resposta correta!\n");
        return pontuacao + 1;
        
    }else
    {
        printf("Resposta errada!\nAlternativa correta: ");
        printf(opcao3);
        return pontuacao;
    }
}

int p4(int pontuacao){
    char pergunta[100] = "\nQual é o único casal do Valorant?";
    char opcao0[100] = "Jett e Fenix",
    opcao1[100] = "Skye e Yoru", 
    opcao2[100] = "Raze e Killjoy", 
    opcao3[100] = "Sage e Omen";
    int resposta_usuario, resposta_correta = 2;


    printf("\n%s", pergunta);
    printf(" \n0 - %s", opcao0);
    printf(" \n1 - %s", opcao1);
    printf(" \n2 - %s", opcao2);
    printf(" \n3 - %s", opcao3);
    printf(" \nEscolha uma opcao: \n");
    scanf("%d", &resposta_usuario);  
    fflush(stdin);
    while (resposta_usuario < 0 || resposta_usuario > 3)
    {
        printf("Opção inválida!\nDigite novamente:\n");
        scanf("%d", &resposta_usuario);
        fflush(stdin);
    }
    if (resposta_usuario == resposta_correta)
    {
        printf("Resposta correta!\n");
        return pontuacao + 1;
        
    }else
    {
        printf("Resposta errada!\nAlternativa correta: ");
        printf(opcao2);
        return pontuacao;
    }
}

int p5(int pontuacao){
    char pergunta[100] = "\nQual é o tipo de Agente que é feito para abrir o bomb?";
    char opcao0[100] = "Sentinela",
    opcao1[100] = "Duelista", 
    opcao2[100] = "Controlador", 
    opcao3[100] = "Iniciador";
    int resposta_usuario, resposta_correta = 1;


    printf("\n%s", pergunta);
    printf(" \n0 - %s", opcao0);
    printf(" \n1 - %s", opcao1);
    printf(" \n2 - %s", opcao2);
    printf(" \n3 - %s", opcao3);
    printf(" \nEscolha uma opcao: \n");
    scanf("%d", &resposta_usuario);  
    fflush(stdin);
    while (resposta_usuario < 0 || resposta_usuario > 3)
    {
        printf("Opção inválida!\nDigite novamente:\n");
        scanf("%d", &resposta_usuario);
        fflush(stdin);
    }
    if (resposta_usuario == resposta_correta)
    {
        printf("Resposta correta!\n");
        return pontuacao + 1;
        
    }else
    {
        printf("Resposta errada!\nAlternativa correta: ");
        printf(opcao1);
        return pontuacao;
    }
}

