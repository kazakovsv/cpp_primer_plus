// Do Programming Exercise 4 from Chapter 9 but convert the Sales structure and
// its associated functions to a class and its methods. Replace the
// setSales(Sales &, double [], int) function with a constructor. Implement the
// interactive setSales(Sales &) method by using the constructor. Keep the
// class within the namespace SALES.

#include <iostream>

namespace SALES
{
    class Sales
    {
    private:
        static const int QUARTERS = 4;
        double m_sales[QUARTERS];
        double m_average;
        double m_max;
        double m_min;
    public:
        Sales() {}
        Sales(const double ar[], int n);
        void SetSales();
        void Show() const;
    };
    
    Sales::Sales(const double ar[], int n)
    {
        m_min = ar[0];
        m_max = ar[0];
        double sum = 0;
        
        for (int i = 0; i < n; i++)
        {
            if (i >= QUARTERS)
            {
                m_sales[i] = 0.0;
            }
            else
            {
                m_sales[i] = ar[i];
                sum += ar[i];
                
                if (ar[i] < m_min)
                {
                    m_min = ar[i];
                }
                
                if (ar[i] > m_max)
                {
                    m_max = ar[i];
                }
            }
        }
        
        m_average = sum / QUARTERS;
    }
    
    void Sales::SetSales()
    {
        std::cout << "Enter sales for 4 quarters:" << std::endl;
        double temp[QUARTERS];
        
        for (int i = 0; i < QUARTERS; i++)
        {
            std::cout << "Quarter #" << i + 1 << ": ";
            std::cin >> temp[i];
        }
        
        *this = Sales(temp, QUARTERS);
    }
    
    void Sales::Show() const
    {
        std::cout << std::endl << "Sales:" << std::endl;
        
        for (int i = 0; i < QUARTERS; i++)
        {
            std::cout << "Quarter #" << i + 1 << ": " << m_sales[i] << std::endl;
        }
        
        std::cout << "Min: " << m_min << std::endl;
        std::cout << "Max: " << m_max << std::endl;
        std::cout << "Average: " << m_average << std::endl;
    }
}

int main()
{
    SALES::Sales s1;
    s1.SetSales();
    s1.Show();
    
    double sales[] = {1234.56, 2345.67, 3456.78, 4567.89, 5678.90};
    SALES::Sales s2(sales, 5);
    s2.Show();
    
    return 0;
}