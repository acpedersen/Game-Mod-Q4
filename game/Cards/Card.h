
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


	// save games
	//void					Save(idSaveGame *savefile) const;					// archives object for save game file
	//void					Restore(idRestoreGame *savefile);					// unarchives object from save game file

	virtual void			Play(idActor act);
	bool					operator==(const Card card);
	bool					CanPlay(idActor act);


	//Inline Functions
	inline idStr			GetDisplayName() { return displayName; }


	//Static Functions
	static Card				GetCard(idStr cardId);
	

protected:
	const idDeclEntityDef* cardDef;
	idStr cardName;
	idStr displayName;
	idStr descriptionText;

	bool playerOnly = false;

};


#endif