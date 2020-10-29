#include "../../idlib/precompiled.h"
#pragma hdrstop

#include "Card.h"


class CardWeaponSwap : public Card
{
public:

	CLASS_PROTOTYPE(CardWeaponSwap);

	CardWeaponSwap();
	virtual ~CardWeaponSwap();
	virtual void Play(idActor act);
};

CLASS_DECLARATION(Card, CardWeaponSwap)
END_CLASS

CardWeaponSwap::CardWeaponSwap()
: Card("card_weapon_swap")
{

}
CardWeaponSwap::~CardWeaponSwap()
{

}

void CardWeaponSwap::Play(idActor act)
{
	if (!CanPlay(act)) //Check if the card can be played
		return;

	Card::Play(act);


}