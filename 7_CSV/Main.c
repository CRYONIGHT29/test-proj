#include <stdio.h>
#include <math.h>

int main() {

	FILE *fp = fopen("numbers.txt", "r");
	if (!fp) {
		printf("File open error\n");
		return 1;
	}

	char line[1024];
	double x, sum = 0, sumsq = 0, min = 0, max = 0;
	int count = 0;

	while (fgets(line, sizeof(line), fp)) {

		if (line[0] == '\n')
			continue;

		if (sscanf(line, "%lf", &x) != 1)
			continue;   // skip invalid lines

		if (count == 0)
			min = max = x;
		else {
			if (x < min) min = x;
			if (x > max) max = x;
		}

		sum += x;
		sumsq += x * x;
		count++;
	}

	fclose(fp);

	if (count == 0) {
		printf("No valid data\n");
		return 1;
	}

	double mean = sum / count;
	double stddev = sqrt((sumsq / count) - (mean * mean));

	printf("Count  : %d\n", count);
	printf("Mean   : %.6f\n", mean);
	printf("Min    : %.6f\n", min);
	printf("Max    : %.6f\n", max);
	printf("StdDev : %.6f\n", stddev);

	return 0;
}