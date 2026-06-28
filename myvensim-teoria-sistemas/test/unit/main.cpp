#include "unit_Model.h"
#include "unit_Flow.h"
#include "unit_System.h"
#include "unit_HandleBody.h"
#include <iostream>
#include <cassert>
#include "unit_test.h"
using namespace std;

int main()
{
    cout << "Running unit tests..." << endl;
        
    cout << "handleBody tests: ";
    mainHandleBody();
    cout << "OK" << endl;

    cout << "System tests: ";
    run_unit_test_System();
    cout << "OK" << endl;

    cout << "Flow tests: ";
    run_unit_test_Flow();
    cout << "OK" << endl;

    cout << "Model tests: ";
    run_unit_test_Model();
    cout << "OK" << endl;


    cout << "All unit tests succeed." << endl;
    
    return 0;
}