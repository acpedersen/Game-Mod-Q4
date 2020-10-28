
#ifndef __GAME_CARD_H__
#define __GAME_CARD_H__

class idActor;
class Card : public idClass
{
public:
	Card();
	virtual ~Card();


	// save games
	//void					Save(idSaveGame *savefile) const;					// archives object for save game file
	//void					Restore(idRestoreGame *savefile);					// unarchives object from save game file

	virtual void			Play(idActor act);
	bool					operator==(const Card card);
	static Card				GetCard(idStr cardId)
	{
		if (idStr::Icmp(cardId, "card_dash"))
		{
			
			Card *card = new Card();
			return *card;
		}


		Card *card = new Card();
		return *card;
	}

protected:
	idStr cardName;
	const idDeclEntityDef* cardDef;
	idStr displayName;
	
};

#endif