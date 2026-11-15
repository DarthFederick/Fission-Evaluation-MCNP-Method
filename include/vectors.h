#ifndef VECTORS_H_
#define VECTORS_H_

typedef struct{
  double x;
  double y;
  double z;
} Vec3;

Vec3 Vec3_sum(Vec3 a, Vec3 b);
double Vec3_norm(Vec3 v);
Vec3 Vec3_scalar(Vec3 v, double lambda);

#endif // VECTORS_H_
