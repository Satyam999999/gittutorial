#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

void computeStats(double values[], int size, double &avg, double &stdDev) {
    double total = 0, squaredTotal = 0;
    for (int i = 0; i < size; ++i) {
        total += values[i];
        squaredTotal += values[i] * values[i];
    }
    avg = total / size;
    stdDev = squaredTotal / size - avg * avg;
}

void displayHistogram(double values[], int size, int binCount) {
    double minValue = *min_element(values, values + size);
    double maxValue = *max_element(values, values + size);
    double binSize = (maxValue - minValue) / binCount;

    vector<int> histogramBins(binCount, 0);

    for (int i = 0; i < size; ++i) {
        int index = (int)((values[i] - minValue) / binSize);
        if (index == binCount) {
            index--;
        }
        histogramBins[index]++;
    }

    for (int i = 0; i < binCount; ++i) {
        cout << "[" << minValue + i * binSize << ", " << minValue + (i + 1) * binSize << "): ";
        for (int j = 0; j < histogramBins[i]; ++j) {
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
    srand(time(0)); 
    double randomValues[1000];
    int counter = 0;
    while (counter < 1000) {
        double randX = (double)rand() / RAND_MAX;
        double randY = (double)rand() / RAND_MAX;
       
        randomValues[counter] = sqrt(-2 * log(randX)) * cos(2 * M_PI * randY);
        counter++;
    }

    double avg, stdDev;
    computeStats(randomValues, 1000, avg, stdDev); 
    cout << "Mean: " << avg << endl;
    cout << "Variance: " << stdDev << endl;

    int binCount = 20; 
    displayHistogram(randomValues, 1000, binCount);

    return 0;
}