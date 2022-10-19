#include"Helper.h"
#include<ctime>
#include<iostream>
#include<cstring>
#include<set>


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

bool Helper::checkMask(std::string pic_path) {
    system(("/Users/cichengzi/miniforge3/envs/DL/bin/python ../MaskDetection/mask_detection.py " + pic_path).c_str());
    FILE *fr = fopen("../MaskDetection/result.txt", "r");
    char temp[100];
    fgets(temp, 100, fr);
    //temp[strlen(temp) - 1] = '\0';
    std::string pred(temp);
    //std::cout << pred << std::endl;
    return pred == "mask";
}

bool Helper::maskDetection() {
    system("/Users/cichengzi/miniforge3/envs/DL/bin/python ../MaskDetection/run_all.py");
    FILE *fr = fopen("../MaskDetection/result.txt", "r");
    char temp[100];
    fgets(temp, 100, fr);
    std::string result(temp);
    if (result == "mask")
        return true;
    return false;
}

User Helper::faceRecognize(const std::string pic_path) {
    system(("/Users/cichengzi/miniforge3/envs/DL/bin/python ../FaceRecognition/face_vectorize.py " + pic_path).c_str());
    FILE *fr = fopen("../FaceRecognition/result.txt", "r");
    char temp[100];
    fgets(temp, 100, fr);
    temp[strlen(temp) - 1] = '\0';
    std::string user_name(temp);
    //std::cout << user_name << std::endl;
    for (User user: readUsers()) {
        if (user.getName() == user_name)
            return user;
    }
    return User();
}

User Helper::faceRecognize() {
    system("/Users/cichengzi/miniforge3/envs/DL/bin/python ../FaceRecognition/run_all.py");
    FILE *fr = fopen("../FaceRecognition/result.txt", "r");
    char temp[100];
    fgets(temp, 100, fr);
    std::string user_name(temp);
    for (User user: readUsers()) {
        if (user.getName() == user_name)
            return user;
    }
    return User();
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

double Helper::getSimilarity(std::string a, std::string b) {
    std::set<int> sa, sb, in, uni;
    int i = 0;
    for (; i < a.length(); ) {
        if (a[i] >= 0) {
            sa.insert((int)a[i]);
            i += 1;
        }
        else {
            int num = a[i] * 256 * 256 + a[i + 1] * 256 + a[i + 2];
            i += 3;
            sa.insert(num);
        }
    }

    i = 0;
    for (; i < b.length(); ) {
        if (b[i] >= 0) {
            sb.insert((int)b[i]);
            i += 1;
        }
        else {
            int num = b[i] * 256 * 256 + b[i + 1] * 256 + b[i + 2];
            i += 3;
            sb.insert(num);
        }
    }
    for (int x: sa) {
        if (sb.find(x) != sb.end())
            in.insert(x);
        uni.insert(x);
    }
    for (int x: sb) {
        uni.insert(x);
    }
    return 1.0 * in.size() / uni.size();
}

std::string Helper::removePrefixBlank(std::string a) {
    while (a.length() > 0 && a[0] == ' ')
        a = a.substr(1, a.length() - 1);
    return a;
}

bool Helper::checkCommodityInShoppingCart(Commodity commodity, ShoppingCart cart) {
    for (Commodity c: cart.getAllCommodities().getAllCommodities()) {
        if (c.getName() == commodity.getName())
            return true;
    }
    return false;
}

bool Helper::hasSame(std::vector<Commodity> cs1, std::vector<Commodity> cs2) {
    std::set<std::string> s1, s2;
    for (Commodity c: cs1) {
        s1.insert(c.getName());
    }
    for (Commodity c: cs2) {
        s2.insert(c.getName());
    }
    for (std::string s: s1) {
        if (s2.find(s) != s2.end())
            return true;
    }
    return false;
}

std::vector<Commodity> Helper::recommendation(std::vector<Commodity> commodities, std::vector<ShoppingCart> records, ShoppingCart currentRecord) {
    std::vector<Commodity> new_commodities;
    std::set<Commodity> idx_sets;
    std::vector<User> users;

    for (ShoppingCart cart: records) {
        if (hasSame(cart.getAllCommodities().getAllCommodities(),
                    currentRecord.getAllCommodities().getAllCommodities())) {
            users.push_back(cart.getUser());
            for (Commodity c: cart.getAllCommodities().getAllCommodities()) {
                idx_sets.insert(c);
            }
        }
    }

    for (Commodity c: idx_sets) {
        new_commodities.push_back(c);
    }
    for (Commodity c: commodities) {
        if (idx_sets.find(c) != idx_sets.end())
            continue;
        new_commodities.push_back(c);
    }
    return new_commodities;
}