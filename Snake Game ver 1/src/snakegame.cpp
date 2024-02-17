#include<stdio.h>

enum state {INGAME = 0, MENU, SETTING, GAMEOVER, INFO} state;

    void Ingame()
    {
        for(int i = 0; i < 80;)
        {
            printf("#");
        }
        state = 10;
    }

    void Menu()
    {
        
    }    

    void Setting()
    {
        
    }

    void Gameover()
    {
        
    }

    void Info()
    {
        
    }

int main()
{
    while(1)
    {
        switch(state)
        {
            case INGAME:
                Ingame();
                break;
            case MENU:
                Menu();
                break;
            case SETTING:
                Setting();
                break;
            case GAMEOVER:
                Gameover();
                break;
            case INFO:
                Info();
                break;
        }
    }
    return 0;
}