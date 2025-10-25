//
// Created by chapuza on 21-10-2025.
//

#pragma once


class Node {
public:
    Node(int vaule,int xpos,int ypos);
    int Vaule;
    int xPos;//a los lados
    int yPos;//de arriba a bajo
    Node* Derecha;//funcioana con la x
    Node* Abajo;//funciona con la y
    void integrarDerecha(Node* nodo);
    void IntegrarAbajo(Node* nodo);
    int Valude(Node* nodo);
    void Print();
};