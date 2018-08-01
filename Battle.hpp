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
    Battle();
    ~Battle();

    void playGame();
    void playRound();
    void takeTurn(Character* attacker, Character* defender);
    void menu();
    void gameOver();

    void setWinner(Character* winner){m_winner = winner;}


};

#endif
