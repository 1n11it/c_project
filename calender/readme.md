# Calendar Generator

## Description
This C program generates a calendar for a specified year. It displays the calendar for each month, accounting for leap years and correctly aligning the days of the week.

## Features
- Calculates whether a year is a leap year
- Displays the calendar for each month of the given year
- Aligns days correctly with their respective weekdays
- Handles years from 1 to 9999

## Project Structure
```
c_project/
│
└── calender/
    ├── kalnirya.c
    └── kalnirya.exe
```

## Installation
1. Clone the repository:
   ```sh
   git clone https://github.com/1n11it/c_project.git
   ```
2. Navigate to the project directory:
   ```sh
   cd c_project/calender
   ```

## Usage
1. If you're on Windows, you can directly run the executable:
   ```sh
   kalnirya.exe
   ```

   For other operating systems or to recompile:
   ```sh
   gcc -o kalnirya kalnirya.c
   ./kalnirya
   ```

2. Enter the year when prompted (format: YYYY).

## Example
```
ENTER YEAR (Y/Y/Y/Y): 2024

JANUARY 2024
SUN  MON  TUE  WED  THU  FRI  SAT
      1    2    3    4    5    6
  7    8    9   10   11   12   13
 14   15   16   17   18   19   20
 21   22   23   24   25   26   27
 28   29   30   31

...

DECEMBER 2024
SUN  MON  TUE  WED  THU  FRI  SAT
  1    2    3    4    5    6    7
  8    9   10   11   12   13   14
 15   16   17   18   19   20   21
 22   23   24   25   26   27   28
 29   30   31
```

## Contributing
This is a personal project, but suggestions and feedback are welcome. Feel free to open an issue if you have ideas for improvements or encounter any bugs.

## Contact
Project Link: [https://github.com/1n11it/c_project](https://github.com/1n11it/c_project)
