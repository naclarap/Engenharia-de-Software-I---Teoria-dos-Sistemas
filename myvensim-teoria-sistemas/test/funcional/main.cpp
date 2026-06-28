#define FUNCTIONAL

#ifdef FUNCTIONAL
    #include "funcional_tests.h"

    int main()
    {
        exponentialFuncionalTest();
        logisticalFuncionalTest();
        complexFuncionalTest();

        cout << "All functional tests succeed." << endl;

        return 0;
    }
#endif