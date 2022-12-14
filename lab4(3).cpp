#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, string> countryCapitalMap;
    countryCapitalMap.insert(pair<string, string>("Ukraine", "Kiev"));
    countryCapitalMap.insert(pair<string, string>("India", "Delhi"));
    countryCapitalMap.insert(pair<string, string>("Nepal", "Kathmandu"));
    countryCapitalMap.insert(pair<string, string>("China", "Beijing"));
    countryCapitalMap.insert(pair<string, string>("France", "Paris"));
    countryCapitalMap.insert(pair<string, string>("Germany", "Berlin"));

   
    for (const auto &ele : countryCapitalMap) {
        cout <<ele.first << ":" << ele.second<<"\n";
    }
   
    return 0;
}