#include <iostream>
#include <cstdlib>
#include <time.h>
#include <locale.h>
using namespace std;

int main()
{

    ///sistema de repetição para rodar em quanto ainda tiver dinheiro no valor acima de 0
    for(int dinheiro=10;dinheiro>0;){

    ///declaração randominica de 1 semente para 1 numero
    srand(time(NULL));


    char resposta;

    cout<<"\n________________________________________________________________________________________________________________________\n"<<endl;
    cout<<"                                     ----------Bem vindo--------"<<endl;
    cout<<"                                     -------------ao------------"<<endl;
    cout<<"                                     ----------BlackJack--------"<<endl;
    cout<<"\n________________________________________________________________________________________________________________________\n"<<endl;

    cout<<"\n                                    ----------Moedas ="<<dinheiro<<"----------\n"<<endl;
    cout<<"\nGostaria de uma jogar uma Partida? Custo 1 Moeda (s/n)"<<endl;
    cin>>resposta;


    ///caso o player recuse jogo sera encerrado
    if(resposta != 's'){
        break;
    }
    char r;

    if(resposta =='s'|| 'S'){

    ///declaração das cartas do player e dealer
        int carta1=rand()%10+1,carta2=rand()%10+1,soma;
        int dealer_carta1=rand()%10+1,SomaDealer;
        int dealer_carta2=rand()%10+1;

        SomaDealer=dealer_carta1+dealer_carta2;
        soma=carta1+carta2;

        cout<<"\nSuas cartas sao: "<<carta1<<" e "<<carta2<<" = "<<soma<<endl;
        cout<<"\nCarta Aberta do Dealer "<<dealer_carta1<<endl;



        ///se a soma do players estiver abaixo de 21 perguntar se quer mais 1 carta
        if(soma<21){

                cout<<"\nGostaria de pedir 1 nova carta? (s/n)"<<endl;
        cin>>r;


        ///enquanto a o jogador ainda responder sim
            do{


            ///se a resposta foi sim entregar 1 nova carta
            if(r =='s'){
            srand(time(NULL));
            int Nova_carta=rand()%10+1;

            if(Nova_carta ==1 && soma<10){

            Nova_carta=11;
            }


            soma=soma+Nova_carta;


            cout<<"\n________________________________________________________________________________________________________________________\n"<<endl;
            cout<<"\nnova carta: "<<Nova_carta<<endl;
            cout<<"\nSoma Total: "<<soma<<endl;

            ///se ainda estiver abaixo de 21 perguntar se quer outra carta
            if(soma<21){
            cout<<"\nGostaria de Outra carta? "<<endl;
            cin>>r;
            }
            }
             if(soma>21){
                cout<<"Voce estourou"<<endl;
                dinheiro=dinheiro-1;

                break;
            }else if(soma == 21){
            cout<<"BlackJack: Parabens Voce ganhou"<<endl;
            dinheiro=dinheiro+1;
              break;
                }
            }while(r=='s');

            ///se a resposta for diferente de Sim para outr carta
            ///ira rodar a entrega das cartas finais do dealer
                if (r !='s'){

            cout<<"Dealer abre sua Segunda carta: "<<dealer_carta2<<endl;
            SomaDealer=dealer_carta1+dealer_carta2;
            cout<<"\nSoma total Dealer: "<<SomaDealer<<endl;

            while(SomaDealer<17){
                    int dealer_carta3=rand()%10+1;
            SomaDealer +=dealer_carta3;
            cout<<"Nova carta dealer: "<<dealer_carta3<<endl;
            cout<<"Soma carta Dealer: "<<SomaDealer<<endl;

            }
            if( SomaDealer==soma){
                cout<<"Empate,Suas moedas foram devolvidas"<<endl;
            }else if(SomaDealer<=21 && SomaDealer>soma){
            cout<<"Voce Perdeu "<<endl;
            dinheiro=dinheiro-1;
            }else{
            cout<<"Voce ganhou "<<endl;
            dinheiro=dinheiro+1;
            }
            }
        }
    }
    }


    return 0;
}
