#include <iostream>
#include <vector>

using namespace std;
enum room_type
{
    bedroom,
    kitchen,
    bathroom,
    children_s,
    living_room
};
struct Rooms
{
    room_type nameRoom;
    double roomArea;
};
struct Level
{
    int countRooms;
    double ceiling_height;
    vector<Rooms> roomList;
};
struct Garage
{
    string nameProgect;
    double buildArea;
};
struct Barns
{
    string nameProgect;
    double buildArea;
};
struct Sauns
{
    string nameProgect;
    double buildArea;
    bool stoveWithPipe;
};
struct Homes
{
    string nameProgect;
    int number;
    double areaOnLand;
    bool stoveWithPipe;
    vector<Level> levelList;
};
struct Buildings
{
    Homes home;
    Garage garage;
    Barns barn;
    Sauns sauna;
};
struct Land
{
    string name;
    double area;
    Buildings bilds;
};
Land setLand(Buildings bilds)
{
    cout << "Введите наименование участка в формате \"B12\": ";
    string nameLand;
    cin >> nameLand;
    cout << "Введите площадь участка в формате 00.00 кв.м.: ";
    double areaLand;
    cin >> areaLand;
    Land land = {nameLand, areaLand, bilds};
    return land;
}
Buildings setBuildings(Homes home, Garage garage, Barns barn, Sauns saun)
{
    Homes h1 = home;
    Garage g1 = garage;
    Barns b1 = barn;
    Sauns s1 = saun;
    Buildings build = {h1, g1, b1, s1};
    // Buildings &ptrBuild = build;
    return build;
}
Garage setGarage()
{
    string nameGarage;
    cout << "Введите наименование проекта Гаража: ";
    cin >> nameGarage;
    double buildArea;
    cout << "Введите площадь гаража: ";
    cin >> buildArea;
    Garage garage = {nameGarage, buildArea};
    // Garage &ptrGarage = garage;
    return garage;
}
Barns setBarns()
{
    string nameBarns;
    cout << "Введите наименование проекта подсобного помещения: ";
    cin >> nameBarns;
    double buildArea;
    cout << "Введите площадь подсобного помещения: ";
    cin >> buildArea;
    Barns barns = {nameBarns, buildArea};
    // Barns &ptrBarns = barns;
    return barns;
}
Sauns setSauns()
{
    string nameSauns;
    cout << "Введите наименование проекта сауны: ";
    cin >> nameSauns;
    double buildArea;
    cout << "Введите площадь сауны: ";
    cin >> buildArea;
    bool stove;
    char tr;
    cout << "Будет ли у сауны печь с трубой? 'y'-если да или 'n' - если нет: ";
    cin >> tr;
    if (tr == 'y')
        stove = true;
    else
        stove = false;
    Sauns sauns = {nameSauns, buildArea, stove};
    // Sauns &ptrSauns = sauns;
    return sauns;
}

Rooms setRoom()
{
    bool check = false;
    room_type typeRoom;
    while (!check)
    {
        cout << "Выберите и введите символ, соответствующий одному из вариантов типа комнаты." << endl;
        cout << "'a' - Спальня, 'b'-Кухня,'c'-Ванная,'d'-Детская,'e'-Гостинная : ";
        char type;
        cin >> type;
        switch (type)
        {
        case 'a':
            typeRoom = bedroom;
            check = true;
            break;
        case 'b':
            typeRoom = kitchen;
            check = true;
            break;
        case 'c':
            typeRoom = bathroom;
            check = true;
            break;
        case 'd':
            typeRoom = children_s;
            check = true;
            break;
        case 'e':
            typeRoom = living_room;
            check = true;
            break;
        default:
            cout << "Выбран не предусмотренный спецификацие вариант!!!" << endl;
            check = false;
            break;
        }
    }
    cout << "Введите площадь комнаты в формате 0.00 :";
    double roomArea;
    cin >> roomArea;
    Rooms room = {typeRoom, roomArea};
    return room;
}

