// Here’s a class declaration:
// class Move
// {
// private:
//     double x;
//     double y;
// public:
//     Move(double a = 0, double b = 0); // sets x, y to a, b
//     showmove() const; // shows current x, y values
//     Move add(const Move & m) const;
//     // this function adds x of m to x of invoking object to get new x,
//     // adds y of m to y of invoking object to get new y, creates a new
//     // move object initialized to new x, y values and returns it
//     reset(double a = 0, double b = 0); // resets x,y to a, b
// };
// Create member function definitions and a program that exercises the class.

#include <iostream>

class Move
{
private:
    double x;
    double y;
public:
    Move(double a = 0, double b = 0);
    void Show() const;
    Move Add(const Move & move) const;
    void Reset(double a = 0, double b = 0);
};

Move::Move(double a, double b)
{
    x = a;
    y = b;
}

void Move::Show() const
{
    std::cout << "x = " << x << ", y = " << y << std::endl;
}

Move Move::Add(const Move & move) const
{
    return Move(x + move.x, y + move.y);
}

void Move::Reset(double a, double b)
{
    x = a;
    y = b;
}

int main()
{
    Move move1(10, 20);
    std::cout << "move1: ";
    move1.Show();
    Move move2(15, 50);
    std::cout << "move2: ";
    move2.Show();
    Move move3 = move1.Add(move2);
    std::cout << "move1 + move2: ";
    move3.Show();
    move1.Reset(0, 0);
    std::cout << "move1 reseted: ";
    move1.Show();
    
    return 0;
}