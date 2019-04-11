#ifndef ENEMIES_H
#define ENEMIES_H


class Enemies
{
    public:
        Enemies();
        int FightingGuard(int playerHP, bool HasShield, bool HasSword, int HandDmg, int SwordDmg);
        int FightingWarden(int playerHP, bool HasShield, bool HasSword, int HandDmg, int SwordDmg);

    protected:

    private:
        int GuardHP;
        int WardenHP;
        int GuardDMG;
        int WardenDMG;
};

#endif // ENEMIES_H
