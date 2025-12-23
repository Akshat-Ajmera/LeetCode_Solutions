class Bank {
private:
    vector<long long> accounts;
public:
    Bank(vector<long long>& balance) {
        accounts = balance;
    }
    bool checkAccountNumber(int account) {
        return (account > 0 && account <= accounts.size());
    }
    bool transfer(int account1, int account2, long long money) {
        if(!checkAccountNumber(account1) || !checkAccountNumber(account2)) return false;
        return withdraw(account1, money) && deposit(account2, money);
    }
    bool deposit(int account, long long money) {
        if(!checkAccountNumber(account)) return false;
        accounts[account - 1] += money;
        return true;
    }
    bool withdraw(int account, long long money) {
        if(!(checkAccountNumber(account)) || (accounts[account - 1] < money)) return false;
        accounts[account - 1] -= money;
        return true;
    }
};