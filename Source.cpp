#include <array>
#include <iostream>
#include <limits>

int main()
{
    const std::array<int, 6> years = { 1910, 1930, 1950, 1970, 1990, 2010 };
    std::array<int, 6> populations = {};

    for (std::size_t index = 0; index < years.size(); ++index)
    {
        std::cout << "Enter the population of Prairieville in "
                  << years[index] << " (rounded to the nearest 1,000): ";

        while (!(std::cin >> populations[index]) || populations[index] < 0)
        {
            std::cout << "Please enter a non-negative whole number: ";
            std::cin.clear();
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

	std::cout << "\nPrairieville Population Growth\n";

    for (std::size_t index = 0; index < years.size(); ++index)
    {
        std::cout << years[index] << " ";

        for (int count = 0; count < populations[index] / 1000; ++count)
        {
            std::cout << '*';
        }

        std::cout << '\n';
    }

    return 0;
}