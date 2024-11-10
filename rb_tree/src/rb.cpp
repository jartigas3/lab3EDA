/*
 * abb.cpp
 *
 *  Created on: Sep 2, 2022
 *      Author: jsaavedr
 */

#include "trees/rb.hpp"
#include <iostream>


namespace trees {

RB::RB():root(nullptr) {
	// TODO Auto-generated constructor stub
}

void RB::balance(RBNode* node) {
    while (node != root && node->getParent()->getColor() == RED) {
        RBNode* parent = node->getParent();
        RBNode* grandparent = parent->getParent();

        if (parent == grandparent->getLeft()) {
            // El tío es el hijo derecho del abuelo
            RBNode* uncle = grandparent->getRight();
            
            // Caso 2: El tío es rojo
            if (uncle != nullptr && uncle->getColor() == RED) {
                parent->setColor(BLACK);
                uncle->setColor(BLACK);
                grandparent->setColor(RED);
                node = grandparent;  // Subimos el nodo para verificar la estructura más arriba
            }
            else {
                // Caso 3: El tío es negro o nulo y el nodo es el hijo derecho
                if (node == parent->getRight()) {
                    node = parent;
                    leftRotate(node);  // Rotación izquierda
                }
                // Ajustamos para caso 3: El tío es negro o nulo y el nodo es el hijo izquierdo
                parent->setColor(BLACK);
                grandparent->setColor(RED);
                rightRotate(grandparent);  // Rotación derecha
            }
        } 
        else {
            // El padre es hijo derecho del abuelo; el tío es el hijo izquierdo del abuelo
            RBNode* uncle = grandparent->getLeft();

            // Caso 2: El tío es rojo
            if (uncle != nullptr && uncle->getColor() == RED) {
                parent->setColor(BLACK);
                uncle->setColor(BLACK);
                grandparent->setColor(RED);
                node = grandparent;  // Subimos el nodo para verificar la estructura más arriba
            }
            else {
                // Caso 3: El tío es negro o nulo y el nodo es el hijo izquierdo
                if (node == parent->getLeft()) {
                    node = parent;
                    rightRotate(node);  // Rotación derecha
                }
                // Ajustamos para caso 3: El tío es negro o nulo y el nodo es el hijo derecho
                parent->setColor(BLACK);
                grandparent->setColor(RED);
                leftRotate(grandparent);  // Rotación izquierda
            }
        }
    }

    // Aseguramos que la raíz siempre sea negra
    root->setColor(BLACK);
}

RotationType RB::getRotationType(RBNode* node){
	/*this will run if node is unbalanced*/
	RotationType rType = RotationType::case_1;
	//TODO
	return rType;
}

// void RB::do_case_1(RBNode* node){
// 	//TODO
// }


void RB::insert(int val) {
    // Método principal de inserción
    if (root == nullptr) {
        // Si el árbol está vacío, creamos la raíz y la configuramos como negra
        root = new RBNode(val);
        root->setColor(BLACK);
    } else {
        // Si no está vacío, llamamos a la función recursiva de inserción
        insert(val, root);
    }
}

void RB::insert(int val, RBNode* node) {
    RBNode* new_node = nullptr;

    if (val < node->getData()) {
        if (node->getLeft() == nullptr) {
            // Insertamos el nodo como hijo izquierdo si el espacio está disponible
            new_node = new RBNode(val, node);
            node->setLeft(new_node);
            new_node->setColor(RED); // Los nuevos nodos siempre se insertan como rojos
        } else {
            // Continuamos la inserción recursivamente por la izquierda
            insert(val, node->getLeft());
        }
    } else {
        if (node->getRight() == nullptr) {
            // Insertamos el nodo como hijo derecho si el espacio está disponible
            new_node = new RBNode(val, node);
            node->setRight(new_node);
            new_node->setColor(RED); // Los nuevos nodos siempre se insertan como rojos
        } else {
            // Continuamos la inserción recursivamente por la derecha
            insert(val, node->getRight());
        }
    }

	balance(new_node);

}


// Método para realizar una rotación a la izquierda
void RB::leftRotate(RBNode* node) {
    RBNode* rightChild = node->getRight();

    // Cambiamos el hijo izquierdo de rightChild a ser el hijo derecho de node
    node->setRight(rightChild->getLeft());
    if (rightChild->getLeft() != nullptr) {
        rightChild->getLeft()->setParent(node);
    }

    // Ajustamos el padre de rightChild para que sea el padre de node
    rightChild->setParent(node->getParent());
    if (node->getParent() == nullptr) {
        root = rightChild;  // Si node es la raíz, actualizamos la raíz
    } else if (node == node->getParent()->getLeft()) {
        node->getParent()->setLeft(rightChild);
    } else {
        node->getParent()->setRight(rightChild);
    }

    // Ajustamos la relación entre node y rightChild
    rightChild->setLeft(node);
    node->setParent(rightChild);
}

// Método para realizar una rotación a la derecha
void RB::rightRotate(RBNode* node) {
    RBNode* leftChild = node->getLeft();

    // Cambiamos el hijo derecho de leftChild a ser el hijo izquierdo de node
    node->setLeft(leftChild->getRight());
    if (leftChild->getRight() != nullptr) {
        leftChild->getRight()->setParent(node);
    }

    // Ajustamos el padre de leftChild para que sea el padre de node
    leftChild->setParent(node->getParent());
    if (node->getParent() == nullptr) {
        root = leftChild;  // Si node es la raíz, actualizamos la raíz
    } else if (node == node->getParent()->getRight()) {
        node->getParent()->setRight(leftChild);
    } else {
        node->getParent()->setLeft(leftChild);
    }

    // Ajustamos la relación entre node y leftChild
    leftChild->setRight(node);
    node->setParent(leftChild);
}



RBNode* RB::find(int val, RBNode* node){
	RBNode* ans = nullptr;
	if (node->getData() == val){
		ans = node;
	}
	else{
		if (val < node->getData()){
			find(val, node->getLeft());
		}
		else{
			find(val, node->getRight());
		}
	}
	return ans;
}

RBNode* RB::find(int val){
	RBNode* ans = nullptr;
	ans = find(val, root);
	return ans;
}

void RB::traverse(RBNode* node, int label){
	if (node != nullptr){
		for (int i = 0; i < label; i++){
			std::cout << "*" << std::flush;
		}
		char T = node->isLeft()?'L':'R';
		std::cout << node->getData() << "  " << T <<std::endl;
		traverse(node->getLeft(), label + 1);
		traverse(node->getRight(), label + 1);
	}
}

void RB::traverse(){
	traverse(root, 1);
}


RB::~RB() {
	delete root;
}

} /* namespace trees */
