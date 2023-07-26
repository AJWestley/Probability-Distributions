#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

float* generate_gaussian(int count);
void seed();

int main(int argc, char *argv[]) {
	seed();

	FILE *fp = fopen("data.txt", "w");
	int count = 1000000;

	float* vars = generate_gaussian(count);

	for (int i = 0; i < count; i++) {
		fprintf(fp, "%f ", vars[i]);
	}

	fclose(fp);

	return EXIT_SUCCESS;
}

float* generate_gaussian(int count) {
	float* g = malloc(sizeof(float) * count);
	int i;
	float rayleigh, theta;
	for (i = 0; i < count-1; i += 2) {
		float rayleigh = sqrt(-2 * log(drand48()));
		float theta = drand48() * 2 * 3.14159365358979;
		g[i] = rayleigh * cos(theta);
		g[i+1] = rayleigh * sin(theta);
	}
	rayleigh = sqrt(-2 * log(drand48()));
	theta = drand48() * 2 * 3.14159365358979;
	g[count-1]  = rayleigh * cos(theta);
	g[count-2] = i == count ? rayleigh * sin(theta) : 3.14;
		
	return g;
}

void seed() {
	time_t t;
	srand48((unsigned)time(&t));
}
