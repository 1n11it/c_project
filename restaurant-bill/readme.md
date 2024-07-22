# Restaurant Bill Generator

## Description
This C program is a restaurant bill management system. It allows users to generate invoices, view all past invoices, search for specific invoices by customer name, and includes features like discount calculation and tax application.

## Features
- Generate new invoices with multiple items
- View all past invoices
- Search for invoices by customer name
- Automatic calculation of subtotal, discount, and taxes
- Save invoices to a file for future reference

## Project Structure
```
c_project/
│
└── restaurant-bill/
    ├── bill.c
    └── bill.exe
```

## Installation
1. Clone the repository:
   ```sh
   git clone https://github.com/1n11it/c_project.git
   ```
2. Navigate to the project directory:
   ```sh
   cd c_project/restaurant-bill
   ```

## Usage
1. If you're on Windows, you can directly run the executable:
   ```sh
   bill.exe
   ```

   For other operating systems or to recompile:
   ```sh
   gcc -o bill bill.c
   ./bill
   ```

2. Follow the on-screen prompts to use the program.

## Menu Options
1. Generate Invoice
2. View All Invoices
3. Search Invoice
4. Exit

## Example Output
```
  ------------RESTAURANT------------	

  SELECT OPERATION 

  GENERATE INVOICE:   1
  ALL INVOICE(S):     2
  SEARCH INVOICE:     3
  EXIT:               4

  YOUR CHOICE: 1

  CUSTOMER NAME: John Doe
  NO. OF ITEMS: 2

   ITEM 1: Burger
   QUANTITY: 2
   UNIT PRICE: 5.99

   ITEM 2: Fries
   QUANTITY: 1
   UNIT PRICE: 2.99

  ---------------RESTAURANT-------------------
  --------------------------------------------
  DATE: Jul 21 2024
  INVOICE TO: John Doe
  --------------------------------------------
  ITEMS		  QUANTITY	  TOTAL AMOUNT		
  --------------------------------------------

  Burger		  2		  11.980		
  Fries		  1		  2.990		

  --------------------------------------------
  SUB TOTAL			14.970
  DISCOUNT @10%			1.497
				----------
  NET TOTAL			13.473
  CGST @9%			1.213
  SGST @9%			1.213
  --------------------------------------------
  GRAND TOTAL			15.899
  --------------------------------------------

  SAVE INVOICE(+): +

  INVOICE SAVED
```

## Contributing
This is a personal project, but suggestions and feedback are welcome. Feel free to open an issue if you have ideas for improvements or encounter any bugs.

## Contact
For more information or queries, please visit the [repository](https://github.com/1n11it/c_project).
