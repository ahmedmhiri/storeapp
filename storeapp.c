#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int id;
    char name[50];
    char brand[50];
    float purchasePrice;
    float salePrice;
    int quantity;
    float vat;
} Product;
typedef struct {
    int id;
    char name[50];
    char email[50];
    char phone[20];
    char address[100];
    char socété[100];
    char country[100];
    char birthdate[100];
} Client;
typedef struct {
    int id;
    char name[50];
    char email[50];
    char phone[20];
    char address[100];
    char socété[100];
    char country[100];
    char birthdate[100];
} Supplier;



void managerMenu();
void clientMenu(int clientId);
void supplierMenu();
void login(const char *filePath, void (*menuFunction)(int));
void signUp(const char *filePath);
void addProduct();
void displayProducts();
void deleteProduct();
void modifyProduct();
void searchProduct();
void addClient();
void displayClients();
void deleteClient();
void modifyClient();
void searchClient();
void manageClients();
void addSupplier();
void displaySuppliers();
void deleteSupplier();
void modifySupplier();
void searchSupplier();
void manageSuppliers();
void viewStockDashboard();
void managerLogin();
void clientLogin();
void supplierLogin();
void displayAndPurchaseProducts(int clientId);
void viewPersonalInvoice(int clientId);
void viewPersonalInfoAndHistory(int clientId);
void viewSupplierpersonalInformation();
void validateProductRequest();


