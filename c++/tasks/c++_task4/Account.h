#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
class Account
{
    
public:

using acc = Account;
static int getNoOfAccounts(void);// Returns the number of accounts
static int getTotalAmount(void);// Returns the total amount of all accounts
static int getNbDeposits(void);// Returns the number of deposits
static int getNoOfWithdrawals(void);// Returns the number of withdrawals
static void displayAccountsInfos(void); // Displays the number of accounts, the total
//amount of deposits, the total amount of withdrawals, and the total amount of all accounts
Account(int initial_deposit);
~Account(void);
void makeDeposit(int deposit);
bool makeWithdrawal(int withdrawal);
int checkAmount(void) const;
void displayStatus(void) const;

private:

static int m_noOfAccounts;
static int m_totalAmount;
static int m_totalNbDeposits;
static int m_totalNbWithdrawals;
// To use time functions --> #include <ctime>
static void m_displayTimestamp(void); // Displays the current timestamp (Will be used in
//displayAccountsInfos() )
int m_accountIndex;
int m_amount;
int m_noOfDeposits;
int m_noOfWithdrawals;
Account(void);
};

#endif /* _ACCOUNT_H_ */

