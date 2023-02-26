#ifndef CHEQUING_H
#define CHEQUING_H

class Chequing : public Account
{
    public:
    Chequing();
    double withdrawal(double);
    double applyFee();
    ~Chequing();

    protected:
    double fee;
};
#endif