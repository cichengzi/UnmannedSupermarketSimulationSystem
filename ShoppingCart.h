#ifndef UNMANNEDSUPERMARKETSIMULATIONSYSTEM_SHOPPINGCART_H
#define UNMANNEDSUPERMARKETSIMULATIONSYSTEM_SHOPPINGCART_H

#include"LinkedList.h"
#include"User.h"

class ShoppingCart {
private:
    LinkedList* carts;
    User user;

    unsigned int cartSize;

    static const int MAXSIZE = 1031;

    static unsigned int hash(unsigned long idx);

public:
    explicit ShoppingCart(User us);

    ShoppingCart();

    User getUser();

    void setUser(User us);

    void addCommodity(Commodity c);

    void removeCommodityById(unsigned long idx);

    void modifyCommodityNumber(unsigned long idx, int num);

    double getPrice(unsigned long idx);

    std::string getName(unsigned long idx);

    int getNumber(unsigned long idx);

    std::string getDescription(unsigned long idx);

    Commodity getCommodity(unsigned long idx);

    void setNumber(unsigned long idx, int num);

    void setDescription(unsigned long idx, std::string d);

    LinkedList getAllCommodities();

    double getTotalPrice();

    void clear();

    std::string toString();

    void loadShoppingCart();
};

#endif //UNMANNEDSUPERMARKETSIMULATIONSYSTEM_SHOPPINGCART_H
