#include "Position.h"
#include <list>
#include <iostream>
#pragma once
class Client;
class Order {
private:
	std::list<Position*> m_ptr_position;
	void clear() {
		m_ptr_position.clear();
	}
	std::string _cost_formate(double cost) {
		std::string tmp = std::to_string(get_cost());
		std::size_t num = tmp.find('.');
		if (num != std::string::npos) {
			tmp.erase(num + 3, std::string::npos);
		}
		return tmp;
	}
public:
	friend Client;
	void add_position(Position* pos) {
		for (auto it = m_ptr_position.begin(); it != m_ptr_position.end(); ++it) {
			if ((*it)->get_ptr_product() == pos->get_ptr_product()) {
				delete* it;
				*it = pos;
				return void();
			}
		}
		m_ptr_position.push_back(pos);
	}
	double get_cost() {
		double cost = 0;
		for (auto it = m_ptr_position.cbegin(); it != m_ptr_position.cend(); ++it)
			cost += (*it)->get_quantity() * (*it)->get_cost();
		return cost;
	}
	void get_info() {
		for (auto it = m_ptr_position.begin(); it != m_ptr_position.end(); ++it) {
			std::cout << (*it)->get_ptr_product()->get_info() << std::endl;
			std::cout << "\tQuantity: " << (*it)->get_quantity() << std::endl;
			std::cout << "\tCost: " << (*it)->get_cost() << std::endl;
		}
		std::cout << "Total cost: " << _cost_formate(get_cost()) << std::endl;
	}
	bool empty() {
		return m_ptr_position.empty();
	}
};
class Balance {
private:
	double m_money = 0;
public:
	void add_money(double money) {
		m_money += money;
	}
	bool waste_money(double money) {
		if (m_money < money)
			return false;
		else {
			m_money -= money;
			return true;
		}
	}
};
class Client {
private:
	Balance m_balance;
public:
	void earn_money(double money) {
		m_balance.add_money(money);
	}
	bool pay_and_recive_order(Order& order) {
		if (m_balance.waste_money(order.get_cost())) {
			order.clear();
			std::cout << "The order is recieved!" << std::endl;
			return true;
		}
		else {
			std::cout << "Not enough money to pay for order!" << std::endl;
			return false;
		}
	}
};
 
