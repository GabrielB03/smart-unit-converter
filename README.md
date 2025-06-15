# Smart Unit Converter

## Overview

Smart Unit Converter is a simple and intuitive terminal-based application developed in modern C++. It allows users to convert between common units of measurement with natural text input, such as `"10 km"`, `"25°C"`, or `"70 lb"`. The project is modular and written using clean object-oriented principles, making it ideal both for quick utility use and as a base for further expansion (e.g., GUI or web integration).

## Features

- **Natural Input Format**: Enter values like `10 km`, `25°C`, or `70 lb`
- **Supports Common Units**:
  - **Temperature**: Celsius, Fahrenheit, Kelvin
  - **Length**: Meters, Kilometers, Miles
  - **Mass**: Kilograms, Pounds
  - **Time**: Seconds, Minutes, Hours
- **Symbol Normalization**: Accepts inputs like `°C`, `ºC`, or `c`
- **Modular Code Structure**: Separated headers and implementation files
- **C++ Standard**: Uses `std::optional`, `std::pair`, and `std::regex` from C++17

## Technologies Used

- **C++17**: Core programming language standard
- **MinGW / g++**: Compiler used for building the project
- **VSCode**: Recommended for editing and running

## Instalation

1. Make sure you have a C++ compiler installed (recommended: MinGW with g++):
   - [Download MinGW](https://www.mingw-w64.org/)
   - Add `bin` folder to your system `PATH`
2. Clone the repository to your local machine:
   ```bash
   git clone https://github.com/GabrielB03/smart-unit-converter.git
   ```
3. Navigate to the project directory:
   ```bash
   cd smart-unit-converter
   ```
4. Compile the project:
   ```bash
   g++ -Iinclude -o converter src/main.cpp src/converter.cpp -std=c++17
   ```
5. Run the program:
   ```bash
   ./converter
   ```

## Requirements

- g++ 7.1 or newer (supports C++17)
- A terminal environment (Windows, Linux or macOS)
- CMake (optional, for larger builds)

## Project Preview

![image](https://github.com/user-attachments/assets/ca7079e2-e086-444f-b8e4-c6eb692a9a0b)

## Contribution

Contributions are welcome! To contribute:
1. Fork the repository
2. Create a feature branch (git checkout -b feature-name)
3. Commit your changes
4. Push the branch to your fork
5. Open a Pull Request for review

## Future Improvements

- Add support for more units (volume, area, speed)
- Develop a GUI version using Qt or ImGui
- Add unit testing with Google Test
- Create a web-based front-end using Flask or React
- Add localization for multilingual input/output

## License

This project is licensed under the MIT license - see the [LICENSE](LICENSE) file for details.
