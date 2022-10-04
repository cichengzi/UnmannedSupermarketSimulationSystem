#include"Helper.h"
#include<time.h>

std::string Helper::substring(std::string s, int begin) {
    std::string t;
    for (int i = 0; i < s.length(); i++) {
        if (i >= begin)
            t += s[i];
    }
    return t;
}

std::string Helper::substring(std::string s, int begin, int end) {
    std::string t;
    for (int i = 0; i < s.length(); i++) {
        if (i >= begin && i < end)
            t += s[i];
    }
    return t;
}

std::vector<std::string> Helper::split(std::string s, std::string p) {
    std::vector<std::string> ans;
    while (s.find(p) != -1) {
        int begin = s.find(p);
        ans.push_back(substring(s, 0, begin));
        s = substring(s, begin + p.length());
    }
    ans.push_back(s);
    return ans;
}

std::string Helper::charArrayToString(char *s) {
    std::string t;
    for (int i = 0; s[i] != '\0'; i++)
        t += s[i];
    return t;
}

bool Helper::checkMask() {

}

User Helper::faceRecognize() {
    std::vector<User> users = readUsers();
    return users[0];
}

std::vector<User> Helper::readUsers() {
    std::vector<User> users;
    FILE *fr = fopen("../data/users.txt", "r");
    char s[1000];
    while (fgets(s, 1000, fr) != NULL) {
        std::string line = charArrayToString(s);
        line = substring(line, 0, line.length() - 1);
        std::vector<std::string> splits = split(line, ",");
        User user;
        if (atoi(splits[1].c_str()) == 0) {
            user = User(splits[0], UserType::Administrator);
        } else {
            user = User(splits[0], UserType::GeneralUser);
        }
        user.setBalance(atof(splits[2].c_str()));
        users.push_back(user);
    }
    fclose(fr);
    return users;
}

std::vector<ShoppingCart> Helper::readShoppingCarts() {
    std::vector<ShoppingCart> carts;
    FILE *fr = fopen("../data/carts.txt", "r");
    char s[1000];
    User currentUser;
    ShoppingCart currentCart;
    while (fgets(s, 1000, fr) != NULL) {
        std::string line = charArrayToString(s);
        if (line[line.length() - 1] == '\n')
            line = line.substr(0, line.length() - 1);
        std::vector<std::string> splits = split(line, ",");
        if (splits.size() == 3) {
            if (currentUser.getName() != "无名") {
                carts.push_back(currentCart);
            }
            if (atoi(splits[1].c_str()) == 0) {
                currentUser = User(splits[0], UserType::Administrator);
            } else {
                currentUser = User(splits[0], UserType::GeneralUser);
            }
            currentUser.setBalance(atof(splits[2].c_str()));
            currentCart = ShoppingCart(currentUser);
        } else {
            std::string pic_path = splits[0];
            std::string name = splits[1];
            Commodity commodity = Commodity(splits[1], atof(splits[2].c_str()), atoi(splits[3].c_str()), splits[5]);
            commodity.setPicPath(pic_path);
            commodity.setId(atoll(splits[4].c_str()));
            currentCart.addCommodity(commodity);
        }
    }
    if (currentUser.getName() != "无名") {
        carts.push_back(currentCart);
    }
    fclose(fr);
    return carts;
}

std::vector<ShoppingCart> Helper::readRecords() {
    std::vector<ShoppingCart> carts;
    FILE *fr = fopen("../data/records.txt", "r");
    char s[1000];
    User currentUser;
    ShoppingCart currentCart;
    while (fgets(s, 1000, fr) != NULL) {
        std::string line = charArrayToString(s);
        if (line[line.length() - 1] == '\n')
            line = line.substr(0, line.length() - 1);
        std::vector<std::string> splits = split(line, ",");
        if (splits.size() == 3) {
            if (currentUser.getName() != "无名") {
                carts.push_back(currentCart);
            }
            if (atoi(splits[1].c_str()) == 0) {
                currentUser = User(splits[0], UserType::Administrator);
            } else {
                currentUser = User(splits[0], UserType::GeneralUser);
            }
            currentUser.setBalance(atof(splits[2].c_str()));
            currentCart = ShoppingCart(currentUser);
        } else {
            std::string pic_path = splits[0];
            std::string name = splits[1];
            Commodity commodity = Commodity(splits[1], atof(splits[2].c_str()), atoi(splits[3].c_str()), splits[5]);
            commodity.setPicPath(pic_path);
            commodity.setId(atoll(splits[4].c_str()));
            currentCart.addCommodity(commodity);
        }
    }
    if (currentUser.getName() != "无名") {
        carts.push_back(currentCart);
    }
    fclose(fr);
    return carts;
}

void Helper::saveRecords(std::vector<ShoppingCart> records) {
    FILE *fw = fopen("../data/records.txt", "w");
    for (ShoppingCart record: records) {
        fprintf(fw, "%s\n", record.toString().c_str());
    }
    fclose(fw);
}

void Helper::saveUsers(std::vector<User> users) {
    FILE *fw = fopen("../data/users.txt", "w");
    for (User user: users) {
        fprintf(fw, "%s\n", user.toString().c_str());
    }
    fclose(fw);
}

void Helper::saveShoppingCarts(std::vector<ShoppingCart> carts) {
    FILE *fw = fopen("../data/carts.txt", "w");
    for (ShoppingCart cart: carts) {
        fprintf(fw, "%s\n", cart.toString().c_str());
    }
    fclose(fw);
}

std::string Helper::currentTimeStamp() {
    time_t rawTime;
    time(&rawTime);
    return std::to_string(rawTime);
}

std::vector<Commodity> Helper::readCommodities() {
    std::vector<Commodity> commodities;
    FILE *fr = fopen("../data/commodities.txt", "r");
    char s[1000];
    while (fgets(s, 1000, fr) != NULL) {
        std::string line = charArrayToString(s);
        line = substring(line, 0, line.length() - 1);
        std::vector<std::string> splits = split(line, ",");
        std::string pic_path = splits[0];
        std::string name = splits[1];
        double price = atof(splits[2].c_str());
        Commodity commodity = Commodity(splits[1], atof(splits[2].c_str()), atoi(splits[3].c_str()), splits[5]);
        commodity.setPicPath(pic_path);
        commodity.setId(atoll(splits[4].c_str()));
        commodities.push_back(commodity);
    }
    fclose(fr);
    return commodities;
}

void Helper::saveCommodities(std::vector<Commodity> commodities) {
    FILE *fw = fopen("../data/commodities.txt", "w");
    for (Commodity commodity: commodities) {
        fprintf(fw, "%s\n", commodity.toString().c_str());
    }
    fclose(fw);
}
