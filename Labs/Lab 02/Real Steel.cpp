#include <iostream>

int steel_grade(int hardness, float carbon_content, int tensile_strength)
{
    bool conditionOne = hardness > 50;
    bool conditionTwo = carbon_content < 0.7;
    bool conditionThree = tensile_strength > 5600;

    if (conditionOne && conditionTwo && conditionThree)
    {
        return 10;
    }
    else if (conditionOne && conditionTwo)
    {
        return 9;
    }
    else if (conditionTwo && conditionThree)
    {
        return 8;
    }
    else if (conditionOne && conditionThree)
    {
        return 7;
    }
    else if (conditionOne || conditionTwo || conditionThree)
    {
        return 6;
    }
    return 5;
}

int main()
{
    int hardness, tensile_strength;
    float carbon_content;
    std::cin >> hardness >> carbon_content >> tensile_strength;
    std::cout << steel_grade(hardness, carbon_content, tensile_strength);
    return 0;
}