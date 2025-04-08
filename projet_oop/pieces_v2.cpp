#include <vector>
#include <iostream>

static int nbrRois = 0;
int const tailleEchequier = 8;

struct Emplacement {
	char lettre;
	int entier;
	int translatePosition() {
		return int(lettre) - int('a');
	}
};

struct EtatDuCase {
	char couleur;
	char piece;
};

class Case {
public:
	Case() :etat_({ 'V', 'V' }), emplacement_({'a', 0}) {};
	Case(EtatDuCase etat, Emplacement emplacement) :etat_(etat), emplacement_(emplacement){};
	void setCase(EtatDuCase etat, Emplacement emplacement) {
		etat_ = etat;
		emplacement_ = emplacement;
		if (etat_.piece == 'R') {
			if (nbrRois <= 2)
				++nbrRois;
			else {
				//better exception
				nbrRois = 9;
			}
		}
	}
	bool mouvementLegal(Emplacement emplacementFinal) {
		switch (etat_.piece)
		{
		case 'R':
			if (abs(emplacementFinal.entier - emplacement_.entier) == 1 && emplacement_.translatePosition() == emplacementFinal.translatePosition())
				return true;
			else if (abs(emplacementFinal.translatePosition() - emplacement_.translatePosition()) == 1 && emplacement_.entier == emplacementFinal.entier)
			{
				return true;
			}
			else if (abs(emplacementFinal.entier - emplacement_.entier) == 1 && abs(emplacement_.translatePosition() - emplacementFinal.translatePosition()) == 1)
			{
				return true;
			}
			else return false;
		case 'T':
			if (emplacement_.entier == emplacementFinal.entier || emplacement_.translatePosition() == emplacementFinal.translatePosition())
				return true;
			else
				return false;
		case 'C':
			if (abs(emplacementFinal.entier - emplacement_.entier) == 3 && abs(emplacementFinal.translatePosition() - emplacement_.translatePosition()) == 2)
				return true;
			else if (abs(emplacementFinal.entier - emplacement_.entier) == 2 && abs(emplacementFinal.translatePosition() - emplacement_.translatePosition()) == 3)
				return true;
			else
				return false;
		default:
			return false;
		}
	}
	void operator=(const Case& autre) {
		etat_ = autre.etat_;
		emplacement_ = autre.emplacement_;
	}
	EtatDuCase getEtat() const { return etat_; }
private:
	EtatDuCase etat_;
	Emplacement emplacement_;
};

class Echequier {
public:
	Echequier() {
		cases_[4][0].setCase({ 'B', 'R' }, {'e', 0});
		cases_[4][7].setCase({ 'N', 'R' }, {'e', 7});
		cases_[0][0].setCase({ 'B', 'T' }, {'a', 0});
		cases_[7][0].setCase({ 'B', 'T' }, {'h', 0});
		cases_[0][7].setCase({ 'N', 'T' }, {'a', 7});
		cases_[7][7].setCase({ 'N', 'T' }, {'h', 7});
		cases_[2][0].setCase({ 'B', 'C' }, {'b', 0});
		cases_[6][0].setCase({ 'B', 'C' }, {'g', 0});
		cases_[2][7].setCase({ 'N', 'C' }, {'b', 7});
		cases_[6][7].setCase({ 'N', 'C' }, {'g', 7});
	};
	void bougerPiece(Emplacement emplacementActuel, Emplacement emplacementFutur){
		cases_[emplacementFutur.translatePosition()][emplacementFutur.entier] = cases_[emplacementActuel.translatePosition()][emplacementActuel.entier];
	}
	Case getCase(Emplacement emplacement) {
		return cases_[emplacement.translatePosition()][emplacement.entier];
	}
private:
	Case cases_[tailleEchequier][tailleEchequier];
};

// Comment devrait etre l'implementation de ca?
class VerificationMouvement {

};

int main() {
	Echequier echequier;
	Case a = echequier.getCase({'c', 0});
	std::cout << a.mouvementLegal({'b', 6});
};