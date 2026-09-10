#ifndef MAPA_H
#define MAPA_H

#define HEROI '@'
#define FANTASMA 'F'
#define PILULA 'P'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'

struct mapa {
  char **matriz;
  int linhas;
  int colunas;
};
typedef struct mapa MAPA;
struct posicao {
  int x;
  int y;
};
typedef struct posicao POSICAO;
int lemapa(MAPA *m);
void alocamapa(MAPA *m);
void liberamapa(MAPA *m);
int encontramapa(MAPA *m, POSICAO *p, char c);
int ehdirecao(char direcao);
int podeandar(MAPA *m, char personagem, int x, int y);
void copiamapa(MAPA *destino, MAPA *origem);
int ehvalida(MAPA *m, int x, int y);
int ehparede(MAPA *m, int x, int y);
int ehpersonagem(MAPA *m, char personagem, int x, int y);
void andanomapa(MAPA *m, int xorigem, int yorigem, int xdestino, int ydestino);

#endif
