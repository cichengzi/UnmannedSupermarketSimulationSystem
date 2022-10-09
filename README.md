```c++
class Commodity {
private:
    std::string pic_path; // 商品图片地址
    std::string name; // 商品名称
    double price; // 商品价格
    int number; // 商品数量
    unsigned long idx; // 商品编号
    std::string description; // 商品描述

public:
    Commodity(); // 商品类的默认构造函数

    Commodity(std::string nm, double p, int nb, std::string d); // 商品类的另一个构造函数

    std::string getPicPath(); // 获取商品图片路径
  
    void setId(unsigned long i); // 设置商品的编号

    void setPicPath(std::string pic_path); // 设置商品图片路径

    std::string getName(); // 获取商品名称

    double getPrice(); // 获取商品价格

    int getNumber(); // 获取商品数量

    std::string getDescription(); // 获取商品描述

    unsigned long getId(); // 获取商品编号

    void setPrice(double p); // 设置商品价格

    void setNumber(int nb); // 设置商品数量

    void setDescription(std::string d); // 设置商品描述

    std::string toString(); // 商品信息转string
};
```



```c++
class CommodityShelf {
private:
    LinkedList* shelves; // 商品哈希表

    static unsigned int hash(unsigned long idx); // 获取商品编号为idx的商品在哈希表中的位置

public:
    CommodityShelf(); // 默认构造函数

    void addCommodity(Commodity c); // 添加商品

    void removeCommodityById(unsigned long idx); // 移除编号为idx的商品

    void modifyCommodityNumber(unsigned long idx, int num); // 修改编号为idx的商品的数量

    double getPrice(unsigned long idx); // 获取编号为idx的商品的价格

    std::string getName(unsigned long idx); // 获取编号为idx的商品的名称

    int getNumber(unsigned long idx); // 获取编号为idx的商品的数量

    std::string getDescription(unsigned long idx); // 获取编号为idx的商品的描述

    Commodity getCommodity(unsigned long idx); // 获取编号为idx的商品

    std::string toString(); // 获取类的string描述

    void setPrice(unsigned long idx, double p); // 设置编号为idx的商品的价格为p

    void setNumber(unsigned long idx, int num); // 设置编号为idx的商品的数量为num

    void setDescription(unsigned long idx, std::string d); // 设置编号为idx的商品的描述为d

    LinkedList getAllCommodities(); // 获取哈希表中所有的商品

    std::vector<Commodity> readCommodities(); // 读取commodities.txt中的所有商品

    void loadCommodities(); // 加载commodities.txt中的所有商品到此类对象中

    void saveCommodities(); // 将此类中所有商品信息保存到commodities.txt中

    void clear(); // 清空此类中所有商品
};
```



```c++
class Helper {
public:
    std::string substring(std::string s, int begin); // 获取字符串s从begin索引开始的子串

    std::string substring(std::string s, int begin, int end); // 获取字符串s从begin索引开始到end索引间（包含end）的子串

    std::vector<std::string> split(std::string s, std::string p); // 获取用字符串p对字符串s进行分割的列表

    std::string charArrayToString(char s[]); // char array转std string

    bool checkMask(std::string pic_path); // 检测处于pic_path路径下的图片中的人是否有佩戴口罩

    User faceRecognize(std::string pic_path); // 检测处于pic_path路径下的图片中的人的身份

    bool maskDetection(); // 检测用户是否有佩戴口罩

    User faceRecognize(); // 对用户进行身份识别

    std::vector<User> readUsers(); // 读取users.txt中所有的用户信息

    std::vector<ShoppingCart> readShoppingCarts(); // 读取carts.txt中所有的购物车信息

    std::vector<ShoppingCart> readRecords(); // 读取records.txt中所有的购买记录信息

    std::vector<Commodity> readCommodities(); // 读取commodities.txt中所有的商品信息

    void saveCommodities(std::vector<Commodity> commodities); // 将commodities vector中的所有商品保存到commodities.txt中

    void saveRecords(std::vector<ShoppingCart> records); // 将records vector中所有的购物车保存到carts.txt中

    void saveUsers(std::vector<User> users); // 将users vector中所有的用户保存到users.txt中

    void saveShoppingCarts(std::vector<ShoppingCart> carts); // 将carts vector中所有的购物车保存到carts.txt中

    std::string currentTimeStamp(); // 以字符串形式获取当前的时间戳
};
```



