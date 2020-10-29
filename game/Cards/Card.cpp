
#include "../../idlib/precompiled.h"
#pragma hdrstop


#include "Card.h"

#include "../Game_local.h"

CLASS_DECLARATION(idClass, Card)
END_CLASS

Card::Card(idStr cardName)
{
	this->cardName = cardName;
	cardDef = gameLocal.FindEntityDef(cardName);
	descriptionText = cardDef->dict.GetString("description_text", "");
	playerOnly = cardDef->dict.GetBool("player_only");
}

Card::~Card()
{
	delete cardName;
	delete cardDef;
	delete displayName;
}

Card Card::GetCard(idStr cardId)
{
	idTypeInfo*	typeInfo;
	if (idStr::Icmp(cardId, "card_dash")==0)
	{
		typeInfo = idClass::GetClass("CardDash");
	}
	else if (idStr::Icmp(cardId, "card_weapon_swap") == 0)
	{
		typeInfo = idClass::GetClass("CardWeaponSwap");
	}
	else if (idStr::Icmp(cardId, "card_grenade") == 0)
	{
		typeInfo = idClass::GetClass("CardGrenade");
	}
	else if (idStr::Icmp(cardId, "card_impulse") == 0)
	{
		typeInfo = idClass::GetClass("CardImpulse");
	}
	else if (idStr::Icmp(cardId, "card_quad_damage") == 0)
	{
		typeInfo = idClass::GetClass("CardQuadDamage");
	}
	else if (idStr::Icmp(cardId, "card_speed_buff") == 0)
	{
		typeInfo = idClass::GetClass("CardSpeedBuff");
	}
	else if (idStr::Icmp(cardId, "card_heal") == 0)
	{
		typeInfo = idClass::GetClass("CardHeal");
	}
	else if (idStr::Icmp(cardId, "card_ammo_up") == 0)
	{
		typeInfo = idClass::GetClass("CardAmmoUp");
	}
	else if (idStr::Icmp(cardId, "card_invisibility") == 0)
	{
		typeInfo = idClass::GetClass("CardInvisibility");
	}
	//Blank Template
	else if (idStr::Icmp(cardId, "") == 0)
	{
		//typeInfo = idClass::GetClass("");
	}

	if (!typeInfo || !typeInfo->IsType(Card::GetClassType()))
	{
		//It isnt a card subclass somehow
		//Card *card = new Card();
		//return *card;
		//gameLocal.Error("Get Card Class is null or not derived from Card");
	}

	idClass *temp = typeInfo->CreateInstance();
	return *static_cast<Card*>(temp);
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

