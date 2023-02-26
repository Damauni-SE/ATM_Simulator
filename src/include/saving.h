#ifndef SAVING_H
#define SAVING_H

class Saving : public Account
{
    public:
    Saving();
    double withdrawal(unsigned int);
    ~Saving();

    protected:
    unsigned int transactionCount;
};
#endif