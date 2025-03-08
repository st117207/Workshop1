#include <iostream>
#include <fstream>
#include <cmath>

int main() {
    std::ifstream inputFile("Rough measurements.csv");
    std::ofstream outputFile("Rough Result.csv");
    float n = 10;
    float sum = 0.0;
    //���������� ������
    double value;
    for (int i = 0; i < n; i++) {
        inputFile >> value;
            sum += value;
    }


    inputFile.close();
    //������� ��������������
    float fx = sum / n;
    float T = 0.1;
    //������������� �����������
    float rerror = (5 * pow(10, -7.0) + 1 / (fx*1000 * T)) * 100;
    //���������� �����������
    float aerror = rerror * fx*1000 / 100;
    outputFile <<  fx << std::endl;
    outputFile << aerror/1000 << std::endl;
    outputFile.close();

    return 0;
}