```c++
class LinkedList {
private:
    Node* front; // 链表的头结点
    Node* back; // 链表的尾结点

public:
    LinkedList(); // 链表类的默认构造函数

    void addCommodity(Commodity c); // 添加商品

    Commodity getCommodityByIndex(int index); // 通过索引获取商品

    Commodity getCommodityById(unsigned long idx); // 通过编号idx获取商品

    void removeCommodityById(unsigned long idx); // 从链表中移除编号为idx的商品

    void removeCommodityByIndex(int index); // 通过索引移除商品

    void modifyCommodityNumber(unsigned long idx, int num); // 修改编号为idx的商品数量为num

    void clear(); // 清空链表中所有的商品

    double getPrice(unsigned long idx); // 获取编号为idx的商品的价格

    std::string getName(unsigned long idx); // 获取编号为idx的商品的名称

    std::string getDescription(unsigned long idx); // 获取编号为idx的商品的描述

    std::string toString(); // 获取链表类的string描述

    bool isEmpty(); // 判断链表是否为空

    int getNumber(unsigned long idx); // 获取编号为idx的商品的数量

    Node* getFront(); // 获取链表的头结点

    Node* getBack(); // 获取链表的尾结点

    void setPrice(unsigned long idx, double p); // 设置编号为idx的商品的价格为p
  
    void setNumber(unsigned long idx, int num); // 设置编号为idx的商品的数量为num

    void setDescription(unsigned long idx, std::string d); // 设置编号为idx的商品的描述为d

    std::vector<Commodity> getAllCommodities(); // 获取链表中所有的商品
};
```



```c++
class Node {
private:
    Commodity data; // 结点类的商品信息
    Node *next; // 下一个结点的指针

public:
    Node(); // 结点类的默认构造函数

    Node(Commodity d); // 带参构造函数1

    Node(Commodity d, Node *nt); // 带参构造函数2

    Commodity getCommodity(); // 获取当前结点的商品信息

    Node* getNext(); // 获取当前结点的下一个结点的指针

    std::string getName(); // 获取当前结点的商品名称

    void setCommodity(Commodity d); // 设置当前结点的商品

    void setNext(Node* nt); // 设置当前结点的下一个结点的指针

    void setCount(int num); // 设置当前结点商品的数量
};
```



```c++
class ProductPurchase : public QWidget {
Q_OBJECT

public:
    explicit ProductPurchase(QWidget *parent = nullptr); // 默认构造函数

    ~ProductPurchase() override; // 析构函数

private slots:

    void returnBack(); // 返回主界面

    void currentItem(); // 显示当前选中栏的元素

    void saveShoppingCart(); // 保存购物车信息到carts.txt

    void addCommodity(); // 添加商品到购物车

    void removeCommodity(); // 从购物车中移除商品

    void showShoppingCart(); // 展示购物车信息

public slots:
    void setCurrentUser(User us); // 设置当前用户为us

    void setShoppingCart(ShoppingCart cart); // 设置当前购物车为cart

    void loadShoppingCart(); // 从carts.txt中找出用户us对应的购物车

private:
    Ui::ProductPurchase *ui; // 当前界面的ui
    User currentUser; // 当前用户
    ShoppingCart shoppingCart; // 当前用户对应的购物车
    CommodityShelf commodityShelf; // 商品货架类
    bool showCart; // 是否显示购物车🛒
    QWidget* shoppingCartWidget; // 购物车界面的ui
    QListWidget* shoppingCartListWidget; // 购物车商品列表的ui
};
```



