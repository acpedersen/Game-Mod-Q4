
#ifndef __GAME_CARD_H__
#define __GAME_CARD_H__

class Card : public idClass
{
public:
	Card();
	virtual ~Card();


	// save games
	//void					Save(idSaveGame *savefile) const;					// archives object for save game file
	//void					Restore(idRestoreGame *savefile);					// unarchives object from save game file

	void					Play(idActor *act);
	static Card				GetCard(idStr cardId);

protected:
	idStr cardName;
	const idDeclEntityDef* cardDef;
	idStr displayName;
	
};

#endif