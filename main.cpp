// Author: Lucas Khamharn
// Date: 20240507
// Prog: Yahtzee Dice


#include <iostream>
#include <map>

int main()
{
    // Map to store the frequency of each die roll
        std::map<int, int> m;
                
    // Iterate for each die roll
        for (int i = 1; i <= 5; ++i)
        {
            std::cout << "Enter die roll: ";
            int value;
            std::cin >> value;
            
            // Update the frequency of the current die roll
            ++m[value];
        }
        
    // Determine the outcome based on the frequency of die rolls

    // If all dice show the same value, it's Yahtzee
        if (m.size() == 1)
        {
            std::cout << "YAHTZEE!!!" << std::endl;
        }
    // If there are exactly two different values and one of them occurs either once or four times, it's Four of a Kind
        else if (m.size() == 2)
        {
            int x = m.begin()->second;
            
            if ((x == 1) || (x == 4))
                std::cout << "FOUR OF A KIND!" << std::endl;
            else
                std::cout << "FULL HOUSE!" << std::endl;
        }
    // If there are exactly three different values and one of them occurs three times, it's Three of a Kind
        else if (m.size() == 3)
        {
            int total = 0;
            
            for (const std::pair<int, int>& die : m)
                if (die.second > 1)
                    total += die.second;
            
            if (total == 3)
                std::cout << "THREE OF A KIND!" << std::endl;
            else
                std::cout << "TWO PAIR!" << std::endl; // If not, it's Two Pair
        }
    // If there are exactly four different values and the sum of the dice is 10 or 18, it's a Small Straight
        else if (m.size() == 4)
        {
            int total = 0;
            
            for (const std::pair<int, int>& die : m)
                total += die.first;
            
            if ((total == 10) || (total == 18))
                std::cout << "SMALL STRAIGHT!" << std::endl;
            else if (total == 14) // If the total is 14, it's a Small Straight only if there is a 2 in the rolls
            {
                if (m.begin()->first == 2)
                    std::cout << "SMALL STRAIGHT!" << std::endl;
                else
                    std::cout << "YOU HAVE NOTHING!" << std::endl;
            }
            else
                std::cout << "YOU HAVE NOTHING!" << std::endl;
        }
    // If there are exactly five different values, it could be a Large Straight or a Small Straight
        else if (m.size() == 5)
        {
            int total = 0;
                
            for (const std::pair<int, int>& die : m)
                total += die.first;
                
            if ((total == 15) || (total == 20))
                std::cout << "LARGE STRAIGHT!" << std::endl; // If the total is 15 or 20, it's a Large Straight
            else if ((total == 16) || (total == 19))
                std::cout << "SMALL STRAIGHT!" << std::endl; // If the total is 16 or 19, it's a Small Straight
            else
                std::cout << "YOU HAVE NOTHING!" << std::endl;
        }
        
    // End program
    return 0;
}
