#include <iostream>
#include "std_lib_facilities.h"

int main()
{
    int max = 50, min = 0, guess_range;
    guess_range = (max - min) / 2 + (max - min) % 2;
    char answer = 'y';

    cout << "\nWelcome to guessing game!\n" << endl;
    cout << "Think about a number between 0 and 100\n" << endl;
    cout << "Type any character when you're ready to proceed: \n" << endl;

    string proceed;
    cin >> proceed;
    cout << '\n';

    while (guess_range > 1)
    {
        cout << "Is it between " << min << " and " << max << " ?\n\n";
        cin >> answer;

        if (answer == 'y')
            max -= guess_range;

        else if (answer == 'n')
        {
            min = max;
            max += guess_range;
        }

        guess_range = (max - min) / 2 + (max - min) % 2;
    }

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
        }
    }

    else if (answer == 'n')
    {
        cout << "Is it " << max + 1 << " ?\n\n";
        cin >> answer;

        if (answer == 'y')
        {
            cout << "I've won!!\n\n";
            return 0;
        }

        else if (answer == 'n')
            cout << "I guess something went wrong...\n\n";
    }

return 0;

}