#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <exception>
#include <stdexcept>
#include <iostream>
#include <cmath>
#include <Windows.h>
#include "Triangle.h"
#include "RightTriangle.h"



int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Triangle Test;
    Test.Read();
    if (Test.is_possible()) {
        Test.display();
        Test.mediani();
        Test.parallel_line();
    RightTriangle Test1;
    if (Test1.is_possibleRight()) {
        Test1.Read();
        Test1.mediani();
        Test1.inscribed_circle();
    }
    else {
        cout << "Це не прямокутний трикутник!" << endl;
    
    }
   
       
        
    }
    else {
        cout << "Це не трикутник!" << endl;
    }
   
    return 0;
}