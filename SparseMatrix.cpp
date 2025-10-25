

#include "SparseMatrix.h"

#include <iostream>
#include <ostream>
//se crea un nodo de cordenan 0,0
SparseMatrix::SparseMatrix() {
    int vaule = 0;
    Node* nexo = new Node(vaule,0,0);
    this ->start = nexo;
    nexo-> IntegrarAbajo(nexo);
    nexo -> integrarDerecha(nexo);
}
                                    //bajo   //Dercha
void SparseMatrix::add(int value, int xPos, int yPos) {
    Node* nexo = this -> start;
    Node* indice= this->start;
    Node* NuevoNodo = new Node(value,xPos,yPos);
    NuevoNodo -> IntegrarAbajo(NuevoNodo);
    Node* anterior;
    bool motor = true;
    while (motor) {
        //colimna encontrada
        if (NuevoNodo ->xPos == indice->xPos) {
            Node* indice2 = indice;
            Node* anterior2;
            while (motor) {
                // listra vacia y nueva cabezera
                if (indice2 -> Abajo ==indice) {
                    NuevoNodo -> Abajo = indice2->Abajo;
                    indice2 ->Abajo = NuevoNodo;
                    motor = false;
                }
                //si hay que poner un nodo entre nodos
                if (indice2 -> yPos < NuevoNodo -> yPos and (indice2 ->Abajo )-> yPos > NuevoNodo -> yPos) {
                    NuevoNodo->Abajo = indice2 -> Abajo;
                    indice2 -> Abajo = NuevoNodo;
                    motor=false;
                }

                if (indice -> yPos > NuevoNodo -> yPos and anterior2 != nullptr) {
                    NuevoNodo -> Abajo = indice;
                    anterior -> Derecha = NuevoNodo;
                    NuevoNodo->Derecha = indice -> Derecha;
                    Node* buscador = indice2;
                    while (motor) {
                        if (buscador -> Abajo == indice) {
                            buscador -> Abajo = NuevoNodo;
                            motor = false;
                        }
                        buscador = buscador ->Abajo;
                    }

                }
                //si hay que cambiar la cabecera

                anterior2 = indice2;
                indice2 = indice2 ->Abajo;
            }
        }
        else {

                if (indice->Derecha == indice) {
                    indice->Derecha = NuevoNodo;
                    NuevoNodo -> Derecha = indice;
                    motor = false;
                }
                if (indice->Derecha == nexo) {
                    indice->Derecha = NuevoNodo;
                    NuevoNodo -> Derecha = nexo;
                    motor = false;
                }
                if ((indice->Derecha)->xPos > NuevoNodo->xPos and indice ->xPos < NuevoNodo->xPos) {
                    NuevoNodo -> Derecha = indice->Derecha;
                    indice->Derecha = NuevoNodo;
                    motor = false;
                }


        }
        anterior = indice;
        indice = indice ->Derecha;

    }

}
void SparseMatrix::printStoredValues(){
    Node* indice = this->start;
    bool motor = true;
    while (motor) {
        indice -> Print();
        if (indice -> Abajo != indice) {
            Node* aux = indice->Abajo;
            bool motor2 = true;
            while (motor2) {
                aux -> Print();
                aux = aux -> Abajo;
                if (aux == indice) {
                    motor2=false;
                }
            }
        }
        indice = indice -> Derecha;
        if (indice == this->start) {
            motor = false;
        }
    }
}
int SparseMatrix::get(int Pocicionx, int pociciony) {
    Node* indice = this->start;
    int valor = 0;
    bool motor = true;
    while (motor) {
        bool motor2 = true;
        if (indice ->xPos == Pocicionx) {
            Node* indice2=indice;
            while (motor) {
                if (indice2 ->yPos == pociciony) {
                    valor = indice2 -> Vaule;
                    motor = false;
                }
                indice2 = indice2 -> Abajo;
                if (indice2 -> Abajo == indice) {
                    motor2 = false;
                }
            }
        }
        indice = indice -> Derecha;
        if (indice == this->start) {
            motor = false;
        }

    }
    return valor;
}
void SparseMatrix::remove(int Pocicionx, int pociciony) {
    Node* indice = this->start;
    Node* anterior ;
    bool motor = true;
    while (motor) {
        if (indice ->xPos == Pocicionx) {
            Node* indice2=indice;
            Node* anterior2;
            while (motor) {
                if (indice2 ->yPos == pociciony) {
                    if (indice2 ->Derecha != nullptr) {
                        Node* abajo = indice -> Abajo;
                        abajo -> Derecha = indice -> Derecha;
                        anterior -> Derecha = abajo;
                        Node* buscador = indice2;
                        bool motor2 = true;
                        while (motor2) {
                            if (buscador -> Abajo == indice) {
                                buscador -> Abajo = abajo;
                                motor2 = false;
                            }
                            buscador = buscador -> Abajo;
                        }
                        delete indice2;

                    }
                    if (indice2 -> Derecha == nullptr) {
                        anterior2 ->Abajo = indice2 -> Abajo;
                        indice2 ->Abajo = nullptr;
                        delete indice2;
                        motor = false;
                    }
                }
                anterior2 = indice2;
                indice2 = indice2 -> Abajo;
                if (indice2 -> Abajo == indice) {
                    motor = false;
                }
            }
        }
        anterior = indice;
        indice = indice -> Derecha;
        if (indice == this->start) {
            motor = false;
        }

    }
}

