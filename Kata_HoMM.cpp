#include <iostream>
#include <string>
#include <tuple>
using namespace std;
class Monster {
private:
	string type = "";
	int HitPoints; //of the particular unit
	int NumberOfUnits; //In the group
	int DMG; //
public:
	Monster() :
		type(""), HitPoints(0), NumberOfUnits(0), DMG(0)
	{ }
	Monster(string type_name, int HP_value, int NumberOfUnits_value, int DMG_value) :
		type(type_name), HitPoints(HP_value), NumberOfUnits(NumberOfUnits_value), DMG(DMG_value)
	{ }
	void BeingAttacked(const Monster& Enemies)const {

	}
};
typedef tuple<string, int, int, int> MonsterGroup;
string who_would_win(const MonsterGroup& mon1,const MonsterGroup& mon2) {
	Monster monster1(get<0>(mon1), get<1>(mon1), get<2>(mon1), get<3>(mon1));
	Monster monster2(get<0>(mon2), get<1>(mon2), get<2>(mon2), get<3>(mon2)); //Перевод данных кордеж -> наш класс Monster
	return "";
}
int main()
{
	
}
