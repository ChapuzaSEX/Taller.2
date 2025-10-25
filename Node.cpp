//
// Created by chapuza on 21-10-2025.
//

#include "Node.h"

#include <iostream>

Node::Node(int vaule, int xpos, int ypos) {
    this ->Vaule = vaule;
    this ->xPos = xpos;
    this ->yPos = ypos;
}
//Poner a la derecha del nodo
void Node::integrarDerecha(Node *nodo) {
    Node* aux = this;
    aux ->Derecha = nodo;
}
//Cual poner Abajo del ndod
void Node::IntegrarAbajo(Node *nodo) {
    Node* aux = this;
    aux ->Abajo = nodo;
}

int Node::Valude(Node *nodo) {
    int val = nodo -> Vaule;
    return val;
}
void Node::Print() {
    Node* nodo = this;
    std::cout << "("<<nodo ->Vaule <<"/"<<nodo -> xPos<<"/"<<nodo->yPos<<")" <<std::endl;
}

