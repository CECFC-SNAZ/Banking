Banking-SNAZ readme.txt
Zach Partain
3-24-2020

Instructions and general information for the banking program.

General:
The program can store information for up to ten users, and can store
up to ten accounts of any supported type (Checking, Savings, Heloc, or
CD) for each user. More information my be input, but it will not save
the main data after closing the program. To ensure a user's data is
properly saved, logout via the program UI. Failure to do so will cause
discrepencies in account information.

Data Storage:
Program data is stored in two files. All user information and
information necessary for initializing accounts is stored in 
"UserAccounts.dat". A history of all transactions made is stored in
"transactions.dat".

Checking:
The checking account type is the simplest account type. There is no
interest, withdrawal limit, or any other restriction. The user may
freely deposit or withdraw money. If the user overdraws, an
overdraft fee is applied.

Savings:
The savings account type is similar to the checking account type,
except it has a withdrawal limit (currently set to 15 withdrawals)
and monthly compounded interest. Following the monthly compounded
interest pattern, interest is only applied at the end of each month.
Because the program does not use an actual server, if the user does
not log in each month, the monthly interest will not compound
properly resulting in a slightly lower balance than the account
should have. The user is prevented from overdrawing on this type of
account.

HELOC:
The HELOC (Home Equity Line Of Credit) account type, being a form of
loan, is different from the other account types. The acount starts with
a set amount of money (currently 50000 dollars), and the user may
withdraw money in amounts up to 500 dollars as long as there is money
remaining in the account. Each time money is withdrawn, the amount owed
is increased by the amount withdrawn plus interest (the interest rate
is currently set to 10%). Rather than depositing money, the user makes
payments that produce a corresponding decrease in the amount owed.

CD:
The CD (Certificate of Deposit) account type is most similar to the
Savings account type, but with a better interest rate and more
restrictions. The user may make a one time deposit that will earn
interest after a certain period of time (currently, two months).
If the user withdraws money before the account reches maturity,
a 100 dollar fee is charged. After the account reaches maturity
and the interest is applied, the user may withdraw freeley until the
funds run out. To aid in testing the program, the Cd class code
includes a bool flag that, when set to "true," advances time two months
to mature the account. Note: a deposit must be made and the program
must be properly closed before setting this flag.