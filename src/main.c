#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "vectors.h"
#include "objects.h"
#include "neutron_functions.h"


int main(){

  srand48(time(NULL));

  sphere godiva = {
    .radius = 8.7407,
    .sigma_t = 0.277415,
    .sigma_s = 0.210835
    };

  int neutron_count = 100000;
  int absorbed_counter = 0;
  int escaped_counter = 0;

  //sim cycle
  for(int i = 0; i < neutron_count; i++){

    particle_status status = ACTIVE;
    status = transport_neutron(godiva);

    if(status == ABSORBED){
      absorbed_counter++;
    } else if(status == ESCAPED){
      escaped_counter++;
    }
  }

  if((absorbed_counter + escaped_counter) == neutron_count){
    printf("No stray neutrons counted (absorbed + escaped = neutron count)\n");
  } else {printf("Absorbed + Escaped does not match the neutron count \n");}

  printf("Absorbed Neutrons = %d \n", absorbed_counter);
  printf("Escaped Neutrons = %d \n", escaped_counter);

  double absorbed_ratio = (double) absorbed_counter / neutron_count;
  double escaped_ratio = (double) escaped_counter / neutron_count;

  printf("Absorbed Neutrons Percentage = %lf \n", absorbed_ratio * 100);
  printf("Escaped Neutrons Percentage = %lf \n", escaped_ratio * 100);

}
