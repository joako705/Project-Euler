// Problem URL: https://projecteuler.net/problem=17
// ---------------------------------------------------------------------------------
// If all the numbers from to 1 to 1,000 (inclusive) were written out in words, how many letters would be used?

#include <iostream>
#include <string>
#include <map>

std::string to_word(int num) {
    // store the easy cases in a dictionary
    std::map<int, std::string> num_words {
        {1, "one"},
        {2, "two"},
        {3, "three"},
        {4, "four"},
        {5, "five"},
        {6, "six"},
        {7, "seven"},
        {8, "eight"},
        {9, "nine"},
        {10, "ten"},
        {11, "eleven"},
        {12, "twelve"},
        {13, "thirteen"},
        {14, "fourteen"},
        {15, "fifteen"},
        {16, "sixteen"},
        {17, "seventeen"},
        {18, "eighteen"},
        {19, "nineteen"},
    };

    // if the number's an easy case, just return the word stored in the dictionary
    if (num >= 1 && num < 20) return num_words[num];

    else if (num >= 20 && num < 100) {
        int ones = num % 10; // find the number in the ones place
        int tens = int(num / 10); // find the number in the tens place (cast the result to an int)

        // if the ones place is a 0, leave it blank; else add a hyphen and that number's value stored in the dictionary
        std::string ones_word = (ones == 0) ? "" : "-" + num_words[ones];

        switch (tens) {
            case 2: return "twenty" + ones_word;
            case 3: return "thirty" + ones_word;
            case 4: return "forty" + ones_word;
            case 5: return "fifty" + ones_word;
            case 6: return "sixty" + ones_word;
            case 7: return "seventy" + ones_word;
            case 8: return "eighty" + ones_word;
            case 9: return "ninety" + ones_word;
            default: break;
        }
    }

    else if (num >= 100 && num < 1000) {
        // same concept as numbers below 100, except with recursion to deal with the tens place
        int ones_tens = num % 100;
        int hundreds = int(num / 100);

        // since ones_tens could be anything between 0 and 100, recursively call the function to convert that number to a word
        std::string ones_tens_word = (ones_tens == 0) ? "" : " and " + to_word(ones_tens);

        return num_words[hundreds] + " hundred" + ones_tens_word;
    }

    else if (num == 1000) return "one thousand"; // handle the last easy case

    // honestly can't be fucked making more ifs for numbers bigger than 1000 or negative numbers
    // so if something else was input into the function, it'll just return an empty string
    return "";
}

int count_letters(std::string num_word) {
    int count = 0;

    for (char x : num_word) {
        if (std::isalpha(x)) count++; // increment only if the character is part of the alphabet
    }

    return count;
}

int main() {
    int letter_count = 0;

    for (int i = 1; i <= 1000; i++) {
        // convert the number to a word, count how many letters are in it, and add it to the count
        letter_count += count_letters(to_word(i));
    }

    std::cout << "Number of letters used when writing out all numbers from 1 to 1000: " << letter_count << std::endl;
    return 0;
}