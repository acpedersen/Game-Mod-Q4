#include "../../idlib/precompiled.h"
#pragma hdrstop

#include "Card.h"


class CardDash : public Card
{
public:
	CardDash();
	virtual ~CardDash();
	virtual void Play(idActor act);
};

CardDash::CardDash()
{
	cardName = "card_dash";

}
CardDash::~CardDash()
{

}

void CardDash::Play(idActor act)
{
	Card::Play(act);

	idVec3 impulse = act.GetPhysics()->GetOrigin() * 5;
	//act->

	act.ApplyImpulse(&act, 0, act.GetPhysics()->GetOrigin(), impulse);
}