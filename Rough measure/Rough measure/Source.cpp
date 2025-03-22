#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>


void inputdata(float arr[], double n)
{
	std::ifstream inputFile("Rough measurements.csv");
	for (int i = 0; i < n; i++) {
		inputFile >> arr[i];
	}
}
float arithmetic_mean(float arr[], double n)
{
	float sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}
	return sum / n;
}
float relative_error(float arr[], double n)
{
	float fx = arithmetic_mean(arr, n);
	float T = 0.1;
	float rerror = (5 * pow(10, -7.0) + 1 / (fx * 1000 * T)) * 100;
	return rerror;
}
float absolute_error(float arr[], double n)
{
	float rerror = relative_error(arr, n);
	float fx = arithmetic_mean(arr, n);
	float aerror = rerror * fx / 100;
	return aerror;
}
void outputdata(float arr[], double n)
{
	std::ofstream outputFile("Rough Result.csv");
	outputFile << arithmetic_mean(arr, n)<<std::endl;
	outputFile << std::setprecision(4) << absolute_error(arr, n) << std::endl;

}
int main() {
	int n = 10;
	float data[10];
	inputdata(data, n);
	outputdata(data, n);

	return 0;
}
