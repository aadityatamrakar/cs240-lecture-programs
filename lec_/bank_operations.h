Account accounts[100];
int num_accounts = 0;

/**
 * Die with error message
 */
void DieWithError(char *errorMessage);

/**
 * Find account by id
 * @param id account id
 * @return account index or -1 if not found
 */
int find_account(int id)
{
    int i;
    for (i = 0; i < num_accounts; i++)
    {
        if (accounts[i].id == id)
            return i;
    }
    return -1;
}

/**
 * Create new account
 * @param id account id
 * @param name account name
 * @param amount amount to deposit
 */
void create_account(int id, char *name, int balance)
{
    int i = find_account(id);
    if (i != -1)
        DieWithError("Account already exists");
    accounts[num_accounts].id = id;
    strcpy(accounts[num_accounts].name, name);
    accounts[num_accounts].balance = balance;
    num_accounts++;
}

void load_accounts(fptr)
{
    Account account;
    rewind(fptr); // go to the beginning of the file
    // read the file
    while (fread(&account, sizeof(Account), 1, fptr) == 1)
    {
        // add the account to the array
        accounts[num_accounts] = account;
        // increment the number of accounts
        num_accounts++;
    }
}

/**
 * Deposit money to account
 * @param id account id
 * @param amount amount to deposit
 */
void deposit(int id, int amount)
{
    int i = find_account(id);
    if (i == -1)
        DieWithError("Account does not exist");
    accounts[i].balance += amount;
}

/**
 * Withdraw money from account
 * @param id account id
 * @param amount amount to withdraw
 */
void withdraw(int id, int amount)
{
    int i = find_account(id);
    if (i == -1)
        DieWithError("Account does not exist");
    if (accounts[i].balance < amount)
        DieWithError("Insufficient funds");
    accounts[i].balance -= amount;
}

/**
 * Get account balance
 * @param id account id
 * @return account balance
 */
int balance(int id)
{
    int i = find_account(id);
    if (i == -1)
        DieWithError("Account does not exist");
    return accounts[i].balance;
}

/**
 * Parse command from client
 * @param command_buffer command string
 * @return Request structure
 */
Request parse_command(char *buffer)
{
    Request t;
    sscanf(buffer, "%d,%d,%d", &t.command, &t.accountId, &t.amount);
    printf("Command: %d, Account: %d, Amount: %d\n", t.command, t.accountId, t.amount);
    return t;
}

/**
 * Add new account to the file
 * @param fptr file pointer
 * @param name account name
 */
int add_account(FILE *fptr, char *name)
{
    Account account;
    account.id = ++num_accounts;
    strcpy(account.name, name);
    account.balance = 0;
    fwrite(&account, sizeof(Account), 1, fptr);
    if (ferror(fptr))
    {
        printf("Error writing to file");
        return -1;
    }
    return account.id;
}

char *search_account(FILE *fptr, char *name)
{
    Account account;
    rewind(fptr);
    while (fread(&account, sizeof(Account), 1, fptr) == 1)
    {
        if (strcmp(account.name, name) == 0)
        {
            char *result = malloc(100);
            sprintf(result, "Account ID: %d, Account Name: %s, Account Balance: %d", account.id, account.name, account.balance);
            return result;
        }
    }
    return "Account not found";
}

void list_accounts(FILE *fptr)
{
    Account account;
    rewind(fptr);
    printf("Lisiting Accounts:\n");
    while (fread(&account, sizeof(Account), 1, fptr) == 1)
    {
        printf("ID: %d\tName: %s\tBalance: %d\n", account.id, account.name, account.balance);
    }
}
