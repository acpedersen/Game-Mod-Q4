#include "../../idlib/precompiled.h"
#pragma hdrstop

#include "Card.h"


class CardGrenade : public Card
{
public:

	CLASS_PROTOTYPE(CardGrenade);

	CardGrenade();
	virtual ~CardGrenade();
	virtual void Play(idActor act);
};

CLASS_DECLARATION(Card, CardGrenade)
END_CLASS

CardGrenade::CardGrenade()
: Card("card_grenade")
{

}
CardGrenade::~CardGrenade()
{

}

void CardGrenade::Play(idActor act)
{
	if (!CanPlay(act)) //Check if the card can be played
		return;

	Card::Play(act);


}