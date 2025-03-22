#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>


void inputdata(double arr[], double n)
{
	std::ifstream inputFile("Precise measurements.csv");
	for (int i = 0; i < n; i++) {
		inputFile >> arr[i];
	}
}
double arithmetic_mean(double arr[], double n)
{
	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}
	double arithmetic = 0.0;
	arithmetic = static_cast<double>(round(sum / n * 1000)) / 1000;
	return arithmetic;
}
double relative_error(double arr[], double n)
{
	double fx = arithmetic_mean(arr, n);
	double T = 1;
	double rerror = (5 * pow(10, -7.0) + 1 / (fx * 1000 * T)) * 100;
	return rerror;
}
double absolute_error(double arr[], double n)
{
	double rerror = relative_error(arr, n);
	double fx = arithmetic_mean(arr, n);
	double aerror = rerror * fx / 100;
	return aerror;
}
void RandomDeviations(double arr1[], double arr2[], double arr3[], double n)
{
	double arithmetic = arithmetic_mean(arr1, n);
	for (int i = 0; i < n; i++) {
		arr2[i] = arr1[i] - arithmetic;
		arr3[i] = arr2[i] * arr2[i];
	}
}
float dispersion(double arr3[], double n)
{
	float sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr3[i];
	}
	return sqrt(sum / (n - 1));
}
double root_mean_square_error_mean(double arr3[], double n)
{
	return dispersion(arr3, n) / sqrt(n);
}
double total_error(double arr1[], double arr3[], double n)
{
	return sqrt(pow(arithmetic_mean(arr1, n) / 3, 2) + pow(root_mean_square_error_mean(arr3, n), 2));
}
void outputdata(double arr1[], double arr2[], double arr3[], double n)
{
	float sum1 = 0;
	float sum2 = 0;
	std::ofstream outputFile("Precise Result.csv");
	RandomDeviations(arr1, arr2, arr3, n);
	outputFile << arithmetic_mean(arr1, n) << std::endl;
	outputFile << std::setprecision(4) << absolute_error(arr1, n) << std::endl;
	outputFile << std::setprecision(4) << dispersion(arr3, n) << std::endl;
	outputFile << std::setprecision(4) << root_mean_square_error_mean(arr3, n) << std::endl;
	outputFile << std::setprecision(4) << total_error(arr1, arr3, n) << std::endl;
	outputFile << std::endl;
	for (int i = 0; i < n; i++) {
		outputFile << arr2[i] << " " << arr3[i] << std::endl;
		sum1 += arr2[i];
		sum2 += arr3[i];
	}
	outputFile << "----------------------"<<std::endl;
	outputFile << std::setprecision(3) << sum1 << " " << std::setprecision(6) << sum2;



}
int main() {
	int n = 43;
	double data1[43];
	double data2[43];
	double data3[43];
	inputdata(data1, n);
	outputdata(data1, data2, data3, n);

	return 0;
}
