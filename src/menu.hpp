#ifndef MENU_HPP
#define MENU_HPP

class Menu
{
private:

public:
    enum MenuType {
        MAIN_MENU,
        OPTION_MENU,
        OBJECT_MENU,
    }

    Menu() {}
    Menu(MenuType menu_type);
}

#endif MENU_HPP
