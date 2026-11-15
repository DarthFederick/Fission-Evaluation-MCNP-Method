#ifndef OBJECTS_H_
#define OBJECTS_H_

#include "vectors.h"

typedef enum{
  ACTIVE,
  ABSORBED,
  ESCAPED
} particle_status;

typedef struct{

  Vec3 pos;
  Vec3 dir;
  particle_status status;

} particle;

typedef struct{
  double radius;

  //Cross section for interaction
  double sigma_t;
  //Cross section for scattering
  double sigma_s;

} sphere;

#endif // OBJECTS_H_
