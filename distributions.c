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

	int* vars = bernoulli_dist(count, atof(argv[2]));

	for (int i = 0; i < count; i++) {
		fprintf(fp, "%d ", vars[i]);
	}

	fclose(fp);
	free(vars);

	return EXIT_SUCCESS;
}

/**
 * Generates an array of random floats according to the Uniform distribution.
*/
float* uniform_dist(int count, float min, float max) {
	float* u = malloc(sizeof(float) * (count + 1));
	u[0] = (float) count;
	for (int i = 1; i <= count; i++) {
		u[i] = uniform_single(min, max);
	}
	return u;
}

/**
 * Generates an array of random floats according to the Normal/Gaussian distribution.
*/
float* gaussian_dist(int count, float mu, float sigma) {
	float* g = malloc(sizeof(float) * (count + 1));
	int i;
	float rayleigh, theta;
	g[0] = (float) count;
	for (i = 1; i <= count-1; i += 2) {
		rayleigh = sqrt(-2 * log(drand48()));
		theta = uniform_single(0, 2 * M_PI);
		g[i] = sigma * rayleigh * cos(theta) + mu;
		g[i+1] = sigma * rayleigh * sin(theta) + mu;
	}
	rayleigh = sqrt(-2 * log(drand48()));
	theta = uniform_single(0, 2 * M_PI);
	g[count] = sigma * rayleigh * cos(theta) + mu;
	if (i == count+1 ) g[count-1] = sigma * rayleigh * sin(theta) + mu;
		
	return g;
}

/**
 * Generates an array of random floats according to the Exponential distribution.
*/
float* exponential_dist(int count, float lambda) {
	float* ex = malloc(sizeof(float) * (count + 1));
	ex[0] = (float) count;
	for (int i = 1; i <= count; i++) {
		ex[i] = exponential_single(lambda);
	}
	return ex;
}

/**
 * Generates an array of random floats according to the Bernoulli distribution.
*/
int* bernoulli_dist(int count, float p) {
	int* bern = malloc(sizeof(float) * (count + 1));
	bern[0] = count;
	for (int i = 1; i <= count; i++) {
		bern[i] = bernoulli_single(p);
	}
	return bern;
}

/**
 * Generates an array of random floats according to the Binomial distribution.
*/
int* binomial_dist(int count, float p, int n) {
	int* bino = malloc(sizeof(float) * (count + 1));
	bino[0] = count;
	for (int i = 1; i <= count; i++) {
		bino[i] = binomial_single(p, n);
	}
	return bino;
}

/**
 * Generates an array of random integers according to the Poisson distribution.
*/
int* poisson_dist(int count, float lambda) {
	int* poisson = malloc(sizeof(float) * (count + 1));
	poisson[0] = count;
	for (int i = 1; i <= count; i++) {
		poisson[i] = poisson_single(lambda);
	}
	return poisson;
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
	return -(log(drand48()) / (1 / lambda));
}

/**
 * Generates a single random float according to the Bernoulli distribution.
*/
int bernoulli_single(float p) {
	return drand48() < p ? 1 : 0;
}

/**
 * Generates a single random float according to the Binomial distribution.
*/
int binomial_single(float p, int n) {
	int bino = 0;
	for (int i = 0; i < n; i++) {
		bino += (drand48() < p ? 1 : 0);
	}
	return bino;
}

/**
 * Generates a single random integer according to the Poisson distribution.
*/
int poisson_single(float lambda) {
	double exp_lambda = exp(-lambda);
	double uniform;
	double uniform_product;
	int poisson;

	poisson = -1;
	uniform_product = 1;

	do
	{
	uniform = uniform_single(0, 1);
	uniform_product = uniform_product * uniform;
	poisson++; 
	} while (uniform_product > exp_lambda);

	return poisson;
}

/**
 * Seeds the random number generator.
*/
void seed() {
	time_t t;
	srand48((unsigned)time(&t));
}
