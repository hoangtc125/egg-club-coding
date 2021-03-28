#include <iostream>
#include <vector>

using namespace std;

unsigned long long demUoc(unsigned long long n) {
    int i = 2;
    int dem = 0;
    vector<unsigned long long> answer1;
    while(n > 0) {
        if(n % i == 0) {
            n /= i;
            dem++;
        } 
        if(n % i != 0) {
            if(dem != 0) {
                answer1.push_back(dem);
            }
            dem = 0;
            i++;
            if(i > n) {
                break;
            }
        }
    }
    dem = 1;
    for(int i = 0; i < answer1.size(); i++){
        dem *= answer1[i] * 2 + 1;
    } 
    return dem;
}

int main() {

    unsigned long long t,n;
    cin>>t;
    vector<unsigned long long> answer;
    while(t > 0){
        t--;
        cin>>n;
        answer.push_back(demUoc(n)); 
    }
    for(int i = 0; i < answer.size(); i++){
        cout<<answer[i]<<"\n";
    }

    return 0;
}