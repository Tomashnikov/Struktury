class element
	{
		friend class RBTree;
		public:
		element * parent;
		element * left;
		element * right;
		int key;
		char color;

	};


class RBTree
{
private:
	
	int size;
	
	element sentinel;             // Wêze³ stra¿nika
		

public:
	element * root;				// Korzeñ drzewa czerwono-czarnego
	RBTree();				// Konstruktor klasy
	RBTree(int i_key);
	~RBTree();				// Destruktor klasy

	void loadFromFile(char url[]);
	void printRBT(element * i_parent);			// Wypisuje drzewo
	void deleteFromNode(element * i_parent);	// Usuwa drzewo od zadanego elementu
	void insertRBT(int i_value);   // Wstawia wêze³ o kluczu k

	element * findElement(int i_value);				// Wyszukuje element o podanej wartosci
	element * minElement(element * i_parent);		// Wyszukuje najmniejszy wêze³ w dzieciach i_parent
	element * sucElement(element * i_parent);		// Wyszukuje nastêpnik rodzica

	void rotateLeft(element * i_target); // Rotacja w lewo wzglêdem celu
	void rotateRight(element * i_target); // Rotacja w prawo wzglêdem celu
	


	void removeRBT(element * X); // Usuwa wêze³ X
};