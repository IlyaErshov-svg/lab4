#include "Product.h"
#pragma once

class Position {
protected:
	Product* m_ptr_product;
public:
	Position(Product& product) {
		m_ptr_product = &product;
	}
	Product* get_ptr_product() {
		return m_ptr_product;
	}
	virtual double get_cost() = 0;
	virtual double get_quantity() = 0;
};

class AmountPosition : public Position {
private:
	std::size_t m_amount;
public:
	AmountPosition(AmountProduct& amount_prod, std::size_t amount):Position(amount_prod) {
		m_amount = amount;
	}
	double get_cost() override {
		return m_ptr_product->get_cost();
	}
	double get_quantity() override{
		return m_amount;
	}
};

class WeightPosition : public Position {
private:
	double m_weight;
public:
	WeightPosition(WeightProduct& weight_prod, double weight) : Position(weight_prod) {
		m_weight = weight;
	}
	double get_cost() override {
		return m_ptr_product->get_cost();
	}
	double get_quantity() override {
		return m_weight;
	}
};