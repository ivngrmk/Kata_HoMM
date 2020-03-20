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
	int LastUnit_HP; // HP of the last unit to hit
public:
	Monster() :
		type(""), HitPoints(0), NumberOfUnits(0), DMG(0), LastUnit_HP(0)
	{ }
	Monster(string type_name, int HP_value, int NumberOfUnits_value, int DMG_value) :
		type(type_name), HitPoints(HP_value), NumberOfUnits(NumberOfUnits_value), DMG(DMG_value), LastUnit_HP(HP_value)
	{ }
	void BeingAttacked(const Monster& Enemies) {
		int Total_HP = HitPoints * NumberOfUnits;
		Total_HP -= Enemies.NumberOfUnits * Enemies.DMG;
		if (Total_HP % HitPoints != 0) {
			NumberOfUnits = Total_HP / HitPoints + 1;

		}
	}
	bool IsDead(){
		if (NumberOfUnits == 0) {
			return true;
		}
		else return false;
	}
	string VictoryLog(){
		return "";
	}
};
typedef tuple<string, int, int, int> MonsterGroup;
string who_would_win(const MonsterGroup& mon1,const MonsterGroup& mon2) {
	Monster monster1(get<0>(mon1), get<1>(mon1), get<2>(mon1), get<3>(mon1));
	Monster monster2(get<0>(mon2), get<1>(mon2), get<2>(mon2), get<3>(mon2)); //Перевод данных кордеж -> наш класс Monster
	int step = 0;
	bool battle_end = false;
	while (!battle_end) {
		switch (step / 2) {
		case(0):
			monster2.BeingAttacked(monster1);
			if (monster2.IsDead()) {
				return monster1.VictoryLog();
				battle_end = true;
			}
			break;
		case(1):
			monster1.BeingAttacked(monster2);
			if (monster1.IsDead()) {
				return monster2.VictoryLog();
				battle_end = true;
			}
			break;
		}
	}
}
int main()
{
	
}
