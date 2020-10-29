#include "../../idlib/precompiled.h"
#pragma hdrstop

#include "Card.h"


class CardQuadDamage : public Card
{
public:

	CLASS_PROTOTYPE(CardQuadDamage);

	CardQuadDamage();
	virtual ~CardQuadDamage();
	virtual void Play(idActor act);

protected:
	int duration;
};

CLASS_DECLARATION(Card, CardQuadDamage)
END_CLASS

CardQuadDamage::CardQuadDamage()
: Card("card_quad_damage")
{
	duration = cardDef->dict.GetInt("duration", "5");
}
CardQuadDamage::~CardQuadDamage()
{

}

void CardQuadDamage::Play(idActor act)
{
	if (!CanPlay(act)) //Check if the card can be played
		return;

	Card::Play(act);

	gameLocal.GetLocalPlayer()->GivePowerUp(POWERUP_QUADDAMAGE, duration);
}