#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void BillHeader(char name[50], char date[30]);
void BillBody(char item[30], int qty, float price);
void BillFooter(float total);

struct item
{
    char item[20];
    float price;
    int qty;
};

struct order
{
    char customer[50];
    char date[30];
    int numOfItem;
    struct item itm[50];
};

int main()
{
    int option, n;
    char saveBill = '+', next = '+';
    char name[50];
    struct order ord;
    struct order order;
    FILE *ptf;
do
{
    int invoiceFound = 0;
    float total;
    printf("\n\t------------RESTAURANT------------\t\n");
    printf("\n  SELECT OPERATION ");
    printf("\n\n  GENERATE INVOICE:   1");
    printf("\n  ALL INVOICE(S):     2");
    printf("\n  SEARCH INVOICE:     3");
    printf("\n  EXIT:               4");
    printf("\n\n  YOUR CHOICE: ");
    scanf("%d", &option);
    fgetc(stdin);

    switch (option)
    {
    case 1:
        system("clear");
        printf("\n  CUSTOMER NAME:");
        fgets(ord.customer, 50, stdin);
        ord.customer[strlen(ord.customer)-1] = 0;
        strcpy(ord.date, __DATE__);
        printf("  NO. OF ITEMS: ");
        scanf("%d", &n);
        ord.numOfItem = n;
        for (int i = 0; i < n; i++)
        {
            fgetc(stdin);
            printf("\n   ITEM %d: ", i+1);
            fgets(ord.itm[i].item, 20, stdin);
            ord.itm[i].item[strlen(ord.itm[i].item)-1] = 0;
            printf("   QUANTITY: ");
            scanf("%d", &ord.itm[i].qty);
            printf("   UNIT PRICE: ");
            scanf("%f", &ord.itm[i].price);   
            total += (ord.itm[i].qty * ord.itm[i].price);
        }
        BillHeader(ord.customer, ord.date);
        for (int i = 0; i < ord.numOfItem; i++)
        { 
            BillBody(ord.itm[i].item, ord.itm[i].qty, ord.itm[i].price);
        }
        BillFooter(total);
        printf("  SAVE INVOICE(+): ");
        scanf("%s", &saveBill);
        if (saveBill == '+')
        {
            ptf = fopen("restaurantBill.dat", "a+");
            fwrite(&ord, sizeof(struct order), 1, ptf);
            if (fwrite != 0)
            {
                printf("\n  INVOICE SAVED");
            }
            else
            {
                printf("\n  ERROR SAVING INVOICE");
            }
            fclose(ptf);
        }
        else
        {
            printf("\n  INVOICE NOT SAVED");
        }
        break;
    case 2:
        system("clear");
        printf("\n  --------------------------------------------\n");
        printf("  PAST INVOICE(S)");
        ptf = fopen("restaurantBill.dat", "r");
        while (fread(&order, sizeof(struct order), 1, ptf))
        {
            float ttl = 0;
            BillHeader(order.customer, order.date);
            for (int i = 0; i < order.numOfItem; i++)
            {
                BillBody(order.itm[i].item, order.itm[i].qty, order.itm[i].price);
                ttl += (order.itm[i].qty * order.itm[i].price);
            }
            BillFooter(ttl);
        }
        fclose(ptf);
        break;
    case 3:
        printf("\n  CUSTOMER NAME:");
        fgets(name, 50, stdin);
        name[strlen(name)-1] = 0;
        system("clear");
        ptf = fopen("restaurantBill.dat", "r");
        while (fread(&order, sizeof(struct order), 1, ptf))
        {
            float ttl = 0;
            if (!strcmp(order.customer, name))
            {
            printf("  INVOICE OF %s ", name);
            BillHeader(order.customer, order.date);
            for (int i = 0; i < order.numOfItem; i++)
            {
                BillBody(order.itm[i].item, order.itm[i].qty, order.itm[i].price);
                ttl += (order.itm[i].qty * order.itm[i].price);
            }
            BillFooter(ttl);
            invoiceFound = 1;
            }
        }
        if (!invoiceFound)
            {
                printf("  INVOICE OF %s DOESN'T EXIST", name);
            }   
        fclose(ptf);
        break;
    case 4:
    printf("\n");
    exit(0);
        break;
    default:
    printf("\n  INVAID CHOICE ");
        break;
    }
    printf("\n");
    printf("\n  ANOTHER OPERATION(+): ");
    scanf("%s", &next);
} while (next == '+');
    return 0;
}

void BillHeader(char name[50], char date[30])
{
    printf("\n\n  ---------------RESTAURANT-------------------\n");
    printf("  --------------------------------------------");
    printf("\n  DATE: %s", date);
    printf("\n  INVOICE TO: %s", name);
    printf("\n  --------------------------------------------\n");
    printf("  ITEMS\t\t");
    printf("  QUANTITY\t");
    printf("  TOTAL AMOUNT\t\t");
    printf("\n  --------------------------------------------\n\n");
}

void BillBody(char item[30], int qty, float price)
{
    printf("  %s\t\t", item);
    printf("  %d\t\t", qty);
    printf("  %.3f\t\t", (qty*price));
    printf("\n");
}

void BillFooter(float total)
{
    float discount = (0.1*total);
    float netTotal = (total-discount);
    float cgst = (0.09*netTotal);
    float grandTotal = netTotal + (2*cgst);
    printf("\n  --------------------------------------------\n");
    printf("  SUB TOTAL\t\t\t%.3f", total);
    printf("\n  DISCOUNT @10%%\t\t\t%.3f", discount);
    printf("\n\t\t\t\t----------");
    printf("\n  NET TOTAL\t\t\t%.3f", netTotal);
    printf("\n  CGST @9%%\t\t\t%.3f", cgst);
    printf("\n  SGST @9%%\t\t\t%.3f", cgst);
    printf("\n  --------------------------------------------");
    printf("\n  GRAND TOTAL\t\t\t%.3f", grandTotal);
    printf("\n  --------------------------------------------\n\n");
}