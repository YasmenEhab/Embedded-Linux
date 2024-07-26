
#include "Account.h"
#include <ctime>
#include <iostream>

int Account::m_noOfAccounts = 0;
int Account::m_totalAmount = 0;
int Account::m_totalNbDeposits = 0;
int Account::m_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) 
    : m_amount(initial_deposit), m_noOfDeposits(0), m_noOfWithdrawals(0) {
    m_accountIndex = m_noOfAccounts++;
    m_totalAmount += m_amount;
    m_displayTimestamp();
    std::cout << "index:" << m_accountIndex << ";amount:" << m_amount << ";created" << std::endl;
}

Account::~Account(void) {
    m_displayTimestamp();
    std::cout << "index:" << m_accountIndex << ";amount:" << m_amount << ";closed" << std::endl;
}

void Account::m_displayTimestamp(void) {
    std::time_t now = std::time(nullptr);
    std::tm* now_tm = std::localtime(&now);
    std::cout << "[" << (now_tm->tm_year + 1900) << "-"
              << (now_tm->tm_mon + 1) << "-"
              << now_tm->tm_mday << " "
              << now_tm->tm_hour << ":"
              << now_tm->tm_min << ":"
              << now_tm->tm_sec << "] ";
}

int Account::getNoOfAccounts(void) {
    return m_noOfAccounts;
}

int Account::getTotalAmount(void) {
    return m_totalAmount;
}

int Account::getNbDeposits(void) {
    return m_totalNbDeposits;
}

int Account::getNoOfWithdrawals(void) {
    return m_totalNbWithdrawals;
}

void Account::displayAccountsInfos(void) {
    m_displayTimestamp();
    std::cout << "accounts:" << getNoOfAccounts() << ";total:" << getTotalAmount()
              << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNoOfWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit) {
    if (deposit > 0) {
        m_amount += deposit;
        m_totalAmount += deposit;
        m_noOfDeposits++;
        m_totalNbDeposits++;
        m_displayTimestamp();
        std::cout << "index:" << m_accountIndex << ";p_amount:" << (m_amount - deposit)
                  << ";deposit:" << deposit << ";amount:" << m_amount
                  << ";nb_deposits:" << m_noOfDeposits << std::endl;
    }
}

bool Account::makeWithdrawal(int withdrawal) {
    if (withdrawal > 0 && m_amount >= withdrawal) {
        m_amount -= withdrawal;
        m_totalAmount -= withdrawal;
        m_noOfWithdrawals++;
        m_totalNbWithdrawals++;
        m_displayTimestamp();
        std::cout << "index:" << m_accountIndex << ";p_amount:" << (m_amount + withdrawal)
                  << ";withdrawal:" << withdrawal << ";amount:" << m_amount
                  << ";nb_withdrawals:" << m_noOfWithdrawals << std::endl;
        return true;
    } else {
        m_displayTimestamp();
        std::cout << "index:" << m_accountIndex << ";p_amount:" << m_amount
                  << ";withdrawal:refused" << std::endl;
        return false;
    }
}

int Account::checkAmount(void) const {
    return m_amount;
}

void Account::displayStatus(void) const {
    m_displayTimestamp();
    std::cout << "index:" << m_accountIndex << ";amount:" << m_amount
              << ";deposits:" << m_noOfDeposits << ";withdrawals:" << m_noOfWithdrawals << std::endl;
}
