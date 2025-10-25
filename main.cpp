#include "SparseMatrix.h"
#include <iostream>
int main(){
    SparseMatrix* matrix=new SparseMatrix();

    matrix->add(1,1,1);
    matrix->add(2,1,2);
    matrix->add(3,1,4);
    matrix->add(3,1,3);
    matrix->add(6,1,0);
    matrix->printStoredValues();
    //matrix->remove(1,2);
    std::cout<<"eliminado"<<std::endl;
    matrix->printStoredValues();
    return 0;
}