#ifndef UNMANNEDSUPERMARKETSIMULATIONSYSTEM_COMMODITYSHELF_H
#define UNMANNEDSUPERMARKETSIMULATIONSYSTEM_COMMODITYSHELF_H

#include"LinkedList.h"
#include"Helper.h"

const int MAXSIZE = 1031;

class CommodityShelf {
private:
    LinkedList* shelves;

    static unsigned int hash(unsigned long idx);

public:
    CommodityShelf();

    void addCommodity(Commodity c);

    void removeCommodityById(unsigned long idx);

    void modifyCommodityNumber(unsigned long idx, int num);

    double getPrice(unsigned long idx);

    std::string getName(unsigned long idx);

    int getNumber(unsigned long idx);

    std::string getDescription(unsigned long idx);

    Commodity getCommodity(unsigned long idx);

    std::string toString();

    void setPrice(unsigned long idx, double p);

    void setNumber(unsigned long idx, int num);

    void setDescription(unsigned long idx, std::string d);

    LinkedList getAllCommodities();

    std::vector<Commodity> readCommodities();

    void loadCommodities();

    void saveCommodities();

    void clear();
};

#endif //UNMANNEDSUPERMARKETSIMULATIONSYSTEM_COMMODITYSHELF_H
