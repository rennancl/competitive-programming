#include <stdio.h>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

char competidores[20][4];
int card_count[13];

int _order(char card){
    if(card == 'A'){
        return 0;
    }
    if(card == '2'){
        return 1;
    }
    if(card == '3'){
        return 2;
    }
    if(card == '4'){
        return 3;
    }
    if(card == '5'){
        return 4;
    }
    if(card == '6'){
        return 5;
    }
    if(card == '7'){
        return 6;
    }
    if(card == '8'){
        return 7;
    }
    if(card == '9'){
        return 8;
    }
    if(card == 'D'){
        return 9;
    }
    if(card == 'Q'){
        return 10;
    }
    if(card == 'J'){
        return 11;
    }
    if(card == 'K'){
        return 12;
    }
    if(card == 'C'){
        return 13;
    }
    return 0;
}

int main(){
    int n, primeiro;
    char c;
    scanf(" %d %d\n", &n, &primeiro);
    for(int i = 0; i < n; i++){
        for(int k = 0; k < 4; k++){
            scanf(" %c", &c);
            competidores[i][k] = c;
        }
        scanf("*c");
    }

    char deck[14] = "A23456789DQJK";
    char card = 'C';
    int card_index = 0;
    int jogador_com_coringa = primeiro;
    int p = primeiro;
    int menor = 1000;
    while(1){
        char cardAux = card;
        //acha a carta a ser removida
        for(int i = 0; i < 13; i++) card_count[i] = 0;
        for(int i = 0; i < 4; i++){
            card_count[_order(competidores[p - 1][i])]++;
        }
        if(cardAux != 'C') card_count[_order(cardAux)]++;
        for(int i = 0; i < 13; i++){
            if(card_count[i] and card_count[i] < menor){
                menor = card_count[i];
                card = deck[i];
            }
        }
        if(cardAux != 'C'){
            for(int i = 0; i < 4; i++){
                if(competidores[p - 1][i] == 'C'){
                    card = 'C';
                }
            }
        }else{
            jogador_com_coringa = p;
        }

        //insere a carta que recebeu
        for(int i = 0; i < 4; i++){
            if(competidores[p - 1][i] == card){
                competidores[p - 1][i] = cardAux;
                break;
            }
        }

        //verifica quem ganhou
        for(int i = 0; i < n; i++){
            for(int i = 0; i < 13; i++) card_count[i] = 0;
            for(int k = 0; k < 4; k++){
                card_count[_order(competidores[i][k])]++;
            }
            if(card_count[_order(competidores[i][0])] == 4 and i + 1 != jogador_com_coringa ){
                std::cout << i + 1 << std::endl;
                return 0;
            }
        }
        menor = 1000;
        if(p == n) p = 1; else p++;
    }
    return 0;
}