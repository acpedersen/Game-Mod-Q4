#include "../../idlib/precompiled.h"
#pragma hdrstop

#include "Card.h"


class CardImpulse : public Card
{
public:

	CLASS_PROTOTYPE(CardImpulse);

	CardImpulse();
	virtual ~CardImpulse();
	virtual void Play(idActor act);
protected:
	int impulse;
};

CLASS_DECLARATION(Card, CardImpulse)
END_CLASS

CardImpulse::CardImpulse()
: Card("card_impulse")
{
	impulse = cardDef->dict.GetFloat("impulse", "1.0");
}
CardImpulse::~CardImpulse()
{

}

void CardImpulse::Play(idActor act)
{
	if (!CanPlay(act)) //Check if the card can be played
		return;

	Card::Play(act);


}