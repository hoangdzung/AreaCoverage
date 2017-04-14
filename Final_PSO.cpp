#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <stdlib.h>
#include <ctime>
#include <iostream>
#include <fstream>

// s1-07
//const int total_sensors = 17;
//int sensor_types = 3;
//int number_sensors[] = {5, 5, 7};
//int min_number_sensors = 5;
//float radius_sensors[] = {14.00, 11.20, 8.96};
//float max_radius = 14.00f;
//float alpha = 0.68f;
//float WIDTH = 100.0f;
//float HEIGHT = 100.0f;

// s2-07
//const int total_sensors = 24;
//int sensor_types = 3;
//int number_sensors[] = { 6, 8, 10 };
//int min_number_sensors = 6;
//float radius_sensors[] = { 12.00, 9.60, 7.68 };
//float max_radius = 12.00f;
//float alpha = 0.69f;
//float WIDTH = 100.0f;
//float HEIGHT = 100.0f;

// s3-07
//const int total_sensors = 36;
//int sensor_types = 3;
//int number_sensors[] = { 8, 12, 16 };
//int min_number_sensors = 8;
//float radius_sensors[] = { 10.00, 8.00, 6.40 };
//float max_radius = 10.00f;
//float WIDTH = 100.0f;
//float HEIGHT = 100.0f;

// s4-07
//const int total_sensors = 57;
//int sensor_types = 3;
//int number_sensors[] = { 12, 18, 27 };
//int min_number_sensors = 12;
//float radius_sensors[] = { 8.00, 6.40, 5.12 };
//float max_radius = 8.00f;
//float alpha = 0.70f;
//float WIDTH = 100.0f;
//float HEIGHT = 100.0f;

// s5-07
//const int total_sensors = 101;
//int sensor_types = 3;
//int number_sensors[] = { 22, 32, 47 };
//int min_number_sensors = 22;
//float radius_sensors[] = { 6.00, 4.80, 3.84 };
//float max_radius = 6.00;
//float alpha = 0.70f;
//float WIDTH = 100.0f;
//float HEIGHT = 100.0f;

// s1-08
//const int total_sensors = 21;
//int sensor_types = 3;
//int number_sensors[] = {5, 6, 10};
//int min_number_sensors = 5;
//float radius_sensors[] = {14.00, 11.20, 8.96};
//float max_radius = 14.00f;
//float alpha = 0.80f;
//float WIDTH = 100.0f;
//float HEIGHT = 100.0f;

// s2-08
//const int total_sensors = 29;
//int sensor_types = 3;
//int number_sensors[] = { 6, 9, 14 };
//int min_number_sensors = 6;
//float radius_sensors[] = { 12.00, 9.60, 7.68 };
//float max_radius = 12.00f;
//float alpha = 0.79f;
//float WIDTH = 100.0f;
//float HEIGHT = 100.0f;

// s3-08
//const int total_sensors = 41;
//int sensor_types = 3;
//int number_sensors[] = { 9, 13, 19 };
//int min_number_sensors = 8;
//float radius_sensors[] = { 10.00, 8.00, 6.40 };
//float max_radius = 10.00f;
//float WIDTH = 100.0f;
//float HEIGHT = 100.0f;

// s4-07
//const int total_sensors = 63;
//int sensor_types = 3;
//int number_sensors[] = { 14, 20, 29 };
//int min_number_sensors = 12;
//float radius_sensors[] = { 8.00, 6.40, 5.12 };
//float max_radius = 8.00f;
//float alpha = 0.78f;
//float WIDTH = 100.0f;
//float HEIGHT = 100.0f;

// s5-08
//const int total_sensors = 116;
//int sensor_types = 3;
//int number_sensors[] = { 25, 36, 55 };
//int min_number_sensors = 22;
//float radius_sensors[] = { 6.00, 4.80, 3.84 };
//float max_radius = 6.00;
//float alpha = 0.80f;
//float WIDTH = 100.0f;
//float HEIGHT = 100.0f;

