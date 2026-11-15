#include "vectors.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

Vec3 Vec3_sum(Vec3 a, Vec3 b){
  Vec3 c = {a.x + b.x, a.y + b.y, a.z + b.z};
  return c;
}

double Vec3_norm(Vec3 a){
  double norma = 0;
  norma = (a.x * a.x) + (a.y * a.y) + (a.z * a.z);
  norma = sqrt(norma);
  return norma;
}

Vec3 Vec3_scalar(Vec3 v, double lambda){
  Vec3 lambda_v = {lambda * v.x, lambda * v.y, lambda * v.z};
  return lambda_v;
}
