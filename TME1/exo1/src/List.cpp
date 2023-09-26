#include "List.h"
#include <iostream>
#include <string>

namespace pr {

// ******************* Chainon
Chainon::Chainon (const std::string & data, Chainon * next):data(data),next(next) {};

size_t Chainon::length() {
	size_t len = 1;
	if (next != nullptr) {
		len += next->length();
	}
	// FAUTE : Récurssion infinie dans Chainon::length
	// return length();
	return len;
}

void Chainon::print (std::ostream & os) const {
	os << data ;
	// FAUTE : Déférencement d'un nullptr si next est nullptr
	if (next != nullptr) {
		os << ", ";
	    next->print(os);

	}
}

// ******************  List
const std::string & List::operator[] (size_t index) const  {
	Chainon * it = tete;
	for (size_t i=0; i < index ; i++) {
		it = it->next;
	}
	return it->data;
}

void List::push_back (const std::string& val) {
	if (tete == nullptr) {
		tete = new Chainon(val);
	} else {
		Chainon * fin = tete;
		while (fin->next) {
			fin = fin->next;
		}
		fin->next = new Chainon(val);
	}
}

void pr::List::push_front(const std::string& val) {
	tete = new Chainon(val,tete);
}

// FAUTE: Définition de fonction hors de la classe sans opérateur de résolution de portée
// bool empty() {
bool List::empty() const{

	return tete == nullptr;
}

size_t List::size() const {
	if (tete == nullptr) {
		return 0;
	} else {
		return tete->length();
	}
}

} // namespace pr

std::ostream & pr::operator<< (std::ostream & os, const pr::List & vec)
{
	os << "[";
	if (vec.tete != nullptr) {
		vec.tete->print (os) ;
	}
	os << "]";
	return os;
}
