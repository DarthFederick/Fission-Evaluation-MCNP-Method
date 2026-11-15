#include <stdlib.h>
#include <math.h>

#include "neutron_functions.h"

double path_length(double sigma_t){
  //Distance is measured in cm
  double distance = 0;
  double phi = 1 - drand48();
  distance = (- log(phi)) / sigma_t;
  return distance;

}

Vec3 new_direction(void){
  Vec3 direction = {0, 0, 0};

  double rand_1 = 1 - drand48();
  double rand_2 = 1 - drand48();

  double mu = 2 * rand_1 - 1;
  double phi = 2 * M_PI * rand_2;

  direction.x = sqrt(1 - (mu * mu)) * cos(phi);
  direction.y = sqrt(1 - (mu * mu)) * sin(phi);
  direction.z = mu;

  return direction;

}