int main() {
    int choice;
    while (1) {
        printf("\n=== Store Management Application ===\n");
        printf("1. Manager\n");
        printf("2. Client\n");
        printf("3. Supplier\n");
        printf("4. Exit\n");
        printf("Choose your role: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                managerLogin();
                break;
            case 2:
                clientLogin();
                break;
            case 3:
                supplierLogin();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void managerLogin() {
    int choice;
    printf("\n=== Manager Login ===\n");
    printf("1. Login\n");
    printf("2. Sign Up\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        login("managers.txt", managerMenu);
    } else if (choice == 2) {
        signUp("managers.txt");
        printf("Manager account created! You can now log in.\n");
    } else {
        printf("Invalid choice! Returning to main menu.\n");
    }
}

void clientLogin() {
    int choice;
    printf("\n=== Client Login ===\n");
    printf("1. Login\n");
    printf("2. Sign Up\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        login("clientslogin.txt", clientMenu);
    } else if (choice == 2) {
        signUp("clientslogin.txt");
        printf("Client account created! You can now log in.\n");
    } else {
        printf("Invalid choice! Returning to main menu.\n");
    }
}

void supplierLogin() {
    int choice;
    printf("\n=== Supplier Login ===\n");
    printf("1. Login\n");
    printf("2. Sign Up\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        login("supplierslogin.txt", supplierMenu);
    } else if (choice == 2) {
        signUp("supplierslogin.txt");
        printf("Supplier account created! You can now log in.\n");
    } else {
        printf("Invalid choice! Returning to main menu.\n");
    }
}

void login(const char *filePath, void (*menuFunction)(int)) {
    char username[50], password[50], fileUsername[50], filePassword[50];
    int userId, authenticated = 0;

    printf("\nEnter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    FILE *file = fopen(filePath, "r");
    if (!file) {
        printf("Error: Could not open file %s.\n", filePath);
        return;
    }

    while (fscanf(file, "%d %s %s", &userId, fileUsername, filePassword) != EOF) {
        if (strcmp(username, fileUsername) == 0 && strcmp(password, filePassword) == 0) {
            authenticated = 1;
            break;
        }
    }
    fclose(file);

    if (authenticated) {
        printf("Login successful!\n");
        menuFunction(userId);
    } else {
        printf("Invalid credentials. Please try again.\n");
    }
}

void signUp(const char *filePath) {
    char username[50], password[50];
    int userId;

    printf("\nEnter a new User ID: ");
    scanf("%d", &userId);
    printf("Enter a new Username: ");
    scanf("%s", username);
    printf("Enter a Password: ");
    scanf("%s", password);

    FILE *file = fopen(filePath, "a");
    if (!file) {
        printf("Error: Could not open file %s.\n", filePath);
        return;
    }

    fprintf(file, "%d %s %s\n", userId, username, password);
    fclose(file);

    printf("Account created successfully!\n");
}
void managerMenu() {
    int choice;
    while (1) {
        printf("\n=== Manager Menu ===\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Delete Product\n");
        printf("4. Modify Product\n");
        printf("5. Search Product\n");
        printf("6. Manage Clients\n");
        printf("7. Manage Suppliers\n");
        printf("8. View Stock Dashboard\n");
        printf("9. Logout\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                displayProducts();
                break;
            case 3:
                deleteProduct();
                break;
            case 4:
                modifyProduct();
                break;
            case 5:
                searchProduct();
                break;
            case 6:
                manageClients();
                break;
            case 7:
                manageSuppliers();
                break;
            case 8:
                viewStockDashboard();
                break;
            case 9:
                printf("Logging out...\n");
                return;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
void addProduct() {
    Product product;
    FILE *file = fopen("requests.txt", "a");

    if (!file) {
        printf("Error: Could not open products file.\n");
        return;
    }

    printf("\nEnter Product Details:\n");
    printf("ID: ");
    scanf("%d", &product.id);
    printf("Name: ");
    scanf("%s", product.name);
    printf("Brand: ");
    scanf("%s", product.brand);
    printf("Purchase Price: ");
    scanf("%f", &product.purchasePrice);
    printf("Sale Price: ");
    scanf("%f", &product.salePrice);
    printf("Quantity: ");
    scanf("%d", &product.quantity);
    printf("VAT (%%): ");
    scanf("%f", &product.vat);

    fprintf(file, "%d %s %s %.2f %.2f %d %.2f\n", product.id, product.name, product.brand, product.purchasePrice, product.salePrice, product.quantity, product.vat);
    fclose(file);

    printf("Product added successfully!\n");
}
void displayProducts() {
    Product product;
    FILE *file = fopen("products.txt", "r");

    if (!file) {
        printf("Error: Could not open products file.\n");
        return;
    }

    printf("\n=== Product List ===\n");
    while (fscanf(file, "%d %s %s %f %f %d %f", &product.id, product.name, product.brand, &product.purchasePrice, &product.salePrice, &product.quantity, &product.vat) != EOF) {
        printf("ID: %d, Name: %s, Brand: %s, Purchase Price: %.2f, Sale Price: %.2f, Quantity: %d, VAT: %.2f%%\n",
               product.id, product.name, product.brand, product.purchasePrice, product.salePrice, product.quantity, product.vat);
    }
    fclose(file);
}
void deleteProduct() {
    int id, found = 0;
    Product product;
    FILE *file = fopen("products.txt", "r");
    FILE *tempFile = fopen("temp.txt", "w");

    if (!file || !tempFile) {
        printf("Error: Could not open file.\n");
        return;
    }

    printf("\nEnter Product ID to Delete: ");
    scanf("%d", &id);

    while (fscanf(file, "%d %s %s %f %f %d %f", &product.id, product.name, product.brand, &product.purchasePrice, &product.salePrice, &product.quantity, &product.vat) != EOF) {
        if (product.id == id) {
            found = 1;
            printf("Product with ID %d deleted.\n", id);
        } else {
            fprintf(tempFile, "%d %s %s %.2f %.2f %d %.2f\n", product.id, product.name, product.brand, product.purchasePrice, product.salePrice, product.quantity, product.vat);
        }
    }

    fclose(file);
    fclose(tempFile);
    remove("products.txt");
    rename("temp.txt", "products.txt");

    if (!found) {
        printf("Product with ID %d not found.\n", id);
    }
}
void modifyProduct() {
    int id, found = 0;
    Product product;
    FILE *file = fopen("products.txt", "r");
    FILE *tempFile = fopen("temp.txt", "w");

    if (!file || !tempFile) {
        printf("Error: Could not open file.\n");
        return;
    }

    printf("\nEnter Product ID to Modify: ");
    scanf("%d", &id);

    while (fscanf(file, "%d %s %s %f %f %d %f", &product.id, product.name, product.brand, &product.purchasePrice, &product.salePrice, &product.quantity, &product.vat) != EOF) {
        if (product.id == id) {
            found = 1;
            printf("\nEnter New Details for Product ID %d:\n", id);
            printf("Name: ");
            scanf("%s", product.name);
            printf("Brand: ");
            scanf("%s", product.brand);
            printf("Purchase Price: ");
            scanf("%f", &product.purchasePrice);
            printf("Sale Price: ");
            scanf("%f", &product.salePrice);
            printf("Quantity: ");
            scanf("%d", &product.quantity);
            printf("VAT (%%): ");
            scanf("%f", &product.vat);
        }
        fprintf(tempFile, "%d %s %s %.2f %.2f %d %.2f\n", product.id, product.name, product.brand, product.purchasePrice, product.salePrice, product.quantity, product.vat);
    }

    fclose(file);
    fclose(tempFile);
    remove("products.txt");
    rename("temp.txt", "products.txt");

    if (found) {
        printf("Product with ID %d modified successfully.\n", id);
    } else {
        printf("Product with ID %d not found.\n", id);
    }
}
void searchProduct() {
    int id, found = 0;
    Product product;
    FILE *file = fopen("products.txt", "r");

    if (!file) {
        printf("Error: Could not open products file.\n");
        return;
    }

    printf("\nEnter Product ID to Search: ");
    scanf("%d", &id);

    while (fscanf(file, "%d %s %s %f %f %d %f", &product.id, product.name, product.brand, &product.purchasePrice, &product.salePrice, &product.quantity, &product.vat) != EOF) {
        if (product.id == id) {
            found = 1;
            printf("\nProduct Found:\n");
            printf("ID: %d\nName: %s\nBrand: %s\nPurchase Price: %.2f\nSale Price: %.2f\nQuantity: %d\nVAT: %.2f%%\n",
                   product.id, product.name, product.brand, product.purchasePrice, product.salePrice, product.quantity, product.vat);
            break;
        }
    }

    fclose(file);

    if (!found) {
        printf("Product with ID %d not found.\n", id);
    }
}
void manageClients() {
    int choice;
    while (1) {
        printf("\n=== Manage Clients ===\n");
        printf("1. Add Client\n");
        printf("2. Display Clients\n");
        printf("3. Delete Client\n");
        printf("4. Modify Client\n");
        printf("5. Search Client\n");
        printf("6. Back to Main Menu\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addClient();
                break;
            case 2:
                displayClients();
                break;
            case 3:
                deleteClient();
                break;
            case 4:
                modifyClient();
                break;
            case 5:
                searchClient();
                break;
            case 6:
                printf("Exiting to Main Menu...\n");
                return;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
void addClient() {
    Client client;
    FILE *file = fopen("clients.txt", "a");

    if (!file) {
        printf("Error: Could not open clients file.\n");
        return;
    }

    printf("\nEnter Client Details:\n");
    printf("ID: ");
    scanf("%d", &client.id);
    printf("Name: ");
    scanf("%s", client.name);
    printf("date of birth: ");
    scanf("%s", client.birthdate);
    printf("Email: ");
    scanf("%s", client.email);
    printf("Phone: ");
    scanf("%s", client.phone);
    printf("Address: ");
    scanf("%s", client.address);
    printf("société: ");
    scanf("%s", client.socété);
    printf("country: ");
    scanf("%s", client.country);
    

    fprintf(file, "%d %s %s %s %s\n", client.id, client.name, client.email, client.phone, client.address);
    fclose(file);

    printf("Client added successfully!\n");
}
void displayClients() {
    Client client;
    FILE *file = fopen("clients.txt", "r");

    if (!file) {
        printf("Error: Could not open clients file.\n");
        return;
    }

    printf("\n=== Client List ===\n");
    while (fscanf(file, "%d %s %s %s %s", &client.id, client.name, client.email, client.phone, client.address) != EOF) {
        printf("ID: %d, Name: %s, Email: %s, Phone: %s, Address: %s\n",
               client.id, client.name, client.email, client.phone, client.address);
    }
    fclose(file);
}
void deleteClient() {
    int id, found = 0;
    Client client;
    FILE *file = fopen("clients.txt", "r");
    FILE *tempFile = fopen("temp_clients.txt", "w");

    if (!file || !tempFile) {
        printf("Error: Could not open file.\n");
        return;
    }

    printf("\nEnter Client ID to Delete: ");
    scanf("%d", &id);

    while (fscanf(file, "%d %s %s %s %s", &client.id, client.name, client.email, client.phone, client.address) != EOF) {
        if (client.id == id) {
            found = 1;
            printf("Client with ID %d deleted.\n", id);
        } else {
            fprintf(tempFile, "%d %s %s %s %s\n", client.id, client.name, client.email, client.phone, client.address);
        }
    }

    fclose(file);
    fclose(tempFile);
    remove("clients.txt");
    rename("temp_clients.txt", "clients.txt");

    if (!found) {
        printf("Client with ID %d not found.\n", id);
    }
}
void modifyClient() {
    int id, found = 0;
    Client client;
    FILE *file = fopen("clients.txt", "r");
    FILE *tempFile = fopen("temp_clients.txt", "w");

    if (!file || !tempFile) {
        printf("Error: Could not open file.\n");
        return;
    }

    printf("\nEnter Client ID to Modify: ");
    scanf("%d", &id);

    while (fscanf(file, "%d %s %s %s %s", &client.id, client.name, client.email, client.phone, client.address) != EOF) {
        if (client.id == id) {
            found = 1;
            printf("\nEnter New Details for Client ID %d:\n", id);
            printf("Name: ");
            scanf("%s", client.name);
            printf("Email: ");
            scanf("%s", client.email);
            printf("Phone: ");
            scanf("%s", client.phone);
            printf("Address: ");
            scanf("%s", client.address);
        }
        fprintf(tempFile, "%d %s %s %s %s\n", client.id, client.name, client.email, client.phone, client.address);
    }

    fclose(file);
    fclose(tempFile);
    remove("clients.txt");
    rename("temp_clients.txt", "clients.txt");

    if (found) {
        printf("Client with ID %d modified successfully.\n", id);
    } else {
        printf("Client with ID %d not found.\n", id);
    }
}
void searchClient() {
    int id, found = 0;
    Client client;
    FILE *file = fopen("clients.txt", "r");

    if (!file) {
        printf("Error: Could not open clients file.\n");
        return;
    }

    printf("\nEnter Client ID to Search: ");
    scanf("%d", &id);

    while (fscanf(file, "%d %s %s %s %s", &client.id, client.name, client.email, client.phone, client.address) != EOF) {
        if (client.id == id) {
            found = 1;
            printf("\nClient Found:\n");
            printf("ID: %d\nName: %s\nEmail: %s\nPhone: %s\nAddress: %s\n",
                   client.id, client.name, client.email, client.phone, client.address);
            break;
        }
    }

    fclose(file);

    if (!found) {
        printf("Client with ID %d not found.\n", id);
    }
}
void manageSuppliers() {
    int choice;
    while (1) {
        printf("\n=== Manage Suppliers ===\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Delete Supplier\n");
        printf("4. Modify Supplier\n");
        printf("5. Search Supplier\n");
        printf("6. Back to Main Menu\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSupplier();
                break;
            case 2:
                displaySuppliers();
                break;
            case 3:
                deleteSupplier();
                break;
            case 4:
                modifySupplier();
                break;
            case 5:
                searchSupplier();
                break;
            case 6:
                printf("Exiting to Main Menu...\n");
                return;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
void addSupplier() {
    Supplier supplier;
    FILE *file = fopen("suppliers.txt", "a");

    if (!file) {
        printf("Error: Could not open suppliers file.\n");
        return;
    }

    printf("\nEnter Supplier Details:\n");
    printf("ID: ");
    scanf("%d", &supplier.id);
    printf("Name: ");
    scanf("%s", supplier.name);
    printf("date of birth: ");
    scanf("%s", supplier.birthdate);
    printf("Email: ");
    scanf("%s", supplier.email);
    printf("Phone: ");
    scanf("%s", supplier.phone);
    printf("Address: ");
    scanf("%s", supplier.address);
    printf("société: ");
    scanf("%s", supplier.socété);
    printf("country: ");
    scanf("%s", supplier.country);

    fprintf(file, "%d %s %s %s %s\n", supplier.id, supplier.name, supplier.email, supplier.phone, supplier.address);
    fclose(file);

    printf("Supplier added successfully!\n");
}
void displaySuppliers() {
    Supplier supplier;
    FILE *file = fopen("suppliers.txt", "r");

    if (!file) {
        printf("Error: Could not open suppliers file.\n");
        return;
    }

    printf("\n=== Supplier List ===\n");
    while (fscanf(file, "%d %s %s %s %s", &supplier.id, supplier.name, supplier.email, supplier.phone, supplier.address) != EOF) {
        printf("ID: %d, Name: %s, Email: %s, Phone: %s, Address: %s\n",
               supplier.id, supplier.name, supplier.email, supplier.phone, supplier.address);
    }
    fclose(file);
}
void deleteSupplier() {
    int id, found = 0;
    Supplier supplier;
    FILE *file = fopen("suppliers.txt", "r");
    FILE *tempFile = fopen("temp_suppliers.txt", "w");

    if (!file || !tempFile) {
        printf("Error: Could not open file.\n");
        return;
    }

    printf("\nEnter Supplier ID to Delete: ");
    scanf("%d", &id);

    while (fscanf(file, "%d %s %s %s %s", &supplier.id, supplier.name, supplier.email, supplier.phone, supplier.address) != EOF) {
        if (supplier.id == id) {
            found = 1;
            printf("Supplier with ID %d deleted.\n", id);
        } else {
            fprintf(tempFile, "%d %s %s %s %s\n", supplier.id, supplier.name, supplier.email, supplier.phone, supplier.address);
        }
    }

    fclose(file);
    fclose(tempFile);
    remove("suppliers.txt");
    rename("temp_suppliers.txt", "suppliers.txt");

    if (!found) {
        printf("Supplier with ID %d not found.\n", id);
    }
}
void modifySupplier() {
    int id, found = 0;
    Supplier supplier;
    FILE *file = fopen("suppliers.txt", "r");
    FILE *tempFile = fopen("temp_suppliers.txt", "w");

    if (!file || !tempFile) {
        printf("Error: Could not open file.\n");
        return;
    }

    printf("\nEnter Supplier ID to Modify: ");
    scanf("%d", &id);

    while (fscanf(file, "%d %s %s %s %s", &supplier.id, supplier.name, supplier.email, supplier.phone, supplier.address) != EOF) {
        if (supplier.id == id) {
            found = 1;
            printf("\nEnter New Details for Supplier ID %d:\n", id);
            printf("Name: ");
            scanf("%s", supplier.name);
            printf("Email: ");
            scanf("%s", supplier.email);
            printf("Phone: ");
            scanf("%s", supplier.phone);
            printf("Address: ");
            scanf("%s", supplier.address);
        }
        fprintf(tempFile, "%d %s %s %s %s\n", supplier.id, supplier.name, supplier.email, supplier.phone, supplier.address);
    }

    fclose(file);
    fclose(tempFile);
    remove("suppliers.txt");
    rename("temp_suppliers.txt", "suppliers.txt");

    if (found) {
        printf("Supplier with ID %d modified successfully.\n", id);
    } else {
        printf("Supplier with ID %d not found.\n", id);
    }
}
void searchSupplier() {
    int id, found = 0;
    Supplier supplier;
    FILE *file = fopen("suppliers.txt", "r");

    if (!file) {
        printf("Error: Could not open suppliers file.\n");
        return;
    }

    printf("\nEnter Supplier ID to Search: ");
    scanf("%d", &id);

    while (fscanf(file, "%d %s %s %s %s", &supplier.id, supplier.name, supplier.email, supplier.phone, supplier.address) != EOF) {
        if (supplier.id == id) {
            found = 1;
            printf("\nSupplier Found:\n");
            printf("ID: %d\nName: %s\nEmail: %s\nPhone: %s\nAddress: %s\n",
                   supplier.id, supplier.name, supplier.email, supplier.phone, supplier.address);
            break;
        }
    }

    fclose(file);

    if (!found) {
        printf("Supplier with ID %d not found.\n", id);
    }
}
void viewStockDashboard() {
    FILE *file = fopen("products.txt", "r");
    if (!file) {
        printf("Error: Could not open products file.\n");
        return;
    }

    printf("\n=== Stock Dashboard ===\n");

    int totalProducts = 0;
    float totalValue = 0.0;
    int lowStockThreshold = 5; // Example threshold for low stock

    Product product;
    printf("%-5s %-20s %-10s %-10s %-10s\n", "ID", "Name", "Quantity", "Sale Price", "Value");
    while (fscanf(file, "%d %s %s %f %f %d %f", &product.id, product.name, product.brand, &product.purchasePrice, &product.salePrice, &product.quantity, &product.vat) != EOF) {
        float stockValue = product.salePrice * product.quantity;
        totalValue += stockValue;
        totalProducts++;

        printf("%-5d %-20s %-10d %-10.2f %-10.2f\n", product.id, product.name, product.quantity, product.salePrice, stockValue);

        if (product.quantity < lowStockThreshold) {
            printf("  * Low stock warning: %s (ID: %d)\n", product.name, product.id);
        }
    }

    fclose(file);

    printf("\nTotal Products: %d\n", totalProducts);
    printf("Total Stock Value: %.2f\n", totalValue);
}
void clientMenu(int clientId) {
    int choice;
    while (1) {
        printf("\n=== Client Menu ===\n");
        printf("1. Register\n");
        printf("2. View and Purchase Products\n");
        printf("3. View Invoice\n");
        printf("4. View Personal Info and Purchase History\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addClient();
                break;
            case 2:
                displayAndPurchaseProducts(clientId);
                break;
            case 3:
                viewPersonalInvoice(clientId);
                break;
            case 4:
                viewPersonalInfoAndHistory(clientId);
                break;
            case 5:
                printf("Exiting Client Menu...\n");
                return;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
void displayAndPurchaseProducts(int clientId) {
    Product product;
    int productId, purchaseQuantity, found = 0;
    char invoiceFileName[30];
    sprintf(invoiceFileName, "invoice_%d.txt", clientId); // Personalized invoice file

    FILE *file = fopen("products.txt", "r");
    FILE *tempFile = fopen("temp_products.txt", "w");
    FILE *invoiceFile = fopen(invoiceFileName, "a");

    if (!file) {
        printf("Error: Could not open products file.\n");
        return;
    }
    if (!tempFile) {
        printf("Error: Could not create temporary products file.\n");
        fclose(file);
        return;
    }
    if (!invoiceFile) {
        printf("Error: Could not create or open invoice file.\n");
        fclose(file);
        fclose(tempFile);
        return;
    }

    // Display available products
    displayProducts();

    printf("\nEnter Product ID to Purchase: ");
    scanf("%d", &productId);
    printf("Enter Quantity to Purchase: ");
    scanf("%d", &purchaseQuantity);

    while (fscanf(file, "%d %s %s %f %f %d %f", &product.id, product.name, product.brand,
                  &product.purchasePrice, &product.salePrice, &product.quantity, &product.vat) != EOF) {
        if (product.id == productId) {
            found = 1;
            if (purchaseQuantity > product.quantity) {
                printf("Not enough stock available for %s. Available quantity: %d\n", product.name, product.quantity);
            } else {
                product.quantity -= purchaseQuantity;
                float totalPrice = product.salePrice * purchaseQuantity;
                float vatAmount = totalPrice * (product.vat / 100);
                float finalTotal = totalPrice + vatAmount;

                fprintf(invoiceFile, "Product: %s, Brand: %s, Quantity: %d, Unit Price: %.2f, VAT: %.2f%%, Total: %.2f\n",
                        product.name, product.brand, purchaseQuantity, product.salePrice, product.vat, finalTotal);
                printf("Purchase successful! Product: %s, Quantity: %d, Total (incl. VAT): %.2f\n",
                       product.name, purchaseQuantity, finalTotal);
            }
        }
        // Write the updated product data to the temporary file
        fprintf(tempFile, "%d %s %s %.2f %.2f %d %.2f\n", product.id, product.name, product.brand,
                product.purchasePrice, product.salePrice, product.quantity, product.vat);
    }

    fclose(file);
    fclose(tempFile);
    fclose(invoiceFile);

    if (!found) {
        printf("Product with ID %d not found.\n", productId);
        remove("temp_products.txt"); // Cleanup temporary file if no changes made
    } else {
        remove("products.txt");
        rename("temp_products.txt", "products.txt");
    }
}
void viewPersonalInvoice(int clientId) {
    char invoiceFileName[30];
    sprintf(invoiceFileName, "invoice_%d.txt", clientId); // Personalized invoice file

    FILE *file = fopen(invoiceFileName, "r");
    if (!file) {
        printf("No invoices found for you.\n");
        return;
    }

    char line[256];
    printf("\n=== Your Invoice ===\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}
void viewPersonalInfoAndHistory(int clientId) {
    printf("\n=== Personal Information ===\n");
    searchClient();
    printf("\n=== Purchase History ===\n");
    viewPersonalInvoice(clientId);
}
void supplierMenu() {
    int choice;
    while (1) {
        printf("\n=== Supplier Menu ===\n");
        printf("1. Register\n");
        printf("2. Validate Orders\n");
        printf("3.view personal information\n");
        printf("4. Logout\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSupplier();
                break;
            case 2:
                validateProductRequest();
                break;
            case 3:
                viewSupplierpersonalInformation();
                break;
            case 4:
                printf("Logging out...\n");
                return;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
void viewSupplierpersonalInformation(){
    printf("====== personal information ======\n");
    searchSupplier();
}
void validateProductRequest() {
    FILE *requestFile = fopen("requests.txt", "r");
    if (!requestFile) {
        printf("Error: Could not open requests file.\n");
        return;
    }

    // Read all requests into an array (you could dynamically allocate or use a linked list if needed)
    Product requestProducts[100];
    int requestCount = 0;
    while (fscanf(requestFile, "%d %s %s %f %f %d %f",
                  &requestProducts[requestCount].id,
                  requestProducts[requestCount].name,
                  requestProducts[requestCount].brand,
                  &requestProducts[requestCount].purchasePrice,
                  &requestProducts[requestCount].salePrice,
                  &requestProducts[requestCount].quantity,
                  &requestProducts[requestCount].vat) != EOF) {
        requestCount++;
    }
    fclose(requestFile);

    if (requestCount == 0) {
        printf("No product requests to validate.\n");
        return;
    }

    // Read all existing products into memory
    FILE *productFile = fopen("products.txt", "r");
    if (!productFile) {
        // If products.txt doesn't exist, we'll create it
        productFile = fopen("products.txt", "w");
        if (!productFile) {
            printf("Error: Could not open or create products file.\n");
            return;
        }
        fclose(productFile);
        productFile = fopen("products.txt", "r");
    }

    Product products[1000];
    int productCount = 0;
    while (fscanf(productFile, "%d %s %s %f %f %d %f",
                  &products[productCount].id,
                  products[productCount].name,
                  products[productCount].brand,
                  &products[productCount].purchasePrice,
                  &products[productCount].salePrice,
                  &products[productCount].quantity,
                  &products[productCount].vat) != EOF) {
        productCount++;
    }
    fclose(productFile);

    // For each request, try to find the product by ID and update its quantity.
    // If not found, add it as a new product.
    for (int i = 0; i < requestCount; i++) {
        int found = 0;
        for (int j = 0; j < productCount; j++) {
            if (products[j].id == requestProducts[i].id) {
                // Product exists: just add the requested quantity
                products[j].quantity += requestProducts[i].quantity;
                printf("Updated Product ID %d: New Quantity = %d\n", products[j].id, products[j].quantity);
                found = 1;
                break;
            }
        }

        if (!found) {
            // Product not found: add as a new product entry
            products[productCount++] = requestProducts[i];
            printf("Added new product: ID %d, Name %s, Quantity %d\n", requestProducts[i].id, requestProducts[i].name, requestProducts[i].quantity);
        }
    }

    // Write the updated product list back to products.txt
    FILE *updatedProductFile = fopen("products.txt", "w");
    if (!updatedProductFile) {
        printf("Error: Could not open products file for updating.\n");
        return;
    }

    for (int j = 0; j < productCount; j++) {
        fprintf(updatedProductFile, "%d %s %s %.2f %.2f %d %.2f\n",
                products[j].id,
                products[j].name,
                products[j].brand,
                products[j].purchasePrice,
                products[j].salePrice,
                products[j].quantity,
                products[j].vat);
    }
    fclose(updatedProductFile);

    printf("All requests have been processed.\n");
}
