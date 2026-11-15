#ifndef NEUTRON_FUNCTIONS_H_
#define NEUTRON_FUNCTIONS_H_

#include "vectors.h"
#include "objects.h"

double path_length(double sigma_t);
Vec3 new_direction(void);
particle_status transport_neutron(sphere godiva);

#endif // NEUTRON_FUNCTIONS_H_
