#include <stdio.h>
#include <stdlib.h>

double w = 0.5;
double last_err = 0;
double epsilon = 0.00001;

double
input_data (double x)
{
	return x * w;
}

double
restore_data (double x)
{
	return x / w;
}

void
train (double x, double res)
{
	double current = x * w;
	last_err = res - current;
	double correction = (last_err / current) * epsilon;
	w += correction;
}

void think() {};

int
main (void)
{
	double km = 100;
	double miles = 62.1371;
	
	int i=1;
	goto start_train;

	for (;;) {
		if (!(last_err > epsilon || last_err < -epsilon)) { break; }
start_train:
		train(km,miles);
		printf("Iteration: %d, Error: %f\n",i,last_err);
		i++;
	}

	think();

	printf("Start to think...\n");
	printf("%f miles in %d km\n", input_data(100), 100);
	printf("%f miles in %d km\n", input_data(541), 541);
	printf("%f km in %d miles\n", restore_data(1), 1);

	return 0;
}
