struct account accounts[100];
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
