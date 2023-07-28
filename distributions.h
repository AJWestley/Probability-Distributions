#ifndef _DIST_H
#define _DIST_H

float* uniform_dist(int count, float min, float max);
float* gaussian_dist(int count, float mu, float sig_squared);
float* exponential_dist(int count, float lambda);
float* bernoulli_dist(int count, float p);
float uniform_single(float min, float max);
float gaussian_single(float mu, float sig_squared);
float exponential_single(float lambda);
float bernoulli_single(float p);
void seed();

#endif 