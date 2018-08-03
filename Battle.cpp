#include <iostream>
#include "Battle.hpp"
#include "Character.hpp"
#include "Vampire.hpp"
#include "Medusa.hpp"
#include "Barbarian.hpp"
#include "HarryPotter.hpp"
#include "BlueMen.hpp"


Battle::Battle(): 
    m_player1(nullptr),
    m_player2(nullptr),
    m_winner(nullptr),
    m_gameOver(false)
{}

Battle::~Battle()
{
}

void Battle::playGame()
{
    m_player1 = new BlueMen(this);
    m_player2 = new BlueMen(this);

    while(!m_gameOver)
    {
        std::cout << "\n******************Round***************\n";
        std::cout << "\nPlayer1:\n" << m_player1 << 
            "\n\nPlayer2:\n" << m_player2 << "\n";
        playRound(); 
    }

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
    m_winner = nullptr;
}

void Battle::playRound()
{
    takeTurn(m_player1, m_player2);
    if(!m_gameOver)
    {
      
        takeTurn(m_player2, m_player1);
    }

}

void Battle::takeTurn(Character* attacker, Character* defender)
{
    if(!defender->specDefend())
    {
        attacker->attack(defender);
    }
    else
    {
        std::cout << "\nno attack\n";
    }

    std::cout << "\n\nPlayer1:\n" << m_player1 << 
        "\n\nPlayer2:\n" << m_player2 << "\n";
}

void Battle::menu()
{}

void Battle::gameOver()
{
    std::cout << "\nGame Over\n";
    m_gameOver = true;
}