```c++
class ShoppingCart {
private:
    LinkedList* carts; // 购物车哈希表
    User user; // 当前购物车对应的用户
    unsigned int cartSize; // 购物车中商品种类的数量
    static const int MAXSIZE = 1031; // 购物车哈希表的最大行数
    static unsigned int hash(unsigned long idx); // 计算编号为idx的商品在哈希表中的位置
public:
    explicit ShoppingCart(User us); // 带参构造函数

    ShoppingCart(); // 无参构造函数

    User getUser(); // 获取购物车对应用户

    void setUser(User us); // 设置购物车的用户

    void addCommodity(Commodity c); // 往购物车中添加商品

    void removeCommodityById(unsigned long idx); // 从购物车中移除掉编号为idx的商品

    void modifyCommodityNumber(unsigned long idx, int num); // 修改购物车中编号为idx的商品的数量

    double getPrice(unsigned long idx); // 获取编号为idx的商品的价格

    std::string getName(unsigned long idx); // 获取编号为idx的商品的名称

    int getNumber(unsigned long idx); // 获取编号为idx的商品的数量

    std::string getDescription(unsigned long idx); // 获取编号为idx的商品的描述

    Commodity getCommodity(unsigned long idx); // 获取编号为idx的商品

    void setNumber(unsigned long idx, int num); // 设置编号为idx的商品的数量为num

    void setDescription(unsigned long idx, std::string d); // 设置编号为idx的商品的描述为d

    LinkedList getAllCommodities(); // 获取购物车中所有商品

    double getTotalPrice(); // 获取当前购物车中所有商品的总价

    void clear(); // 清空购物车

    std::string toString(); // 获取购物车的string描述

    void loadShoppingCart(); // 从carts.txt中导入当前user对应的购物车信息
};
```



```c++
class Simulator : public QMainWindow {
Q_OBJECT

public:
    explicit Simulator(QWidget *parent = nullptr); // 默认构造函数

    ~Simulator() override; // 析构函数

private slots:

    void productPurchase(); // 商品购买的界面

    void authentication(); // 身份验证的界面

    void maskDetection(); // 口罩检测的界面

    void deal(); // 商品结算的界面

    ShoppingCart searchShoppingCart(User us); // 搜索用户为us的购物车

    void updateUser(); // 更新users.txt

    void updateShoppingCart(); // 更新carts.txt

    void updateRecord(); // 更新records.txt

    void updateCommodity(); // 更新commodities.txt

    void purchaseRecord(); // 购买记录的界面

    void closeRecord(); // 关闭购买记录界面

    void margoManagement(); // 进出货管理界面

    void closeMargoManagement(); // 关闭进出货管理界面

    void addMargo(); // 添加货物

    void removeMargo(); // 移除货物

    void helpMargo(); // 帮助界面

public slots:
    void setCurrentUser(User us); // 设置currentUser

    void setShoppingCart(ShoppingCart cart); // 设置shoppingCart

    void setMask(bool m); // 设置口罩检测是否通过


private:
    Ui::Simulator *ui;
    User currentUser; // 当前用户
    ShoppingCart shoppingCart; // 当前用户对应的购物车
    bool mask; // 是否佩戴口罩
    QWidget* recordWidget; // 购买记录控件
    QListWidget* recordListWidget; // 购买记录列表控件
    QPushButton* recordButton; // 返回控件
    QWidget* manageWidget; // 进出货管理控件
    QLineEdit* picPathPrompt; // 商品图片路径输入栏
    QLineEdit* namePrompt; // 商品名称输入栏
    QLineEdit* pricePrompt; // 商品价格输入栏
    QLineEdit* numberPrompt; // 商品数量输入栏
    QLineEdit* descriptionPrompt; // 商品描述输入栏
    QPushButton* manageAddButton; // 商品添加按钮
    QPushButton* manageCloseButton; // 界面关闭按钮
    QPushButton* manageSubButton; // 商品移除按钮
    QPushButton* manageHelpButton; // 帮助按钮
    bool DEBUG = true; // 如果是debug模式的话，不用口罩检测和人脸识别
};
```



