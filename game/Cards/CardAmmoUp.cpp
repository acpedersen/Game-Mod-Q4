#include "../../idlib/precompiled.h"
#pragma hdrstop

#include "Card.h"


class CardAmmoUp : public Card
{
public:

	CLASS_PROTOTYPE(CardAmmoUp);

	CardAmmoUp();
	virtual ~CardAmmoUp();
	virtual void Play(idActor act);

protected:
	float ammoRefillPercentage;
};

CLASS_DECLARATION(Card, CardAmmoUp)
END_CLASS

CardAmmoUp::CardAmmoUp()
: Card("card_ammo_up")
{
	ammoRefillPercentage = cardDef->dict.GetFloat("ammo_percentage", "1.0");
}
CardAmmoUp::~CardAmmoUp()
{

}

void CardAmmoUp::Play(idActor act)
{
	if (!CanPlay(act)) //Check if the card can be played
		return;

	Card::Play(act);


}