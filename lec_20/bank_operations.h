struct account accounts[100];
int num_accounts = 0;

void DieWithError(char *errorMessage);

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

void deposit(int id, int amount)
{
    int i = find_account(id);
    if (i == -1)
        DieWithError("Account does not exist");
    accounts[i].balance += amount;
}

void withdraw(int id, int amount)
{
    int i = find_account(id);
    if (i == -1)
        DieWithError("Account does not exist");
    if (accounts[i].balance < amount)
        DieWithError("Insufficient funds");
    accounts[i].balance -= amount;
}

int balance(int id)
{
    int i = find_account(id);
    if (i == -1)
        DieWithError("Account does not exist");
    return accounts[i].balance;
}

void transfer(int from, int to, int amount)
{
    withdraw(from, amount);
    deposit(to, amount);
}

Request parse_command(char *buffer)
{
    Request t;
    char *token;
    token = strtok(buffer, " ");
    t.command = atoi(token);
    token = strtok(NULL, " ");
    t.accountId = atoi(token);
    token = strtok(NULL, " ");
    t.amount = atoi(token);

    printf("Command: %d, Account: %d, Amount: %d\n", t.command, t.accountId, t.amount);

    return t;
}
