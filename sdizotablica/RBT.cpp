#include "stdafx.h"
#include "RBT.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

RBTree::RBTree()
{
	size = 0;
		      
		sentinel.parent = &sentinel;
		sentinel.left = &sentinel;
		sentinel.right = &sentinel;
		sentinel.color = 'temp'; 

	root = &sentinel;          
}

RBTree::RBTree(int i_key)
{

		sentinel.parent = &sentinel;
		sentinel.left = &sentinel;
		sentinel.right = &sentinel;
		sentinel.color = 'temp'; 

	root = &sentinel;         

	switch (i_key){
	case 100:
		size = 100;
		loadFromFile("data/100.txt"); break;
	case 500:
		size = 500;
		loadFromFile("data/500.txt"); break;
	case 1000:
		size = 1000;
		loadFromFile("data/1000.txt"); break;
	case 2000:
		size = 2000;
		loadFromFile("data/2000.txt"); break;
	case 5000:
		size = 5000;
		loadFromFile("data/5000.txt"); break;
	case 20000:
		size = 20000;
		loadFromFile("data/20000.txt"); break;
	default: cout << "in the end it doesnt even matter" << endl;

	}

}

void RBTree::loadFromFile(char url[])
{
	fstream myfile;
	myfile.open(url, ios_base::in);

	int i_target, len = 0;
	while (myfile >> i_target)
	{
		insertRBT(i_target);
	}
	myfile.close();
}

RBTree::~RBTree()
{
	deleteFromNode(root);      
}


void RBTree::printRBT(element * i_parent)
{
	if (i_parent != &sentinel)
	{
		printRBT(i_parent->right);
		cout << "  " << i_parent->color << ":" << i_parent->key << endl;
		printRBT(i_parent->left);
	}
}

void RBTree::deleteFromNode(element * i_parent)
{
	if (i_parent != &sentinel)
	{
		deleteFromNode(i_parent->left);   // usuwam lewe poddrzewo
		deleteFromNode(i_parent->right);  // usuwam prawe poddrzewo
		delete i_parent;              
	}
}


//Wyszukiwarki elementów

element * RBTree::findElement(int i_value)
{
	element * i_parent;
	i_parent = root;

	while ((i_parent != &sentinel) && (i_parent->key != i_value))
		if (i_value < i_parent->key) i_parent = i_parent->left;
		else i_parent = i_parent->right;
		
		if (i_parent == &sentinel) return NULL;
		return i_parent;
}

element * RBTree::minElement(element * i_parent)
{
	if (i_parent != &sentinel)
		while (i_parent->left != &sentinel) i_parent = i_parent->left;
	return i_parent;
}

element * RBTree::sucElement(element * i_parent)
{
	element * r;

	if (i_parent != &sentinel)
	{
		if (i_parent->right != &sentinel) return minElement(i_parent->right);
		else
		{
			r = i_parent->parent;
			while ((r != &sentinel) && (i_parent == r->right))
			{
				i_parent = r;
				r = r->parent;
			}
			return r;
		}
	}
	return &sentinel;
}

//Rotacje

void RBTree::rotateLeft(element *i_target)
{
	element *temp, *i_parent;

	temp = i_target->right;
	if (temp != &sentinel)
	{
		i_parent = i_target -> parent;
		i_target -> right = temp ->left;
		if (i_target -> right != &sentinel) i_target->right->parent = i_target;

		temp->left = i_target;
		temp->parent = i_parent;
		i_target->parent = temp;

		if (i_parent != &sentinel)
		{
			if (i_parent->left == i_target) i_parent->left = temp; else i_parent->right = temp;
		}
		else root = temp;
	}
}

void RBTree::rotateRight(element *i_target)
{
	element * temp, *i_parent;

	temp = i_target->left;
	if (temp != &sentinel)
	{
		i_parent = i_target->parent;
		i_target->left = temp->right;
		if (i_target->left != &sentinel) i_target->left->parent = i_target;

		temp->right = i_target;
		temp->parent = i_parent;
		i_target->parent = temp;

		if (i_parent != &sentinel)
		{
			if (i_parent->left == i_target) i_parent->left = temp; else i_parent->right = temp;
		}
		else root = temp;
	}
}

//Dodawanie

