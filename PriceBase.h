#pragma once
#include "Product.h"
#include "Position.h"
#include <map>
class PriceBase {
public:
	PriceBase(const PriceBase&) = delete;
	PriceBase& operator = (const PriceBase&) = delete;
	static PriceBase& Instance() {
		static PriceBase instance;
		return instance;
	}
	WeightProduct& get_product_weight_price(const std::string& search) {//const
		return m_products_weight_price.at(search);
	}
	AmountProduct& get_product_ampunt_price(const std::string& search) {
		return m_products_amount_price.at(search);
	}
protected:
	PriceBase() {
		m_products_info = {
		{ "Apple", ProductInfo("Green sweet apple") },
		{ "Nuts", ProductInfo("Macadamia nut") },
		{ "Pensile", ProductInfo("Red pensile with rubber") },
		{ "Chair", ProductInfo("Wooden chair with armrests") },
		};
		m_products_weight_price = {
		{ "Apple", WeightProduct(m_products_info.at("Apple"), 11.35) },
		{ "Nuts", WeightProduct(m_products_info.at("Nuts"), 34.25) },
		};
		m_products_amount_price = {
		{ "Pensile", AmountProduct(m_products_info.at("Pensile"), 5.7) },
		{ "Chair", AmountProduct(m_products_info.at("Chair"), 75) },
		};
	}
private:
	std::map < std::string, ProductInfo> m_products_info;
	std::map < std::string, WeightProduct> m_products_weight_price;
	std::map < std::string, AmountProduct> m_products_amount_price;
};