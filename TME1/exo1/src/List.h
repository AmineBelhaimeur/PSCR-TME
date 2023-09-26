#ifndef SRC_LIST_H_
#define SRC_LIST_H_

#include <cstddef>
#include <string>
#include <ostream>

namespace pr {

class Chainon {
public :
	std::string data;
	Chainon * next;
	Chainon (const std::string & data, Chainon * next=nullptr);
	size_t length() ;
	void print (std::ostream & os) const;
};

class List {
public:

	Chainon * tete;

	List(): tete(nullptr)  {}

	~List() {
	    for (Chainon *c = tete; c;) {
	        Chainon *tmp = c->next;
	        delete c;
	        c = tmp;
	    }
	    tete = nullptr;  //FAUTE: Pointeur suspendu. Le définir à nullptr.
	}


	const std::string & operator[] (size_t index) const ;

	void push_back (const std::string& val) ;

	// FAUTE: Double définition de push_front
	// void push_front(const std::string& val) {
	//     tete = new Chainon(val, tete);
	// }
	// Retirez-en une.

	void push_front(const std::string& val);

	// FAUTE: Type de retour manquant pour la fonction empty
	// bool empty();
	bool empty() const;

	size_t size() const ;
};


std::ostream & operator<< (std::ostream & os, const List & vec) ;

} /* namespace pr */

#endif /* SRC_LIST_H_ */
