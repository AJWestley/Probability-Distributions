#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

float* generate_uniform(int count, float min, float max);
float* generate_gaussian(int count, float mu, float sig_squared);
float single_uniform(float min, float max);
float single_gaussian(float mu, float sig_squared);
void seed();

int main(int argc, char *argv[]) {
	seed();

	FILE *fp = fopen("data.txt", "w");
	int count = 1000000;

	float* vars = generate_gaussian(count, 0, 10);

	for (int i = 0; i < count; i++) {
		fprintf(fp, "%f ", vars[i]);
	}

	fclose(fp);
	free(vars);

	return EXIT_SUCCESS;
}

float* generate_uniform(int count, float min, float max) {
	float* u = malloc(sizeof(float) * count);
	for (int i = 0; i < count; i++) {
		u[i] = single_uniform(min, max);
	}
	return u;
}

float* generate_gaussian(int count, float mu, float sig_squared) {
	float* g = malloc(sizeof(float) * count);
	int i;
	float rayleigh, theta;
	for (i = 0; i < count-1; i += 2) {
		rayleigh = sqrt(-2 * log(drand48()));
		theta = single_uniform(0, 2 * M_PI);
		g[i] = sig_squared * rayleigh * cos(theta) + mu;
		g[i+1] = sig_squared * rayleigh * sin(theta) + mu;
	}
	rayleigh = sqrt(-2 * log(drand48()));
	theta = single_uniform(0, 2 * M_PI);
	g[count-1]  = sig_squared * rayleigh * cos(theta) + mu;
	if (i == count ) g[count-2] = sig_squared * rayleigh * sin(theta) + mu;
		
	return g;
}

float single_uniform(float min, float max) {
	return drand48() * (max - min) + min;
}
float single_gaussian(float mu, float sig_squared) {
	float rayleigh = sqrt(-2 * log(drand48()));
	float theta = single_uniform(0, 2 * M_PI);
	return sig_squared * rayleigh * sin(theta) + mu;
}

void seed() {
	time_t t;
	srand48((unsigned)time(&t));
}
