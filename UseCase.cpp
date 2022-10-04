#include"UseCase.h"

Supermarket UseCase::case1() {
    Supermarket supermarket;
    supermarket.addCommodity(Commodity("巧乐兹", 3.5, 20, "非常好吃的冰棒"));
    supermarket.addCommodity(Commodity("安慕希", 5, 10, "好喝的酸奶"));
    supermarket.addCommodity(Commodity("倪记拉面", 6, 1, "好吃的拉面"));
    supermarket.addUser(User("孙琪", Administrator, 20000));
    supermarket.addUser(User("甄思琪", Administrator, 10000));
    return supermarket;
}

Supermarket UseCase::case2() {
    Supermarket supermarket;
    supermarket.loadAll();
    Commodity c1 = supermarket.getCommodityByIndex(0);
    c1.setNumber(2);
    Commodity c2 = supermarket.getCommodityByIndex(1);
    c2.setNumber(3);
    Commodity c3 = supermarket.getCommodityByIndex(2);
    c3.setNumber(2);
    Commodity c4 = supermarket.getCommodityByIndex(3);
    c4.setNumber(1);
    supermarket.addCartCommodity(c1);
    supermarket.addCartCommodity(c2);
    supermarket.addCartCommodity(c3);
    supermarket.addCartCommodity(c4);
    return supermarket;
}