Level setLevel()
{
    cout << "Введите количество комнат на этаже: ";
    int countRooms;
    cin >> countRooms;
    cout << "Введите высоту потолка этажа в формате 0.00 м.: ";
    double ceil_height;
    cin >> ceil_height;
    vector<Rooms> rList;
    // vector<Rooms>& ptrL = rList;
    for (int i = 0; i < countRooms; i++)
    {
        rList.push_back(setRoom());
    }
    Level level = {countRooms, ceil_height, rList};
    return level;
}
vector<Level> setLevels()
{
    cout << "Введите количество этажей в доме. Возможно строительство от 1 до 3 этажей.: ";
    int countLevel;
    cin >> countLevel;
    vector<Level> levelList;
    // vector<Level> &ptrLevels = levelList;
    for (int i = 0; i < countLevel; i++)
    {
        levelList.push_back(setLevel());
    }
    return levelList;
}
Homes setHome()
{
    string nameProgect;
    cout << "Введите наименование проекта дома: ";
    cin >> nameProgect;
    int number;
    cout << "Введите номер дома: ";
    cin >> number;
    double areaOnLand;
    cout << "Введите площадь которую занимает дом на участке: ";
    cin >> areaOnLand;
    bool stove;
    char tr;
    cout << "Будет ли у дома печь с трубой? 'y'-если да или 'n' - если нет: ";
    cin >> tr;
    if (tr == 'y')
        stove = true;
    else
        stove = false;
    Homes home = {nameProgect, number, areaOnLand, stove, setLevels()};
    // Homes &ptrHome = home;
    return home;
}

int main()
{
    cout << "Введите требуемое количество учестков для строительства домов: ";
    int countLand;
    cin >> countLand;
    vector<Land> landList;
    for (int i = 0; i < countLand; i++)
    {
        Land land = setLand(setBuildings(setHome(), setGarage(), setBarns(), setSauns()));
        landList.push_back(land);
    }
    for (Land l : landList)
    {
        cout << "Номер участка - " << l.name << " площадь участка - " << l.area << endl;
        cout << "Сауна - " << l.bilds.sauna.nameProgect << " площадь - " << l.bilds.sauna.buildArea << " печь с трубой - " << l.bilds.sauna.stoveWithPipe << endl;
        cout << "Сарай - " << l.bilds.barn.nameProgect << " площадь - " << l.bilds.barn.buildArea << endl;
        cout << "Гараж - " << l.bilds.garage.nameProgect << " площадь - " << l.bilds.garage.buildArea << endl;
        cout << "Дом - " << l.bilds.home.nameProgect << " площадь на участке - " << l.bilds.home.areaOnLand << " номер дома - " << l.bilds.home.number << " печь с трубой - " << l.bilds.home.stoveWithPipe << endl;
        for (int i = 0; i < l.bilds.home.levelList.size(); i++)
        {
            cout << "Дом этаж - " << i + 1 << " Потолок - " << l.bilds.home.levelList.at(i).ceiling_height << "м. Количество комнат - " << l.bilds.home.levelList.at(i).countRooms << endl;
            cout << "Перечень комнат на этаже - " << i + 1 << endl;
            for (int j = 0; j < l.bilds.home.levelList.at(i).roomList.size(); j++)
            {
                int tmp = l.bilds.home.levelList.at(i).roomList.at(j).nameRoom;
                string name;
                if (tmp == 0)
                    name = "Спальня";
                else if (tmp == 1)
                    name = "Кухня";
                else if (tmp == 2)
                    name = "Ванная";
                else if (tmp == 3)
                    name = "Детская";
                else if (tmp == 4)
                    name = "Гостинная";
                cout << "Название типа комнаты - " << name << " Площадь - " << l.bilds.home.levelList.at(i).roomList.at(j).roomArea << endl;
            }
        }
    }
}