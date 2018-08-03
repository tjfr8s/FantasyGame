/*******************************************************************************
 * Author: Tyler Freitas
 * Date: 20180802
 * Description: This class represents a battle. It has 3 Character* data 
 * members for player 1, 2, and winner. It has a bool member for keeping track
 * of game overs. There are member functions for playing a whole game, a single
 * round, a single turn, and gameOver.
*******************************************************************************/ 
#include <iostream>
#include "Battle.hpp"
#include "Character.hpp"
#include "Vampire.hpp"
#include "Medusa.hpp"
#include "Barbarian.hpp"
#include "HarryPotter.hpp"
#include "BlueMen.hpp"


/*******************************************************************************
 * Description: Constructor that initializes m_player1 and m_player2 data 
 * members based on p1 and p2 parameters.
*******************************************************************************/ 
Battle::Battle(int p1, int p2): 
    m_player1(nullptr),
    m_player2(nullptr),
    m_winner(nullptr),
    m_gameOver(false)
{
    switch(p1)
    {
        case 1:
            m_player1 = new Vampire(this);
            break;
        case 2:
            m_player1 = new Medusa(this);
            break;
        case 3:
            m_player1 = new Barbarian(this);
            break;
        case 4:
            m_player1 = new BlueMen(this);
            break;
        case 5:
            m_player1 = new HarryPotter(this);
            break;
    }

    switch(p2)
    {
        case 1:
            m_player2 = new Vampire(this);
            break;
        case 2:
            m_player2 = new Medusa(this);
            break;
        case 3:
            m_player2 = new Barbarian(this);
            break;
        case 4:
            m_player2 = new BlueMen(this);
            break;
        case 5:
            m_player2 = new HarryPotter(this);
            break;
    }
}


/*******************************************************************************
 * Description: Desctructor that deallocates memory for m_player1 and m_player2 
 * data members.
*******************************************************************************/ 
Battle::~Battle()
{
    if(m_player1 != nullptr)
    {
        delete m_player1;
        m_player1 = nullptr;
    }
 
    if(m_player2 != nullptr)
    {
        delete m_player2;
        m_player2 = nullptr;
    }  
}

/*******************************************************************************
 * Description: Calls playRound until a gameover occurs.
*******************************************************************************/ 
void Battle::playGame()
{

    int count = 1;

        std::cout << "\nPlayer1:" << m_player1 << 
            "\n\nPlayer2:" << m_player2 << "\n\n";
    while(!m_gameOver)
    {
        
        std::cout << "\n******************Round " << count << 
            "****************\n";
        playRound(); 
        count++;
    }

    m_winner = nullptr;
}


/*******************************************************************************
 * Description: calls take turn for player 1 and take turn for player 2 if they
 * don't die during player 1's turn.
*******************************************************************************/ 
void Battle::playRound()
{
    std::cout << "****************\n";
    std::cout << "Player 1's turn:\n";
    std::cout << "****************\n";
    takeTurn(m_player1, m_player2);
    if(!m_gameOver)
    {
        std::cout << "****************\n";
        std::cout << "Player 2's turn:\n";
        std::cout << "****************\n";
        takeTurn(m_player2, m_player1);
    }

}


/*******************************************************************************
 * Description: takes two Char* members, attacker and defender. Calls spec 
 * defend for defender to see if they attacker will attack. Then attacker 
 * attacks and defender defneds against the attack. Battle info is dispalyed for 
 * each turn.
*******************************************************************************/ 
void Battle::takeTurn(Character* attacker, Character* defender)
{
    std::cout << "1. Attacker type: " << attacker->getTypeString() << "\n";
    std::cout << "2. Defender type: " << defender->getTypeString() << 
        ", armor: " << defender->getArmor() << ", strength: " << 
        defender->getStrength();
    if(!defender->specDefend())
    {
        attacker->attack(defender);
    }
    else
    {
        std::cout << "\nno attack\n";
    }
    std::cout << "6. Defenders updated strength: " << defender->getStrength() <<
        "\n";
    if(m_gameOver)
    {
        std::cout << "\n\n ** GAME OVER ** \n\n";
    }

}


/*******************************************************************************
 * Description: sets m_gameOver to true.
*******************************************************************************/ 
void Battle::gameOver()
{
    m_gameOver = true;
}
