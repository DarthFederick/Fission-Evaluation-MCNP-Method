#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct{
  double x;
  double y;
} Vec2;

typedef enum{
  INTATTO,
  FISSIONATO,
  INERTE
} StatoAtomo;

typedef struct{
  Vec2 pos;
  //Per simulare la vibrazione termica in un secondo momento
  Vec2 vel;
  //Stato del singolo atomo
  StatoAtomo stato_attuale;

} atomo;

typedef struct{
  Vec2 pos;
  Vec2 vel;
} neutrone;
