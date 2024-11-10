/*
 * abb.hpp
 *
 *  Created on: Sep 2, 2022
 *      Author: jsaavedr
 */

#ifndef RB_HPP_
#define RB_HPP_

#include "trees/rbNode.hpp"

namespace trees {


// Enumeración para los casos de rotación y balanceo
enum RotationType{
	case_1 = 10,
	case_2 = 20,
	case_3 = 30,
	case_4 = 40,
	//you can or should add more cases 
};

class RB {
private:
	RBNode* root;  // puntero a la raíz del árbol

    // Métodos privados para balancear el árbol y manejar rotaciones
    void balance(RBNode* node);
    RotationType getRotationType(RBNode* node);

	void leftRotate(RBNode* node);
	void rightRotate(RBNode* node);		

    // Placeholder para los casos de balanceo específicos
    // void do_case_1(RBNode* node);
    // void do_case_2(RBNode* node);
    // ...

public:
	RB();

	 // Métodos de inserción y búsqueda
	void insert(int val, RBNode* node);
	void insert(int val);
	RBNode* find(int val, RBNode* node);
	RBNode* find(int val);

	  // Método para recorrer el árbol e imprimir su estructura
	void traverse(RBNode* node, int level);
	void traverse();

	virtual ~RB();
};

} /* namespace trees */

#endif /* RB_HPP_ */
