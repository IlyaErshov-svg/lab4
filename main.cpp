#include <iostream>
#include "Product.h"
#include "Position.h"
#include "Client.h"
#include "PriceBase.h"
int main()
{
    PriceBase& pricebase = PriceBase::Instance();
    Order order;
    if (order.empty()) {
        std::cout << "Order is empty" << std::endl;
    }
    order.add_position(new WeightPosition(pricebase.get_product_weight_price("Apple"), 0.5));
    order.add_position(new AmountPosition(pricebase.get_product_ampunt_price("Pensile"), 2));
    order.get_info();
    order.add_position(new WeightPosition(pricebase.get_product_weight_price("Apple"), 1.5));
    order.get_info();
    Client Ivan;
    Ivan.pay_and_recive_order(order);
    Ivan.earn_money(500);
    Ivan.pay_and_recive_order(order);
    if (order.empty()) {
        std::cout << "Order is empty" << std::endl;
    }
    order.get_info();
}
