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