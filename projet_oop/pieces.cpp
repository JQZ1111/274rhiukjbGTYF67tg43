
static bool roiOuNon = false;

struct Emplacement {
	char lettre;
	int entier;
};

class Piece {
public:
	Piece();
	void setProchainEmplacement();
private:
	bool estBlanc_;
protected:
	Emplacement emplacementActuel_;
	Emplacement emplacementApresDeplacement_;
};

class Roi :public Piece {
public:
	Roi();
	bool mouvementBloquerOuNon();
	bool mouvementAllouerOuNon();
	bool mouvementEnDehorsOuNon();
private:
	bool mouvementLegal_;
};

// Commet savoir si un  mouvement ne nous met pas en echec? verification de tt les autres pieces?
class Tour:public Piece {
public:
	Tour();
	bool mouvementBloquerOuNon();
	bool mouvementAllouerOuNon();
	bool mouvementEnDehorsOuNon();
private:
	bool mouvementLegal_;
	bool protegeRoi_;
};

class Cavalier:public Piece {
public:
	Cavalier();
	bool mouvementBloquerOuNon();
	bool mouvementAllouerOuNon();
	bool mouvementEnDehorsOuNon();
private:
	bool mouvementLegal_;
	bool protegeRoi_;
};

class RessourceManager {
public:

private:

};