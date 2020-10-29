#include "../../idlib/precompiled.h"
#pragma hdrstop

#include "Card.h"


class CardHeal : public Card
{
public:

	CLASS_PROTOTYPE(CardHeal);

	CardHeal();
	virtual ~CardHeal();
	virtual void Play(idActor act);

protected:
	int health;
};

CLASS_DECLARATION(Card, CardHeal)
END_CLASS

CardHeal::CardHeal()
: Card("card_heal")
{
	health = cardDef->dict.GetInt("health", "10");

}
CardHeal::~CardHeal()
{

}

void CardHeal::Play(idActor act)
{
	if (!CanPlay(act)) //Check if the card can be played
		return;

	Card::Play(act);

	gameLocal.GetLocalPlayer()->health += health;
}