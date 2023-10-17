#include <iostream>
#include "modules/Engine.h"
using namespace std;

int main(){
    Engine engine; 
    engine.run();
    engine.resize(100,200);
    engine.resize(500,1000);
    return 0;
}
