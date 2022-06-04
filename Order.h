#include "Position.h"
#include <vector>
#include <iostream>
#pragma once
class Order {
private:
	std::vector<Position*> m_ptr_position;
public:
	void add_position(Position* pos) {
		for (auto it = m_ptr_position.begin(); it != m_ptr_position.end(); ++it) {
			if ((*it)->get_ptr_product() == pos->get_ptr_product()) {
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
		std::cout << "Total cost: " << get_cost();
	}
	bool empty() {
		return m_ptr_position.empty();
	}
	void clear() {
		m_ptr_position.clear();
	}
};