// s1-09
//const int total_sensors = 23;
//int sensor_types = 3;
//int number_sensors[] = {6, 7, 10};
//int min_number_sensors = 5;
//float radius_sensors[] = {14.00, 11.20, 8.96};
//float max_radius = 14.00f;
//float alpha = 0.90f;
//float WIDTH = 100.0f;
//float HEIGHT = 100.0f;

// s2-09
//const int total_sensors = 32;
//int sensor_types = 3;
//int number_sensors[] = { 7, 11, 14 };
//int min_number_sensors = 6;
//float radius_sensors[] = { 12.00, 9.60, 7.68 };
//float max_radius = 12.00f;
//float alpha = 0.89f;
//float WIDTH = 100.0f;
//float HEIGHT = 100.0f;

// s3-09
//const int total_sensors = 46;
//int sensor_types = 3;
//int number_sensors[] = { 11, 14, 21 };
//int min_number_sensors = 8;
//float radius_sensors[] = { 10.00, 8.00, 6.40 };
//float max_radius = 10.00f;
//float WIDTH = 100.0f;
//float HEIGHT = 100.0f;

// s4-09
//const int total_sensors = 73;
//int sensor_types = 3;
//int number_sensors[] = { 16, 23, 34 };
//int min_number_sensors = 12;
//float radius_sensors[] = { 8.00, 6.40, 5.12 };
//float max_radius = 8.00f;
//float alpha = 0.90f;
//float WIDTH = 100.0f;
//float HEIGHT = 100.0f;

// s5-09
const int total_sensors = 130;
int sensor_types = 3;
int number_sensors[] = { 28, 41, 61 };
int min_number_sensors = 9;
float radius_sensors[] = { 6.00, 4.80, 3.84 };
float max_radius = 6.00;
float alpha = 0.90f;
float WIDTH = 100.0f;
float HEIGHT = 100.0f;

int MAXGEN = 1000;
float w_first = 0.9;
float w_last = 0.4;
float c1 = 1.5;
float c2 = 1.5;

typedef struct {
	float x;
	float y;
	float radius;
	float cell;
} Sensor;

typedef struct {
	float x;
	float y;
} Velocity;

typedef struct {
	Sensor sensor[total_sensors];
	float fitness;
} G_Pbest;

typedef struct {
	Sensor sensor[total_sensors];
	Velocity velocity[total_sensors];
	float fitness;
} Individual;

const int SIZE = 50;
G_Pbest gbest, pbest[SIZE], gbest_copy[SIZE];
Individual population[SIZE];
float coA;

float RandomFloat(float a, float b);
float min(float x, float y);
float max(float x, float y);
Individual randomInitialization();
void initializePopulation();
Individual VFA(Individual idvd);
Individual standardlizeSensors(Individual idvd);
float distance(Sensor c1, Sensor c2);
float overlap(Sensor s1, Sensor s2);
float fitness_fn(Individual idvd);
void Init_pbest();
void Update_gbest();
void Update_UV(int gen);
void Update_pbest();
void Print_gbest();
void Write_Population();
float Monte();

int main () {
	srand(time(NULL));
	rand();
	initializePopulation();
	Init_pbest();
	Update_gbest();
	int gen = 0;
	while(gen < MAXGEN) {
		Update_UV(gen);
		Update_pbest();
		Update_gbest();
		Print_gbest();
		gen++;
	}
	Print_gbest();
	Write_Population();
	coA = Monte();
	printf("coA = %f", coA); 
	return 0;
}

void Write_Population() {
	FILE *f;
	f = fopen ("final_result.txt", "w");
	fprintf (f, "%.0f\n", WIDTH);
	fprintf (f, "%.0f\n", HEIGHT);
	fprintf (f, "%d\n", total_sensors);
	fprintf (f, "%d\n", sensor_types);
	for (int i = 0; i < sensor_types; i++) {
		fprintf (f, "%d ", number_sensors[i]);
	}
	fprintf (f, "\n");
	for (int i = 0; i < sensor_types; i++) {
		fprintf(f, "%.2f ", radius_sensors[i]);
	}
	fprintf(f, "\n0");
	fprintf(f, "\n%d\n", SIZE + 1);
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < total_sensors; j++) {
			fprintf(f, "%f,%f,%f ", population[i].sensor[j].x, population[i].sensor[j].y, population[i].sensor[j].radius );
		}
		fprintf(f, "\nfitness %f\n", population[i].fitness);
	}
	for (int j = 0; j < total_sensors; j++) {
		fprintf(f, "%f,%f,%f ", gbest.sensor[j].x, gbest.sensor[j].y, gbest.sensor[j].radius );
	}
	fprintf(f, "\nfitness %f\n", gbest.fitness);
	fclose(f);
}

