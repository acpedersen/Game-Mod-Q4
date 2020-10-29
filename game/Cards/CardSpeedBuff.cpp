#include "../../idlib/precompiled.h"
#pragma hdrstop

#include "Card.h"


class CardSpeedBuff : public Card
{
public:

	CLASS_PROTOTYPE(CardSpeedBuff);

	CardSpeedBuff();
	virtual ~CardSpeedBuff();
	virtual void Play(idActor act);

protected:
	int duration;
};

CLASS_DECLARATION(Card, CardSpeedBuff)
END_CLASS

CardSpeedBuff::CardSpeedBuff()
: Card("card_speed_buff")
{
	duration = cardDef->dict.GetInt("duration", "10");
}
CardSpeedBuff::~CardSpeedBuff()
{

}

void CardSpeedBuff::Play(idActor act)
{
	if (!CanPlay(act)) //Check if the card can be played
		return;

	Card::Play(act);

	gameLocal.GetLocalPlayer()->GivePowerUp(POWERUP_HASTE, duration);
}