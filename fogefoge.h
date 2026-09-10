#ifndef FOGEFOGE_H
#define FOGEFOGE_H

#include "mapa.h"

#define CIMA 'w'
#define BAIXO 's'
#define ESQUERDA 'a'
#define DIREITA 'd'
#define BOMBA 'b'

int acabou();
void move(char direcao);
int ehdirecao(char direcao);
void andanomapa(MAPA *m, int xorigem, int yorigem, int xdestino, int ydestino);
int paraondefantasmavai(int xatual, int yatual, int *xdestino, int *ydestino);
void fantasmas();
void explodepilula();
void explodepilula2(int x, int y, int somax, int somay, int qtd);

#endif
