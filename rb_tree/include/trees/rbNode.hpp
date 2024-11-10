/*
 * abbNode.h
 *
 *  Created on: Sep 2, 2022
 *      Author: jsaavedr
 */

#ifndef RBNODE_HPP_
#define RBNODE_HPP_

namespace trees {

enum NodeType{
	LEFT = 10,
	RIGHT = 20
};

enum NodeColor{
	RED = 10,
	BLACK = 20
};


class RBNode {
private:
	int data;               // valor del nodo
    RBNode* ptrLeft;        // puntero al hijo izquierdo
    RBNode* ptrRight;       // puntero al hijo derecho
    RBNode* parent;         // puntero al nodo padre
    NodeColor color;        // color del nodo: RED o BLACK
    NodeType type;          // tipo de nodo: LEFT o RIGHT


public:
	RBNode();
	RBNode(int val, RBNode* _parent = nullptr);

	 // Métodos para establecer y obtener atributos del nodo
	void setLeft(RBNode* node);
	void setRight(RBNode* node);
	void setParent(RBNode* node);
	void setData(int val);	
	void setType(NodeType t);
	void setColor(NodeColor t);

	// Métodos para obtener información del nodo
	bool isLeft();
	bool isRight();
	RBNode* getLeft();
	RBNode* getRight();
	RBNode* getParent();
	int getData();	
	char getColor();	// devuelve 'R' o 'B' según el color
    char getType();    // devuelve 'L' o 'R' según el tipo

	virtual ~RBNode();
};

} /* namespace trees */

#endif /* RBNODE_H_ */