Individual randomInitialization() {
	int i = 0;
	Individual idvd;
	for (int type = 0; type < sensor_types; type++) {
		for (int j = 0; j < number_sensors[type]; j++) {
			idvd.sensor[i].x = RandomFloat(radius_sensors[type], WIDTH - radius_sensors[type]);
			idvd.sensor[i].y = RandomFloat(radius_sensors[type], HEIGHT - radius_sensors[type]);
			idvd.sensor[i].radius = radius_sensors[type];
			idvd.velocity[i].x = 0;
			idvd.velocity[i].y = 0;
			i++;
		}
	}
	idvd = VFA(idvd);
	idvd.fitness = fitness_fn(idvd);
	return idvd;
}


Individual VFA(Individual idvd) {
	for (int i = 0; i < total_sensors; i++) {
		float frx = 0.0f, fry = 0.0f;
		int nr = 0;
		for (int j = 0; j < total_sensors; j++) {
			if (i == j) continue;
			float dt = distance(idvd.sensor[i], idvd.sensor[j]);
			float sum_radius = idvd.sensor[i].radius + idvd.sensor[j].radius;
			if (dt < sum_radius) {
				frx += (1 - sum_radius / dt) * (idvd.sensor[j].x - idvd.sensor[i].x);
				fry += (1 - sum_radius / dt) * (idvd.sensor[j].y - idvd.sensor[i].y);
				nr++;
			}
		}
		if (nr != 0) {
			idvd.sensor[i].x += frx / nr;
			idvd.sensor[i].y += fry / nr;
		}
		idvd.sensor[i].x = round(idvd.sensor[i].x * 1000) / 1000;
		idvd.sensor[i].y = round(idvd.sensor[i].y * 1000) / 1000;
	}
	idvd = standardlizeSensors(idvd);
	return idvd;
}


Individual standardlizeSensors(Individual idvd) {
	for (int i = 0; i < total_sensors; i++) {
		if (idvd.sensor[i].x < idvd.sensor[i].radius)
			idvd.sensor[i].x = idvd.sensor[i].radius;
		if (idvd.sensor[i].y < idvd.sensor[i].radius)
			idvd.sensor[i].y = idvd.sensor[i].radius;
		float max_x = WIDTH - idvd.sensor[i].radius;
		float max_y = HEIGHT - idvd.sensor[i].radius;
		if (idvd.sensor[i].x > max_x) idvd.sensor[i].x = max_x;
		if (idvd.sensor[i].y > max_y) idvd.sensor[i].y = max_y;
	}
	return idvd;
}

void initializePopulation() {
	for(int i = 0; i < SIZE; i++) {
		population[i] = randomInitialization();
	}
}

float distance(Sensor c1, Sensor c2) {
	float x = c2.x - c1.x;
	float y = c2.y - c1.y;
	return sqrt(x*x + y*y);
}

float overlap(Sensor s1, Sensor s2) {
	float ol = 0;
	float dt = distance(s1, s2);
	float sum_radius = s1.radius + s2.radius;
	if (dt >= sum_radius) return 0;

	if (fabs(s1.radius - s2.radius) <= dt && dt < sum_radius) {
		float gamma = sum_radius*min(s1.radius, s2.radius) / (max_radius*max(s1.radius, s2.radius));
		return gamma*(sum_radius - dt);
	}
	float beta = 2 * max_radius + 0.1;
	return beta*min(s1.radius, s2.radius);
}

