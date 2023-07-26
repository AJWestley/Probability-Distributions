#ifndef _DIST_H
#define _DIST_H

float* generate_uniform(int count, float min, float max);
float* generate_gaussian(int count, float mu, float sig_squared);
float single_uniform(float min, float max);
float single_gaussian(float mu, float sig_squared);
void seed();

#endif 