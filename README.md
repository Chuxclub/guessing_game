# guessing_game
Computer guesses a user number

Exercise from Bjarne Stroustrup's book: Programming, Principles and Practice Using C++:
Write a program to play a numbers guessing game. The user thinks of a number between 1 and 100 and your program asks questions to figure out what the number is (e.g., “Is the number you are thinking of less than 50?”). Your program should be able to identify the number after asking no more than seven questions. Hint: Use the < and <= operators and the if-else construct.

Possible improvements:
1) I feel like having the computer to guess a possibly user excluded value is a bit of hack. I could add a prompt indicating that user must not exclude values indicated by the intervals but it feels easy and ugly. There must be another algorithm which doesn't have this downside. 
2) I'd like several modes to this game: multiplayer, player guesses computer's number, difficulty modes (with varying bigger or smaller intervals) without cluttering up the main. Here again, good documentation and suggestions are more than welcome!
3) In a distant future: maybe a GUI?