```c++
class Supermarket {
private:
    CommodityShelf commodityShelf; // 商品货架
    std::vector<User> users; // 用户列表
    ShoppingCart cart = ShoppingCart(User()); // 购物车
    User currentUser; // 当前用户
  
    int chineseCharToNumber(char a, char b, char c); // 中文字符转int类型

    std::string numberToChineseChar(int num); // int转中文字符

    std::set<int> chineseCharIntersection(std::string a, std::string b); // 求两个中文字符串的交集

    std::set<int> chineseCharUnion(std::string a, std::string b); // 求两个中文字符串的并集

    static bool cmp(std::pair<Commodity, double> a, std::pair<Commodity, double> b); // 定义商品排序规则

public:
    Supermarket(); // 无参构造函数

    explicit Supermarket(CommodityShelf cs); // 带参构造函数
 
    Commodity getCommodity(unsigned long idx); // 获取编号为idx的商品

    Commodity getCommodityByIndex(int index); // 通过索引获取商品

    Commodity getCartCommodity(unsigned long idx); // 获取编号为idx的购物车中商品

    void addCommodity(Commodity c); // 添加商品

    bool addCartCommodity(Commodity c); // 往购物车添加商品

    void removeCommodityById(unsigned long idx); // 移除编号为idx的商品

    void removeCartCommodityById(unsigned long idx); // 移除购物车中编号为idx的商品

    void modifyCommodityNumber(unsigned long idx, int num); // 修改编号为idx的商品的数量

    bool modifyCartCommodityNumber(unsigned long idx, int num); // 修改购物车中编号为idx的商品的数量

    double getPrice(unsigned long idx); // 获取编号为idx的商品的价格

    double getCartPrice(unsigned long idx); // 获取购物车中编号为idx的商品的价格

    std::string getName(unsigned long idx); // 获取编号为idx的商品名称

    std::string getCartName(unsigned long idx); // 获取购物车中编号为idx的商品的名称

    int getNumber(unsigned long idx); // 获取编号为idx的商品的数量

    int getCartNumber(unsigned long idx); // 获取购物车中编号为idx的商品的数量

    std::string getDescription(unsigned long idx); // 获取编号为idx的商品的描述

    std::string getCartDescription(unsigned long idx); // 获取购物车中编号为idx的商品的描述

    std::string toString(); // 获取类的string描述

    void setPrice(unsigned long idx, double p); // 设置编号为idx的商品的价格为p

    void setNumber(unsigned long idx, int num); // 设置编号为idx的商品的数量为num

    void setCartNumber(unsigned long idx, int num); // 设置购物车中编号为idx的商品的数量为num

    void setDescription(unsigned long idx, std::string d); // 设置编号为idx的商品的描述为d

    LinkedList searchCommodity(std::string query, double threshold); // 搜索商品名称与query相似度不低于threshold的商品

    std::vector<User> getUsers(); // 获取users.txt中所有user

    void saveUsers(); // 保存所有user到users.txt中

    void addUser(User user); // 添加新的user

    void clearUsers(); // 清空users

    void clearCommodities(); // 清空所有商品

    std::vector<User> readUsers(); // 读取users.txt中所有用户

    double calculateSimilarity(std::string a, std::string b); // 计算字符串a和b的相似度

    std::vector<Commodity> readCommodities(); // 读取commodities.txt中所有的商品

    void saveCommodities(); // 保存商品到commodities.txt中

    void saveAll(); // 保存所有信息

    void clearAll(); // 清空所有信息

    User getUser(unsigned int idx); // 获取编号为idx的用户

    void loadAll(); // 导入所有信息

    ShoppingCart getCart(); // 获取购物车

    CommodityShelf getCommodityShelf(); // 获取货物架

    // 以下为超市的功能函数

    void login(); // 登录

    void logout(); // 登出

    bool checkMask(); // 检测是否佩戴口罩
};
```



```c++
class Tester {
public:
    bool assertTrueString(std::string a, std::string b); // 判断两个字符串是否相等

    bool assertTrueUserType(UserType a, UserType b); // 判断两个用户类型是否相等

    bool assertTrueDouble(double a, double b); // 判断两个浮点数是否相等

    bool assertTrueInt(int a, int b); // 判断两个整型是否相等

    bool testReadUsers(); // 测试读取用户信息

    bool testAddUser(); // 测试添加用户

    bool testClearAllUsers(); // 测试清空所有用户

    bool testGetUser(); // 测试获取用户

    bool testSaveUsers(); // 测试保存用户

    bool runAllTest(); // 运行所有测试
};
```



```c++
class UseCase {
public:
    static Supermarket case1(); // 测试用例1

    static Supermarket case2(); // 测试用例2
};
```



```c++
enum UserType { // 用户类别，管理员和普通用户
    Administrator = 0, GeneralUser = 1
};
```



```c++
class User {
private:
    std::string name; // 用户姓名
    UserType userType; // 用户类型
    double balance; // 余额
    unsigned int idx; // 用户编号

public:
    User(); // 无参构造函数

    explicit User(std::string nm); // 带参构造函数1

    User(std::string nm, UserType ut); // 带参构造函数2

    User(std::string nm, UserType ut, double b); // 带参构造函数3

    std::string getName(); // 获取用户姓名

    UserType getUserType(); // 获取用户类型

    void setBalance(double b); // 设置用户余额

    double getBalance(); // 获取用户余额

    std::string toString(); // 获取用户的string描述

    unsigned int getId(); // 获取用户的编号
};
```

