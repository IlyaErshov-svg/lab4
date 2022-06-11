#pragma once
#include <string>
class ProductInfo {
private:
	std::string m_info;
public:
	ProductInfo(const std::string& info) {
		m_info = info;
	}
	std::string get_info() const{
		return m_info;
	}
};
class Product {
public:
	Product(const ProductInfo& product_info) {
		m_product_info = product_info.get_info();
	}
	virtual std::string get_info() = 0;
	virtual double get_cost() = 0;
protected:
	std::string m_product_info;
};

class WeightProduct: public Product{
private:
	double m_cost_per_kg;
public:
	WeightProduct(const ProductInfo& product_info, const double cost):Product(product_info) {
		m_cost_per_kg = cost;
	}
	double get_cost() override{
		return m_cost_per_kg;
	}
	std::string get_info() override {
		std::string tmp = std::to_string(m_cost_per_kg);
		std::size_t num = tmp.find('.');
		if (num != std::string::npos) {
			tmp.erase(num + 3, std::string::npos);
		}
		return m_product_info + ": " + tmp + " per kg";
	}
};

class AmountProduct : public Product {
private:
	double m_cost_per_one;
public:
	AmountProduct(const ProductInfo& product_info, const double cost) :Product(product_info) {
		m_cost_per_one = cost;
	}
	double get_cost() override {
		return m_cost_per_one;
	}
	std::string get_info() override {
		std::string tmp = std::to_string(m_cost_per_one);
		std::size_t num = tmp.find('.');
		if (num != std::string::npos) {
			tmp.erase(num + 3, std::string::npos);
		}
		return m_product_info + ": " + tmp + " per kg";
	}
};