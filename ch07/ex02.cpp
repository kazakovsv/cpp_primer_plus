// Write a program that asks the user to enter up to 10 golf scores, which are
// to be stored in an array. You should provide a means for the user to
// terminate input prior to entering 10 scores. The program should display all
// the scores on one line and report the average score. Handle input, display,
// and the average calculation with three separate array-processing functions.

#include <iostream>

const int MaxSize = 10;

int fill_scores(int scores[], int size);
void show_scores(const int scores[], int size);
int calculate_average(const int scores[], int size);

int main()
{
    int scores[MaxSize] = {};
    int count = fill_scores(scores, MaxSize);
    show_scores(scores, count);
    
    return 0;
}

int fill_scores(int scores[], int size)
{
    std::cout << "Enter up to " << size << " golf scores (-1 to terminate):"
              << std::endl;
    
    int count = 0;
    int score = 0;
    
    for (; count < size; count++)
    {
        std::cout << "Score #" << count + 1 << ": ";
        
        while (!(std::cin >> score))
        {
            std::cin.clear();
            
            while (std::cin.get() != '\n')
            {
                continue;
            }
            
            std::cout << "Please enter an integer number or -1 to terminate: ";
        }
        
        if (score < 0)
        {
            break;
        }
        
        scores[count] = score;
    }
    
    return count;
}

void show_scores(const int scores[], int size)
{
    if (size == 0)
    {
        return;
    }
    
    std::cout << "Scores:";
    
    for (int i = 0; i < size; i++)
    {
        std::cout << " " << scores[i];
    }
    
    std::cout << std::endl << "Average: "
              << calculate_average(scores, size) << std::endl;
}

int calculate_average(const int scores[], int size)
{
    int sum = 0;
    
    for (int i = 0; i < size; i++)
    {
        sum += scores[i];
    }
    
    return sum / size;
}