
#include "../../idlib/precompiled.h"
#pragma hdrstop


#include "Card.h"

#include "../Game_local.h"

Card::Card()
{
	cardDef = gameLocal.FindEntityDef(cardName);
	playerOnly = cardDef->dict.GetBool("PlayerOnly");
}

Card::~Card()
{
	delete cardName;
	delete cardDef;
	delete displayName;
}

void Card::Play(idActor act)
{
	
}

bool Card::CanPlay(idActor act)
{
	return playerOnly && gameLocal.GetLocalPlayer()->GetInstance() != act.GetInstance();
}

bool Card::operator==(const Card card)
{
	return this->cardName == card.cardName;
}