void RBTree::insertRBT(int i_value)
{
	size++;
	element * newElement, *temp;

	newElement = new element;       
	newElement->left = &sentinel;          
	newElement->right = &sentinel;
	newElement->parent = root;
	newElement->key = i_value;

	if (newElement->parent == &sentinel) root = newElement; // newElement staje siê korzeniem
	else
		while (true)            
		{
		if (i_value < newElement->parent->key)
		{
			if (newElement->parent->left == &sentinel)
			{
				newElement->parent->left = newElement;  
				break;
			}
			newElement->parent = newElement->parent->left;
		}
		else
		{
			if (newElement->parent->right == &sentinel)
			{
				newElement->parent->right = newElement; 
				break;
			}
			newElement->parent = newElement->parent->right;
		}
		}
	newElement->color = 'R';        
	while ((newElement != root) && (newElement->parent->color == 'R'))
	{
		if (newElement->parent == newElement->parent->parent->left)
		{
			temp = newElement->parent->parent->right; 

			if (temp->color == 'R')  
			{
				newElement->parent->color = 'temp';
				temp->color = 'temp';
				newElement->parent->parent->color = 'R';
				newElement = newElement->parent->parent;
				continue;
			}

			if (newElement == newElement->parent->right) 
			{
				newElement = newElement->parent;
				rotateLeft(newElement);
			}

			newElement->parent->color = 'temp'; 
			newElement->parent->parent->color = 'R';
			rotateRight(newElement->parent->parent);
			break;
		}
		else  // Przypadki lustrzane
		{                  
			temp = newElement->parent->parent->left;

			if (temp->color == 'R') 
			{
				newElement->parent->color = 'temp';
				temp->color = 'temp';
				newElement->parent->parent->color = 'R';
				newElement = newElement->parent->parent;
				continue;
			}

			if (newElement == newElement->parent->left) 
			{
				newElement = newElement->parent;
				rotateRight(newElement);
			}

			newElement->parent->color = 'temp'; 
			newElement->parent->parent->color = 'R';
			rotateLeft(newElement->parent->parent);
			break;
		}
	}
	root->color = 'temp';
}

//Usuwanie

void RBTree::removeRBT(element * newElement)
{
	element * uncle, *temp, *cousin;

	if ((newElement->left == &sentinel) || (newElement->right == &sentinel)) temp = newElement;
	else                                    temp = sucElement(newElement);

	if (temp->left != &sentinel) cousin = temp->left;
	else              cousin = temp->right;

	cousin->parent = temp->parent;

	if (temp->parent == &sentinel) root = cousin;
	else if (temp == temp->parent->left) temp->parent->left = cousin;
	else                      temp->parent->right = cousin;

	if (temp != newElement) newElement->key = temp->key;

	if (temp->color == 'temp')   // Fix
		while ((cousin != root) && (cousin->color == 'temp'))
			if (cousin == cousin->parent->left)
				{
				uncle = cousin->parent->right;

				if (uncle->color == 'R')
				{              
					uncle->color = 'temp';
					cousin->parent->color = 'R';
					rotateLeft(cousin->parent);
					uncle = cousin->parent->right;
				}

				if ((uncle->left->color == 'temp') && (uncle->right->color == 'temp'))
				{              
					uncle->color = 'R';
					cousin = cousin->parent;
					continue;
				}

				if (uncle->right->color == 'temp')
				{              
					uncle->left->color = 'temp';
					uncle->color = 'R';
					rotateRight(uncle);
					uncle = cousin->parent->right;
				}

				uncle->color = cousin->parent->color;
				cousin->parent->color = 'temp';
				uncle->right->color = 'temp';
				rotateLeft(cousin->parent);

				cousin = root;         // Oszukanie pêtli
			}
			else
			{                // Przypadki lustrzane
				uncle = cousin->parent->left;

				if (uncle->color == 'R')
				{             
					uncle->color = 'temp';
					cousin->parent->color = 'R';
					rotateRight(cousin->parent);
					uncle = cousin->parent->left;
				}

				if ((uncle->left->color == 'temp') && (uncle->right->color == 'temp'))
				{              
					uncle->color = 'R';
					cousin = cousin->parent;
					continue;
				}

				if (uncle->left->color == 'temp')
				{              
					uncle->right->color = 'temp';
					uncle->color = 'R';
					rotateLeft(uncle);
					uncle = cousin->parent->left;
				}

				uncle->color = cousin->parent->color; 
				cousin->parent->color = 'temp';
				uncle->left->color = 'temp';
				rotateRight(cousin->parent);
				cousin = root;    //Ponowne oszukanie pêtli    
			}

	cousin->color = 'temp';
	size--;

	delete temp;
}
