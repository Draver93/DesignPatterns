#include "Visitor.h"

#include <vector>


namespace visitor_pattern {

	class Mage;
	class Warrior;
	class Archer;

	class Action { //Visitor
	public:
		virtual void execute(Warrior* actor) = 0;
		virtual void execute(Mage* actor) = 0;
		virtual void execute(Archer* actor) = 0;
	};


	class Entity { //Visitable
	public:
		virtual void execute_action(std::shared_ptr<Action> action) = 0;
	};

	class Warrior : public Entity {
	public:
		std::string _name;
	public:
		Warrior(const std::string& name) : _name(name) { }
		void execute_action(std::shared_ptr<Action> action) {
			action->execute(this);
		}
	};

	class Mage : public Entity {
	public:
		std::string _name;
	public:
		Mage(const std::string& name) : _name(name) { }
		void execute_action(std::shared_ptr<Action> action) {
			action->execute(this);
		}
	};

	class Archer : public Entity {
	public:
		std::string _name;
	public:
		Archer(const std::string& name) : _name(name) { }
		void execute_action(std::shared_ptr<Action> action) {
			action->execute(this);
		}
	};


	class Attack : public Action {
	public:
		void execute(Warrior* actor) {
			std::cout << "Warrior: " + actor->_name + " executing sword attack" << std::endl;
		}
		void execute(Mage* actor) {
			std::cout << "Mage: " + actor->_name + " executing fireball spell" << std::endl;
		}
		void execute(Archer* actor) {
			std::cout << "Archer: " + actor->_name + " executing triple arrow shot" << std::endl;
		}
	};

	class Rest : public Action {
	public:
		void execute(Warrior* actor) {
			std::cout << "Warrior: " + actor->_name + "  restoring hp by eating meat" << std::endl;
		}
		void execute(Mage* actor) {
			std::cout << "Mage: " + actor->_name + " restoring mana by drinking potion" << std::endl;
		}
		void execute(Archer* actor) {
			std::cout << "Archer: " + actor->_name + " restoring energy by drinking water" << std::endl;
		}
	};

	class Prepare : public Action {
	public:
		void execute(Warrior* actor) {
			std::cout << "Warrior: " + actor->_name + " always ready!" << std::endl;
		}
		void execute(Mage* actor) {
			std::cout << "Mage: " + actor->_name + " reading the spell" << std::endl;
		}
		void execute(Archer* actor) {
			std::cout << "Archer: " + actor->_name + " drawing a bowstring" << std::endl;
		}
	};
}


std::string VisitorPattern::get_info() {
	return "Name: Visitor Pattern.\nType: Behavioral.\nDescription: The Visitor pattern allows adding new operations to a set of objects without modifying their structure, enabling better separation of concerns.";
}

int VisitorPattern::run() {

	std::vector<std::shared_ptr<visitor_pattern::Entity>> group;
	group.push_back(std::make_shared<visitor_pattern::Mage>("John"));
	group.push_back(std::make_shared<visitor_pattern::Warrior>("Jimmy"));
	group.push_back(std::make_shared<visitor_pattern::Archer>("Alex"));

	std::cout << "\n" << "Team preparation:" << std::endl;
	for (auto& member : group) member->execute_action(std::make_shared<visitor_pattern::Prepare>());
	std::cout << "\n" << "Team attack:" << std::endl;
	for (auto& member : group) member->execute_action(std::make_shared<visitor_pattern::Attack>());
	std::cout << "\n" << "Team resting:" << std::endl;
	for (auto& member : group) member->execute_action(std::make_shared<visitor_pattern::Rest>());

	return 0;
}