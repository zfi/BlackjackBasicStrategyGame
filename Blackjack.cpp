#include "Blackjack.h"

void Blackjack::blackjackGame()
{
    srand(time(0));
    cout << "Work In Progress Blackjack Basic Strategy!" << endl;
    char playAgain = 'Y';
    while (playAgain == 'Y')
    {
        vector<int> playerHand;
        vector<int> dealerHand;
        playerHand.push_back(randomCard());
        playerHand.push_back(randomCard());
        dealerHand.push_back(randomCard());
        dealerHand.push_back(randomCard());
        int playerTotal = calcTotal(playerHand);

        cout << "Your Hand: " << playerHand[0] << " and " << playerHand[1] << " = "  << playerTotal << endl;
        cout << "Dealer's face-up card: " << dealerHand[0] << endl;

        while (true)
        {
            //int playerTotal = calcTotal(playerHand);

            if (playerTotal == 21)
            {
                cout << "Blackjack! You win!" << endl;
                break;
            }
            else if (playerTotal > 21)
            {
                cout << "Bust! You lose!" << endl;
                break;
            }

            char choice;
            cout << "Do you want to hit (H) or stand (S)? ";
            cin >> choice;
            choice = toUpperCase(choice);

            if (choice == 'H')
            {
                playerHand.push_back(randomCard());
                cout << "You drew: " << playerHand.back() << endl;
                playerTotal = calcTotal(playerHand);
                cout << "New Total: " << playerTotal << endl;
                if (calcTotal(playerHand) > 21)
                {
                    cout << "Bust! You lose!" << endl;
                    break;
                }
            }
            else if (choice == 'S')
            {
                int dealerTotal = calcTotal(dealerHand);
                while (dealerTotal < 17)
                {
                    dealerHand.push_back(randomCard());
                    dealerTotal = calcTotal(dealerHand);
                }
                cout << "Dealer's hand: ";
                for (int card : dealerHand)
                {
                    cout << card << " ";
                }
                cout << "(" << dealerTotal << ")" << endl;
                if (dealerTotal > 21 || playerTotal > dealerTotal)
                {
                    cout << "You win!" << endl;
                }
                else if (playerTotal < dealerTotal)
                {
                    cout << "Dealer wins!" << endl;
                }
                else
                {
                    cout << "It's a tie!" << endl;
                }
                break;
            }
        }

        while (true)
        {
            cout << "Do you want to play again? (Y/N): ";
            cin >> playAgain;
            playAgain = toUpperCase(playAgain);
            if (playAgain == 'Y')
            {
                break;
            }
            else if (playAgain == 'N')
            {
                break;
            }
            else 
            {
                cout << "\n----Must be a Y or N----\n";
            }
        }
    }
}

int Blackjack::randomCard()
{
    return rand() % 11 + 1;
}

int Blackjack::calcTotal(const vector<int>& hand)
{
    int total = 0;
    int numAces = 0;

    for (int card : hand)
    {
        if (card == 11)
        {
            numAces++;
        }
        total += card;
    }

    while (total > 21 && numAces > 0)
    {
        total -= 10;
        numAces--;
    }

    return total;
}

char Blackjack::toUpperCase(char choice)
{
    if (choice >= 'a' && choice <= 'z')
    {
        return choice - ('a' - 'A');
    }
    else
    {
        // If the character is not a lowercase letter, return it unchanged.
        return choice;
    }
}
