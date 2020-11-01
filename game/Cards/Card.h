
#ifndef __GAME_CARD_H__
#define __GAME_CARD_H__

class idActor;
class Card : public idClass
{
public:
	CLASS_PROTOTYPE(Card);

	Card() {};
	Card(idStr cardName);
	virtual ~Card();


	void					Play(idActor *act);

	idStr					GetCardDefName();

	bool					operator==(const Card card);
	bool					CanPlay(idActor *act);
	static bool				IsCard(idStr cardName);


	//Inline Functions
	inline idStr			GetDisplayName() { return displayName; }


	//Static Functions
	static idList<idStr>	GetStringsFromCards(idList<Card> list);
	static idList<Card>		GetCardsFromStrings(idList<idStr> list);

protected:
	idDict cardDef;
	idStr cardName;
	idStr displayName;
	idStr descriptionText;

	bool playerOnly = false;


	void					PlayAmmoUp(idActor *act);
	void					PlayDash(idActor *act);
	void					PlayHaste(idActor *act);
	void					PlayHeal(idActor *act);
	void					PlayImpulse(idActor *act);
	void					PlayInvisibility(idActor *act);
	void					PlayQuadDamage(idActor *act);
	void					PlayWeaponSwap(idActor *act);
	void					PlayMegaJump(idActor *act);

	void					PlaySpecific(idActor *act);
};


#endif