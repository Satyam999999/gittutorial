#include <iostream>
#include <vector>
using namespace std;

int happy(vector<int>& speeds) {
    vector<int> height1, height2; 
    for (int speed : speeds) {
        if (height1.empty() || speed <= height1.back()) {
            height1.push_back(speed);
        } 
       
        else if (height2.empty() || speed <= height2.back()) {
            height2.push_back(speed);
        } 
   
        else if (!height1.empty() && speed > height1.back()) {
            height1.back() = speed;
        } else if (!height2.empty() && speed > height2.back()) {
            height2.back() = speed;
        }
    }

    return height1.size() + height2.size();
}

int main() {
    int N;
    cin >> N;
    vector<int> speeds(N);
    for (int i = 0; i < N; i++) {
        cin >> speeds[i];
    }

    cout << happy(speeds) << endl;
    return 0;
}