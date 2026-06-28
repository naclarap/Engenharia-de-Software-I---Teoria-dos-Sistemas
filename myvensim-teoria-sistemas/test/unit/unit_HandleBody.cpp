#include <iostream>
#include <assert.h>
#include <cstdlib>
#include <iostream>
#include "unit_handleBody.h"
#include "../../src/counts.h"
#include "unit_test.h"
using namespace std;

void mainHandleBody() {
    numHandleCreated = 0;
    numHandleDeleted = 0;
    numBodyCreated = 0;
    numBodyDeleted = 0;
    Model* m = Model::createModel("teste");

    System* s1 = m->createSystem("populacao", 10.0);
    System* s2 = m->createSystem("Teste", 7.90);
    s1->setValue(s1->getValue());
    s2->setValue(s2->getValue());
    
    assert(numHandleCreated == 3);
    assert(numBodyCreated == 3);
    assert(numBodyDeleted == 0);
    assert(numHandleDeleted == 0);

    numHandleCreated = 0;
    numHandleDeleted = 0;
    numBodyCreated = 0;
    numBodyDeleted = 0;

    SystemHandle s3("Ana", 7), s4("Clara", 8);
    assert(numHandleCreated == 2);
    assert(numBodyCreated == 2);
    assert(numBodyDeleted == 0);
    assert(numHandleDeleted == 0);

    s3 = s4;

    assert(numHandleCreated == 2);
    assert(numBodyCreated == 2);
    assert(numBodyDeleted == 1);
    assert(numHandleDeleted == 0);
}
