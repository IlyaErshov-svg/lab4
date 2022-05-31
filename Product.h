#pragma once
#include <string>
class ProductInfo {
private:
	std::string m_info;
public:
	ProductInfo(const std::string& info) {
		m_info = info;
	}
	std::string get_info() {
		return m_info;
	}
};
class Product {
public:
	Product();
};