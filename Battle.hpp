/*******************************************************************************
 * Author: Tyler Freitas
 * Date: 20180802
 * Description: This class represents a battle. It has 3 Character* data 
 * members for player 1, 2, and winner. It has a bool member for keeping track
 * of game overs. There are member functions for playing a whole game, a single
 * round, a single turn, and gameOver.
*******************************************************************************/ 
#ifndef BATTLE_HPP
#define BATTLE_HPP

class Character;
class Battle
{
private:
    Character* m_player1;
    Character* m_player2;
    Character* m_winner;
    bool m_gameOver;
public:
/*******************************************************************************
 * Description: Constructor that initializes m_player1 and m_player2 data 
 * members based on p1 and p2 parameters.
*******************************************************************************/ 
    Battle(int p1, int p2);


/*******************************************************************************
 * Description: Desctructor that deallocates memory for m_player1 and m_player2 
 * data members.
*******************************************************************************/ 
    ~Battle();


/*******************************************************************************
 * Description: Calls playRound until a gameover occurs.
*******************************************************************************/ 
    void playGame();


/*******************************************************************************
 * Description: calls take turn for player 1 and take turn for player 2 if they
 * don't die during player 1's turn.
*******************************************************************************/ 
    void playRound();


/*******************************************************************************
 * Description: takes two Char* members, attacker and defender. Calls spec 
 * defend for defender to see if they attacker will attack. Then attacker 
 * attacks and defender defneds against the attack. Battle info is dispalyed for 
 * each turn.
*******************************************************************************/ 
    void takeTurn(Character* attacker, Character* defender);


    
/*******************************************************************************
 * Description: sets m_gameOver to true.
*******************************************************************************/
    void gameOver();

    void setWinner(Character* winner){m_winner = winner;}
};

#endif
