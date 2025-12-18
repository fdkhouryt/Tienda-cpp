#ifndef ISUSCRIPTOR_H_
#define ISUSCRIPTOR_H_

#include "../datatype/DTPromocion.h"

class ISuscriptor {
public:
	virtual ~ISuscriptor(){};
	virtual	void notificar(DTNotificacion noti)=0;
};

#endif /* SUSCRIPTOR_H_ */