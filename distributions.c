#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "distributions.h"

int main(int argc, char *argv[]) {
	if (argc < 4) {
		printf("Usage: %s int float float\n", argv[0]);
		return EXIT_FAILURE;
	}

	seed();

	FILE *fp = fopen("data.txt", "w");
	int count = atoi(argv[1]);

	float* vars = bernoulli_dist(count, atof(argv[2]));

	for (int i = 0; i < count; i++) {
		fprintf(fp, "%f ", vars[i]);
	}

	fclose(fp);
	free(vars);

	return EXIT_SUCCESS;
}

/**
 * Generates an array of random floats according to the Uniform distribution.
*/
float* uniform_dist(int count, float min, float max) {
	float* u = malloc(sizeof(float) * count);
	for (int i = 0; i < count; i++) {
		u[i] = uniform_single(min, max);
	}
	return u;
}

/**
 * Generates an array of random floats according to the Normal/Gaussian distribution.
*/
float* gaussian_dist(int count, float mu, float sigma) {
	float* g = malloc(sizeof(float) * count);
	int i;
	float rayleigh, theta;
	for (i = 0; i < count-1; i += 2) {
		rayleigh = sqrt(-2 * log(drand48()));
		theta = uniform_single(0, 2 * M_PI);
		g[i] = sigma * rayleigh * cos(theta) + mu;
		g[i+1] = sigma * rayleigh * sin(theta) + mu;
	}
	rayleigh = sqrt(-2 * log(drand48()));
	theta = uniform_single(0, 2 * M_PI);
	g[count-1]  = sigma * rayleigh * cos(theta) + mu;
	if (i == count ) g[count-2] = sigma * rayleigh * sin(theta) + mu;
		
	return g;
}

/**
 * Generates an array of random floats according to the Exponential distribution.
*/
float* exponential_dist(int count, float lambda) {
	float* ex = malloc(sizeof(float) * count);
	for (int i = 0; i < count; i++) {
		ex[i] = exponential_single(lambda);
	}
	return ex;
}

/**
 * Generates an array of random floats according to the Bernoulli distribution.
*/
float* bernoulli_dist(int count, float p) {
	float* bern = malloc(sizeof(float) * count);
	for (int i = 0; i < count; i++) {
		bern[i] = bernoulli_single(p);
	}
	return bern;
}

/**
 * Generates a single random float according to the Uniform distribution.
*/
float uniform_single(float min, float max) {
	return drand48() * (max - min) + min;
}

/**
 * Generates a single random float according to the Normal/Gaussian distribution.
*/
float gaussian_single(float mu, float sigma) {
	float rayleigh = sqrt(-2 * log(drand48()));
	float theta = uniform_single(0, 2 * M_PI);
	return sigma * rayleigh * sin(theta) + mu;
}

/**
 * Generates a single random float according to the Exponential distribution.
*/
float exponential_single(float lambda) {
	return -(log(drand48()) / lambda);
}

/**
 * Generates a single random float according to the Bernoulli distribution.
*/
float bernoulli_single(float p) {
	return drand48() < p ? 1 : 0;
}
	
/**
 * Seeds the random number generator.
*/
void seed() {
	time_t t;
	srand48((unsigned)time(&t));
}
