#include "../../idlib/precompiled.h"
#pragma hdrstop

#include "Card.h"


class CardInvisibility : public Card
{
public:

	CLASS_PROTOTYPE(CardInvisibility);

	CardInvisibility();
	virtual ~CardInvisibility();
	virtual void Play(idActor act);

protected:
	int duration;
};

CLASS_DECLARATION(Card, CardInvisibility)
END_CLASS

CardInvisibility::CardInvisibility()
: Card("card_invisibility")
{
	duration = cardDef->dict.GetInt("duration", "10");

}
CardInvisibility::~CardInvisibility()
{

}

void CardInvisibility::Play(idActor act)
{
	if (!CanPlay(act)) //Check if the card can be played
		return;

	Card::Play(act);

	gameLocal.GetLocalPlayer()->GivePowerUp(POWERUP_INVISIBILITY, duration);
}