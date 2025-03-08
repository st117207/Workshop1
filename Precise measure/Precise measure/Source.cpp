#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

int main() {
    std::ifstream inputFile("Precise measurements.csv");
    std::ofstream outputFile("Precise Result.csv");
    float n = 50;
    float sum = 0.0;
    double temp = 0;
    double data[50];
    double value;
    //���������� ������
    for (int i = 0; i < n; i++) {
        inputFile >> value;
        data[i] = value;
        sum += value;
    }


    inputFile.close();
    //������� ��������������
    float fx =round(sum / n * 1000) / 1000;
    float T = 1;
    //������������� �����������
    float rerror = 5 * pow(10, -7.0) + 1 / (fx * 1000 * T) * 100;
    //���������� �����������
    float aerror = rerror * fx * 1000 / 100;
    //���������
    for (int i = 0; i < n; i++) {
        temp += pow((data[i] - fx), 2);
    }
    double sygma = sqrt(temp / (n - 1));
    //������� ������������ ����������� ��������
    double sygmax = sygma / sqrt(n);
    outputFile <<fx << std::endl;
    outputFile << std::fixed<<std::setprecision(6) << aerror / 1000 << std::endl;
    outputFile << sygma << std::endl;
    outputFile << sygmax << std::endl;


    outputFile.close();

    return 0;
}
