
#include "../../idlib/precompiled.h"
#pragma hdrstop


#include "Card.h"


#include "../Game_local.h"

Card::Card()
{
	cardDef = gameLocal.FindEntityDef(cardName);

}

Card::~Card()
{

}

void Card::Play(idActor *act)
{

}

Card Card::GetCard(idStr cardId)
{

}
