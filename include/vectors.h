#ifndef VECTORS_H_
#define VECTORS_H_

typedef struct{
  double x;
  double y;
  double z;
} Vec3;

Vec3 Vec3_somma(Vec3 a, Vec3 b);
double Vec3_norma(Vec3 v);

#endif // VECTORS_H_
