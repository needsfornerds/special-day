#include <iostream>
#include <string>
using namespace std;

bool palindrome(string date)
{
    string rev_date = date;
    int i, len = rev_date.length();

    for (i = 0; i < len / 2; i++)
        swap(rev_date[i], rev_date[len - i - 1]);

    if (rev_date == date)
        return true;
    return false;
}

bool ambigram(string date)
{
    int i, j;
    string ambigram_digits = "012458";

    for (i = 0; i < date.length(); i++)
    {
        for (j = 0; j < 7; j++)
        {
            if (date[i] == ambigram_digits[j])
                break;
        }
        if (j == 7)
            return false;
    }
    return true;
}

int main()
{
    string date;
    cout << "Enter today's date: ";
    cin >> date;

    string clean_date;
    int i, j;
    for (i = 0; i < date.length(); i++)
    {
        if (isdigit(date[i]))
            clean_date.push_back(date[i]);
    }
    date = clean_date;

    if (palindrome(date) && ambigram(date))
        cout << "Special Day!" << endl;
    else
        cout << "Not really perfect." << endl;
}
