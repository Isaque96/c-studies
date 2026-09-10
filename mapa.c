#include "mapa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copiamapa(MAPA *destino, MAPA *origem) {
  destino->linhas = origem->linhas;
  destino->colunas = origem->colunas;

  alocamapa(destino);
  for (int i = 0; i < origem->linhas; i++) {
    for (int j = 0; j < origem->colunas; j++) {
      strcpy(destino->matriz[i], origem->matriz[i]);
    }
  }
}

int ehparede(MAPA *m, int x, int y) {
  return m->matriz[x][y] == PAREDE_VERTICAL ||
         m->matriz[x][y] == PAREDE_HORIZONTAL;
}

int ehpersonagem(MAPA *m, char personagem, int x, int y) {
  return m->matriz[x][y] == personagem;
}

int ehvalida(MAPA *m, int x, int y) {
  if (x < 0 || y < 0)
    return 0;
  if (x >= m->linhas)
    return 0;
  if (y >= m->colunas)
    return 0;

  return 1;
}

int podeandar(MAPA *m, char personagem, int x, int y) {
  return ehvalida(m, x, y) && !ehparede(m, x, y) &&
         !ehpersonagem(m, personagem, x, y);
}

int encontramapa(MAPA *m, POSICAO *p, char c) {
  for (int i = 0; i < m->linhas; i++) {
    for (int j = 0; j < m->colunas; j++) {
      if (m->matriz[i][j] == c) {
        p->x = i;
        p->y = j;
        return 1;
      }
    }
  }

  return 0;
}

int lemapa(MAPA *m) {
  FILE *f = fopen("mapa.txt", "r");
  if (f == 0) {
    printf("Erro ao abrir o arquivo.\n");
    return 1;
  }
  fscanf(f, "%d %d", &m->linhas, &m->colunas);
  printf("m.linhas %d m.colunas %d\n", m->linhas, m->colunas);
  alocamapa(m);
  for (int i = 0; i < m->linhas; i++) {
    fscanf(f, "%s", m->matriz[i]);
  }

  fclose(f);

  return 0;
}

void alocamapa(MAPA *m) {
  m->matriz = malloc(m->linhas * sizeof(char *));
  for (int i = 0; i < m->linhas; i++) {

    m->matriz[i] = malloc((m->colunas + 1) * sizeof(char));
  }
}

void liberamapa(MAPA *m) {
  for (int i = 0; i < m->linhas; i++) {
    free(m->matriz[i]);
  }
  free(m->matriz);
}

void andanomapa(MAPA *m, int xorigem, int yorigem, int xdestino, int ydestino) {
  char personagem = m->matriz[xorigem][yorigem];
  m->matriz[xdestino][ydestino] = personagem;
  m->matriz[xorigem][yorigem] = VAZIO;
}
