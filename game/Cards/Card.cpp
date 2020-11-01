
#include "../../idlib/precompiled.h"
#pragma hdrstop


#include "Card.h"

#include "../Game_local.h"

CLASS_DECLARATION(idClass, Card)
END_CLASS

Card::Card(idStr cardName)
{
	if (!IsCard(cardName))
		return;

	this->cardName = cardName;
	cardDef = gameLocal.FindEntityDef(cardName, false)->dict;
	descriptionText = cardDef.GetString("description_text", "");
	playerOnly = cardDef.GetBool("player_only");
}

Card::~Card()
{
	delete cardName;
	delete displayName;
}

void Card::Play(idActor *act)
{
	if (!CanPlay(act)) //Check if the card can be played
		return;

	PlaySpecific(act);
}

void Card::PlayAmmoUp(idActor *act)
{
	float ammoRefillPercentage = cardDef.GetFloat("ammo_percentage", "1.0");
	int ammoRefilled = 0;
	idPlayer * player = gameLocal.GetLocalPlayer();
	int weaponIndex = player->GetCurrentWeapon();
	idStr weaponAmmo = rvWeapon::GetAmmoNameForIndex(weaponIndex);
	ammoRefilled = ammoRefillPercentage * player->inventory.MaxAmmoForAmmoClass(player, weaponAmmo);
	player->Give(weaponAmmo, "" + ammoRefilled);
}

void Card::PlayDash(idActor *act)
{
	int impulseValue = cardDef.GetInt("impulse", "1");
	idVec3 impulse = act->GetPhysics()->GetOrigin() * impulseValue;
	//act->

	act->ApplyImpulse(act, 0, act->GetPhysics()->GetOrigin(), impulse);
}

void Card::PlayHaste(idActor *act)
{
	float duration = cardDef.GetFloat("duration", "10f");
	
	bool succeed = gameLocal.GetLocalPlayer()->GivePowerUp(POWERUP_HASTE, SEC2MS(duration));
	gameLocal.Printf("Give haste succeeded: %s\n", succeed);
}

void Card::PlayHeal(idActor *act)
{
	int health = cardDef.GetInt("health", "10");
	gameLocal.GetLocalPlayer()->health += health;
}

void Card::PlayImpulse(idActor *act)
{
	float impulse = cardDef.GetFloat("impulse", "1.0f");
}

void Card::PlayInvisibility(idActor *act)
{
	float duration = cardDef.GetFloat("duration", "10f");
	gameLocal.GetLocalPlayer()->GivePowerUp(POWERUP_INVISIBILITY, SEC2MS(duration));
}

void Card::PlayQuadDamage(idActor *act)
{
	float duration = cardDef.GetFloat("duration", "5f");
	gameLocal.GetLocalPlayer()->GivePowerUp(POWERUP_QUADDAMAGE, SEC2MS(duration));
}

void Card::PlayWeaponSwap(idActor *act)
{

}

void Card::PlayMegaJump(idActor *act)
{
	float force = cardDef.GetFloat("force", "5.0f");
	act->AddForce(act, 0, act->GetPhysics()->GetOrigin(), idVec3(0, force, 0));
}

void Card::PlaySpecific(idActor *act)
{
	if (idStr::Icmp(cardName, "card_ammo_up") == 0)
	{
		PlayAmmoUp(act);
	}
	else if (idStr::Icmp(cardName, "card_dash") == 0)
	{
		PlayDash(act);
	}
	else if (idStr::Icmp(cardName, "card_haste") == 0)
	{
		PlayHaste(act);
	}
	else if (idStr::Icmp(cardName, "card_heal") == 0)
	{
		PlayHeal(act);
	}
	else if (idStr::Icmp(cardName, "card_impulse") == 0)
	{
		PlayImpulse(act);
	}
	else if (idStr::Icmp(cardName, "card_invisibility") == 0)
	{
		PlayInvisibility(act);
	}
	else if (idStr::Icmp(cardName, "card_quad_damage") == 0)
	{
		PlayQuadDamage(act);
	}
	else if (idStr::Icmp(cardName, "card_weapon_swap") == 0)
	{
		PlayWeaponSwap(act);
	}
	else if (idStr::Icmp(cardName, "card_mega_jump") == 0)
	{
		PlayMegaJump(act);
	}
}

idStr Card::GetCardDefName()
{
	return cardName;
}

bool Card::CanPlay(idActor *act)
{
	bool notBlank = cardName != "";
	bool playerCheck = !playerOnly || gameLocal.GetLocalPlayer()->GetInstance() == act->GetInstance();

	return notBlank && playerCheck;
}

bool Card::IsCard(idStr cardName)
{
	const idDeclEntityDef *cardDef = gameLocal.FindEntityDef(cardName, false);
	return cardDef;
}

bool Card::operator==(const Card card)
{
	return this->cardName == card.cardName;
}

idList<idStr> Card::GetStringsFromCards(idList<Card> list)
{
	idList<idStr> *returnList = new idList<idStr>();
	for (int i = 0; i < list.Size(); i++)
	{
		returnList->Append(list[i].GetCardDefName());
	}
	return *returnList;
}

idList<Card> Card::GetCardsFromStrings(idList<idStr> list)
{
	idList<Card> *returnList = new idList<Card>();
	for (int i = 0; i < list.Size(); i++)
	{
		returnList->Append(Card(list[i]));
	}
	return *returnList;
}