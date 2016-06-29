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
	
	element sentinel;             // W�ze� stra�nika
		

public:
	element * root;				// Korze� drzewa czerwono-czarnego
	RBTree();				// Konstruktor klasy
	RBTree(int i_key);
	~RBTree();				// Destruktor klasy

	void loadFromFile(char url[]);
	void printRBT(element * i_parent);			// Wypisuje drzewo
	void deleteFromNode(element * i_parent);	// Usuwa drzewo od zadanego elementu
	void insertRBT(int i_value);   // Wstawia w�ze� o kluczu k

	element * findElement(int i_value);				// Wyszukuje element o podanej wartosci
	element * minElement(element * i_parent);		// Wyszukuje najmniejszy w�ze� w dzieciach i_parent
	element * sucElement(element * i_parent);		// Wyszukuje nast�pnik rodzica

	void rotateLeft(element * i_target); // Rotacja w lewo wzgl�dem celu
	void rotateRight(element * i_target); // Rotacja w prawo wzgl�dem celu
	


	void removeRBT(element * X); // Usuwa w�ze� X
};