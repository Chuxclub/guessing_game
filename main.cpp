#include <iostream>
#include "std_lib_facilities.h"

// Computer has to guess player's number
int main()
{
    /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Variables ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  */

    int max = 50, min = 0, guess_range;
    char answer = 'y';
    guess_range = (max - min) / 2 + (max - min) % 2;

    /* The best way I saw to do this was to implement a guess range which is equal to half the former guess range.
     * First guess range is by default 50, as this value is never used though I didn't initialized guess_range.
     * Dividing by two meant getting double values, so I added '+ (max - min) % 2' to have only even numbers. */

    /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Prompts ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  */

    cout << "\nWelcome to guessing game!\n" << endl;
    cout << "Think about a number between 0 and 100\n" << endl;
    cout << "Type any character when you're ready to proceed: \n" << endl;

    string proceed;
    cin >> proceed;
    cout << '\n';

    /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Guess loop ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  */

    while (guess_range > 1)
    {
        cout << "Is it between " << min << " and " << max << " ?\n\n";
        cin >> answer;

        // If the answer is yes, to get the new guess interval I simply subtract to the upper bound the new guess range
        if (answer == 'y')
            max -= guess_range;

        /* If the answer is no, I want the computer to switch to the other half of the guess interval while still
         * narrowing the guess interval. To get it I assign to the lower bound of the new guess interval the previous
         * upper bound and I add to the previous upper bound the new guess range */
        else if (answer == 'n')
        {
            min = max;
            max += guess_range;
        }

        guess_range = (max - min) / 2 + (max - min) % 2;
    }

    /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Final guesses ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  */

    // When guess range is equal to 1 that means that there's only two choices left
    cout << "Is it between " << min << " and " << max << " ?\n\n";
    cin >> answer;

    if (answer == 'y')
    {
        cout << "Is it " << min << " ?\n\n";
        cin >> answer;

        if (answer == 'y')
        {
            cout << "I've won!!\n\n";
            return 0;
        }

        cout << "Is it " << max << " ?\n\n";
        cin >> answer;

        if (answer == 'y')
        {
            cout << "I've won!!\n\n";
            return 0;
        }
    }

    /* I realized that if, for example, the user's guessing number is 62 and the computer asks: 'is it between 50 and
     * 62', the user might consider whether 62 is to be excluded or included. If the user thought it had to be excluded,
     * he would end up with: 'is it between 60 and 61' So I wanted the computer to guess a possibly excluded value. */
    else if (answer == 'n')
    {
        cout << "Is it " << max + 1 << " ?\n\n";
        cin >> answer;

        if (answer == 'y')
        {
            cout << "I've won!!\n\n";
            return 0;
        }

        /* I've tested my program several times with several numbers and it never reached this part (except if user
         * chooses a number out of range)... */
        else if (answer == 'n')
        {
            cout << "You lie!\n\n";
            return 0;
        }
    }

return 0;
}