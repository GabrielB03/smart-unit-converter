#include "converter.hpp"
#include <sstream>
#include <iostream>
#include <regex>
#include <cctype>
#include <iomanip>

std::optional<std::string> UnitConverter::convert(const std::string &input)
{
    auto [value, unit] = parseInput(input);
    unit = normalizeUnit(toLower(unit)); // Normaliza 'ºc', '°c', etc.

    if (unit == "c" || unit == "f" || unit == "k")
        return convertTemperature(value, unit);
    else if (unit == "m" || unit == "km" || unit == "mi")
        return convertLength(value, unit);
    else if (unit == "kg" || unit == "lb")
        return convertMass(value, unit);
    else if (unit == "s" || unit == "min" || unit == "h")
        return convertTime(value, unit);

    return std::nullopt;
}

std::pair<double, std::string> UnitConverter::parseInput(const std::string &input)
{
    std::regex rgx(R"(([+-]?[\d.]+)\s*([a-zA-Zº°]+))"); // aceita º e °
    std::smatch match;
    if (std::regex_search(input, match, rgx))
    {
        return {std::stod(match[1]), match[2]};
    }
    return {0.0, ""};
}

std::string UnitConverter::toLower(const std::string &str)
{
    std::string lower;
    for (char c : str)
        lower += std::tolower(static_cast<unsigned char>(c));
    return lower;
}

// NOVA FUNÇÃO — normaliza '°c', 'ºc', etc. para apenas 'c'
std::string UnitConverter::normalizeUnit(const std::string &unit)
{
    if (unit == "°c" || unit == "ºc")
        return "c";
    if (unit == "°f" || unit == "ºf")
        return "f";
    if (unit == "°k" || unit == "ºk")
        return "k";
    return unit;
}

std::string UnitConverter::convertTemperature(double value, const std::string &unit)
{
    std::ostringstream out;
    out << std::fixed << std::setprecision(2);
    if (unit == "c")
        out << value << " °C = " << (value * 9 / 5 + 32) << " °F";
    else if (unit == "f")
        out << value << " °F = " << ((value - 32) * 5 / 9) << " °C";
    else if (unit == "k")
        out << value << " K = " << (value - 273.15) << " °C";
    return out.str();
}

std::string UnitConverter::convertLength(double value, const std::string &unit)
{
    std::ostringstream out;
    out << std::fixed << std::setprecision(2);
    if (unit == "km")
        out << value << " km = " << (value * 0.621371) << " mi";
    else if (unit == "mi")
        out << value << " mi = " << (value / 0.621371) << " km";
    else if (unit == "m")
        out << value << " m = " << (value / 1000) << " km";
    return out.str();
}

std::string UnitConverter::convertMass(double value, const std::string &unit)
{
    std::ostringstream out;
    out << std::fixed << std::setprecision(2);
    if (unit == "kg")
        out << value << " kg = " << (value * 2.20462) << " lb";
    else if (unit == "lb")
        out << value << " lb = " << (value / 2.20462) << " kg";
    return out.str();
}

std::string UnitConverter::convertTime(double value, const std::string &unit)
{
    std::ostringstream out;
    out << std::fixed << std::setprecision(2);
    if (unit == "s")
        out << value << " s = " << (value / 60) << " min";
    else if (unit == "min")
        out << value << " min = " << (value / 60) << " h";
    else if (unit == "h")
        out << value << " h = " << (value * 60) << " min";
    return out.str();
}