float fitness_fn(Individual idvd) {
	float olap = 0;
	for (int i = 0; i < total_sensors; i++) {

		for (int j = i + 1; j < total_sensors; j++) {
			olap += overlap(idvd.sensor[i], idvd.sensor[j]);
		}
		Sensor barrier[] = {
			{ idvd.sensor[i].x, 0 },
			{ idvd.sensor[i].x, HEIGHT },
			{ 0, idvd.sensor[i].y },
			{ WIDTH, idvd.sensor[i].y }
		};
		for (int j = 0; j < 4; j++) {
			float dt = distance(idvd.sensor[i], barrier[j]);
			if(dt < idvd.sensor[i].radius)
				olap += (idvd.sensor[i].radius - dt)*idvd.sensor[i].radius;
		}
	}
	return 1.0/olap;
}
void Init_pbest() {
	for (int i = 0; i < SIZE; i++) {
		for(int j = 0; j < total_sensors; j++) {
			pbest[i].sensor[j].x = population[i].sensor[j].x;
			pbest[i].sensor[j].y = population[i].sensor[j].y;
			pbest[i].sensor[j].radius = population[i].sensor[j].radius;
		}
		pbest[i].fitness = population[i].fitness;
	}
}

void Update_gbest() {
	gbest = pbest[0];
	for (int i = 1; i < SIZE; i++) {
		if (gbest.fitness < pbest[i].fitness) gbest = pbest[i];
	}
}

void Update_UV(int gen) {
	float w = (w_first - w_last) * (float) (MAXGEN - gen)/ MAXGEN + w_last;
	float r1 = RandomFloat(0, 1);
	float r2 = RandomFloat(0, 1);
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < total_sensors; j++) {
			population[i].velocity[j].x = w * population[i].velocity[j].x 
										+ c1 * r1 * (pbest[i].sensor[j].x - population[i].sensor[j].x) 
										+ c2 * r2 * (gbest.sensor[j].x - population[i].sensor[j].x);
			population[i].velocity[j].y = w * population[i].velocity[j].y
										+ c1 * r1 * (pbest[i].sensor[j].y - population[i].sensor[j].y) 
										+ c2 * r2 * (gbest.sensor[j].y - population[i].sensor[j].y);
		}
		for (int j = 0; j < total_sensors; j++) {
			population[i].sensor[j].x += population[i].velocity[j].x;
			population[i].sensor[j].y += population[i].velocity[j].y;
		}
		population[i] = VFA(population[i]);
		population[i].fitness = fitness_fn(population[i]);
	}
}

void Update_pbest() {
	for (int i = 0; i < SIZE; i++) {
		if (population[i].fitness > pbest[i].fitness) {
			pbest[i].fitness = population[i].fitness;
			for (int j = 0; j < total_sensors; j++) {
				pbest[i].sensor[j].x = population[i].sensor[j].x;
				pbest[i].sensor[j].y = population[i].sensor[j].y;
				pbest[i].sensor[j].radius = population[i].sensor[j].radius;
			}
		}
	}
}

void Print_gbest() {
	printf ("olap: %f\n", 1.0/gbest.fitness);
}

float Monte() {
	int L = 1000000;
	float coA = 0;
	Sensor *point;
	point = (Sensor*)malloc(sizeof(Sensor)*L);
	for (int i = 0; i < L; i++) {
		point[i].x = RandomFloat(0, WIDTH);
		point[i].y = RandomFloat(0, HEIGHT);
	}
	for(int i = 0; i < L; i++) {
		for(int j = 0; j < total_sensors; j++) {
			if (distance(point[i], gbest.sensor[j]) <= gbest.sensor[j].radius) {
				coA++;
				break;
			}
		}
	}
	free(point);
	return coA / L * WIDTH * HEIGHT;
}

float RandomFloat(float a, float b) {
	float random = ((float)rand()) / (float)RAND_MAX;
	float diff = b - a;
	float r = random * diff;
	return a + r;
}

float min(float x, float y) {
	if (x < y) return x;
	return y;
}

float max(float x, float y) {
	if (x < y) return y;
	return x;
}
