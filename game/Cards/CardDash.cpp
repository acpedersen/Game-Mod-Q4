#include "../../idlib/precompiled.h"
#pragma hdrstop

#include "Card.h"

class CardDash : public Card
{
public:
	CardDash();
	virtual ~CardDash();
	virtual void Play(idActor *actor);
};

CardDash::CardDash()
{

}
CardDash::~CardDash()
{
	Card::~Card();
}

void CardDash::Play(idActor *actor)
{
	Card::Play(actor);

	actor->ApplyImpulse();
}