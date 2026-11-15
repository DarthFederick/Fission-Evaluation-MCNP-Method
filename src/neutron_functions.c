#include <stdlib.h>
#include <math.h>

#include "neutron_functions.h"
#include "objects.h"
#include "vectors.h"

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

particle_status transport_neutron(sphere godiva){

  double s = 0;
  double p_scatter = godiva.sigma_s / godiva.sigma_t;

  //Initializing neutron in (0, 0, 0)
  particle neutron = {
    .pos = {0},
    .dir = {0},
    .status = ACTIVE
  };

  //Giving the neutron a random motion direction
  neutron.dir = new_direction();

  //Neutron Life Cicle
  while(neutron.status == ACTIVE){
    s = path_length(godiva.sigma_t);
    neutron.pos = Vec3_sum(neutron.pos, Vec3_scalar(neutron.dir, s));

    if(Vec3_norm(neutron.pos) > godiva.radius){
      neutron.status = ESCAPED;
    } else {
      if(drand48() < p_scatter){
        neutron.dir = new_direction();
      } else {
        neutron.status = ABSORBED;
      }
    }
  }

  return neutron.status;

}
