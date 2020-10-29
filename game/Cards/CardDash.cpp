#include "../../idlib/precompiled.h"
#pragma hdrstop

#include "Card.h"


class CardDash : public Card
{
public:

	CLASS_PROTOTYPE(CardDash);

	CardDash();
	virtual ~CardDash();
	virtual void Play(idActor act);

protected:
	int impulseValue;
};

CLASS_DECLARATION(Card, CardDash)
END_CLASS

CardDash::CardDash()
: Card("card_dash")
{
	impulseValue = cardDef->dict.GetInt("impulse", "1");
}
CardDash::~CardDash()
{

}

void CardDash::Play(idActor act)
{
	if (!CanPlay(act)) //Check if the card can be played
		return;

	Card::Play(act);

	idVec3 impulse = act.GetPhysics()->GetOrigin() * impulseValue;
	//act->

	act.ApplyImpulse(&act, 0, act.GetPhysics()->GetOrigin(), impulse);
}